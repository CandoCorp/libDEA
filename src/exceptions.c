#include "exceptions.h"
#include <stdio.h>

typedef struct __UserDefException{
    int code;
    char name[30];
}UserDefException;

typedef struct __UserExceptionList{
    UserDefException Exception;
    struct __UserExceptionList *next;
}UserExceptionList;

static UserExceptionList *__UserExceptions;

static const char *tempstrings[] = {	"NullPointer","ArrayStore","IllegalArgument",
										"NegativeArraySize","ArrayIndexOutOfBounds","ArithmeticException",
										"NoFileFound","IllegalAccess","Instantiation",
										"ClassNotFound","ClassNotSupported","IndexOutOfBounds"
									};

static volatile int lastcodeUsed = __LastException;

/* Flag to be set by ON? */
volatile int __exc_handled;

/* For indexing every call to TRY. */
volatile unsigned __exc_tries;

/* These identify the thrown exception.  File, function, line and
   the exception itself. */
static char *__exc_file;
static char *__exc_function;
static unsigned __exc_line;
static __EXC_TYPE __exc_code;

/* Stack is actually a linked list of catcher cells. */
struct __exc_stack
{
  unsigned num;
  jmp_buf j;
  struct __exc_stack *prev;
};

/* This is the global stack of catchers. */
static struct __exc_stack *__exc_global;

#ifdef __EXC_DEBUG
    void __exc_print_global(void);

    /* For printing __exc_global. */
    void
    __exc_print_global (){
        struct __exc_stack *level = __exc_global;
        unsigned items;

        if (level == NULL){
          fprintf (__EXC_STREAM, "Stack empty\n");
          return;
        }

        fprintf (__EXC_STREAM, "Current stack (from bottom to top):\n");
        for (items = 0; level; level = level->prev){
          fprintf (__EXC_STREAM, "%c ", items == 0 ? '[' : ' ');

          /* FIXME: does printing jmp_buf literally (as we now address and
             its size) good?  No, unless human understands it.  One
             can't unless he chooses one popular C library and study the
             implementation carefully;) */
          fprintf (__EXC_STREAM, "%u", level->num);
          /* TODO: newline every four or so items.  Use tab stops. */
          fprintf (__EXC_STREAM, " %c\n", level->prev ? ' ' : ']');  
          items++;
        }

      fprintf (__EXC_STREAM, "Totally %u items.\n", items);
    }
#else
    #define __exc_print_global()
#endif
	
void
__exc_print(FILE *stream, char *file, char *function, unsigned line,
__EXC_TYPE code)
{
	fprintf(stream, "Exception in file \"%s\", at line %u",
		file, line);
	if (function){
		fprintf(stream, ", in function \"%s\"", function);
	}
	fprintf(stream, ".");

#ifdef __EXC_PRINT
	fprintf(stream, " Exception: ");
	__EXC_PRINT(code, stream);
#endif
	fprintf(stream, "\n");
}

/* Pop exception from stack, putting into J (if nonzero).  If stack is
   empty, print error message and exit.  Used in EXCEPT. */
void
__exc_pop (jmp_buf *j){
    struct __exc_stack *stored = __exc_global;

    debug ("Pop () to %p", j);

    if (stored == NULL)
    {
        debug ("Unhandled exception.");

        fprintf (stderr, "Unhandled exception:\n");
        __exc_print (stderr, __exc_file, __exc_function,
                     __exc_line, __exc_code);

        exit (3);
		//return;
    }

    __exc_global = stored->prev;

    if (j){
		/* This assumes that JMP_BUF is a structure etc. and can be
		copied rawely.  This is true in GLIBC, as I know. */
		memcpy (j, &stored->j, sizeof (jmp_buf));
    }

    debug ("Popped");
    __exc_print_global ();

    /* While with MALLOC, free.  When using obstacks it is better not to
       free and hold up. */
    free (stored);
}

/* Push J onto the stack, with RETURNED as value from SETJMP.  Return
   nonzero, if RETURNED is 0.  If RETURNED is nonzero, returns 0.
   Used in TRY. 
*/

int
__exc_push (jmp_buf *j, int returned)
{
    struct __exc_stack *new;

    debug ("Push (), %p, %d", j, returned);

    /* SETJMP returns 0 first time, nonzero from __EXC_THROW.
       Returning false-like value here (0) will enter the
       else branch (that is, EXCEPT.) */
    
	if (returned != 0){
        debug ("Returning from THROW");
        return 0;
    }

    /* Since this didn't come from THROW, fine to increase counter. */
    ++__exc_tries;
    debug ("This is PUSH () number %u", __exc_tries);

    /* Using memcpy here is the best alternative. */
    new = malloc (sizeof (struct __exc_stack));
    check_mem(new);
    memcpy (&new->j, j, sizeof (jmp_buf));
    new->num = __exc_tries;
    new->prev = __exc_global;
    __exc_global = new;

    __exc_print_global ();
    return 1;

    error:
        return -1;
}

/* Throw an exception in FILE at LINE, with code CODE.  Used in THROW. */

void
__exc_throw (char *file, char *function, unsigned line, __EXC_TYPE code)
{
    jmp_buf j;

    debug ("Throw ()");

    int res = findException(code);
    
    if(res == -3){
        __exc_file = file;
        __exc_function = function;
        __exc_line = line;
        __exc_code = code;

        /* Pop for jumping. */
        __exc_pop (&j);

        debug ("Jumping to the handler");

        /* LONGJUMP to J with nonzero value. */
        longjmp (j, 1);
    }else if(res == 0){
        log_err("%s\n\t%s","The exception wasn't found by the system, you can use:","throw_new to add it to the system");
    }
}

void
__exc_throw_new (char *file, char *function, unsigned line, __EXC_TYPE code)
{
    jmp_buf j;

    debug ("Throw ()");

    addException(code);

    __exc_file = file;
    __exc_function = function;
    __exc_line = line;
    __exc_code = code;

    /* Pop for jumping. */
    __exc_pop (&j);

    debug ("Jumping to the handler");

    /* LONGJUMP to J with nonzero value. */
    longjmp (j, 1);
}

/* Throw it in upper level of catcher blocks. */

void
__exc_rethrow (){
    jmp_buf j;

    debug ("Rethrow ()");
    
    __exc_pop (&j);
    longjmp (j, 1);
}



#ifdef _WIN32
    #define __EXC_NDEBUG_UN(decl)         decl
#else
    #define __EXC_NDEBUG_UN(decl)         decl __attribute__((unused))
#endif

int
__exc_on (__EXC_NDEBUG_UN(char *file),
		  __EXC_NDEBUG_UN(char *function),
		  __EXC_NDEBUG_UN(unsigned line),
		  __EXC_TYPE code){
    
    debug ("On ()");
    debug ("Trying to handle in file \"%s\", at line %u", file, line);

#ifdef __EXC_DEBUG
    if (function)
      {
        debug ("In function \"%s\".", function);
      }
#endif

    if (__exc_handled == 1){
      debug ("Exception already handled in this level, skip");
      return 0;
    }

    int pos = findException(code);
    if(pos != 0)    
        if (__EXC_EQ (code, __exc_code)){
            
            debug ("This handler fits");

            removeException(code,pos);
            __exc_handled = 1;
            return 1;
        }

    debug ("This handler DOESN'T FIT");

    /* Not matched. */
    return 0;
}

inline const char *exceptionString(Exception code){
    switch(code){      
        case NullPointer:{
            return tempstrings[0];
        }break;
        case ArrayStore:{
            return tempstrings[1];
        }break;
        case IllegalArgument:{
            return tempstrings[2];
        }break;
        case NegativeArraySize:{
            return tempstrings[3];
        }break;
        case ArrayIndexOutOfBounds:{
            return tempstrings[4];
        }break;
        case ArithmeticException:{
            return tempstrings[5];
        }break;
        case  NoFileFound:{
            return tempstrings[6];
        }break; 
        case IllegalAccess:{
            return tempstrings[7];
        }break;
        case Instantiation:{
            return tempstrings[8];
        }break;
        case ClassNotFound:{
            return tempstrings[9];
        }break;
        case ClassNotSupported:{
            return tempstrings[10];
        }break;
        case IndexOutOfBounds:{
            return tempstrings[11];
        }break;
        default:{
            debug("Exception Not Found!..");
        }
    }
    
    return NULL;
}

inline void addException(const char ExceptionName[]){
    UserExceptionList *temp = malloc(sizeof(UserExceptionList));
    
    check_mem(temp);
    switch(findException(ExceptionName)){
        case -2:{
            debug("First exception being added to the system by the user");
            temp->next = __UserExceptions;
            temp->Exception.code = lastcodeUsed;
            strcpy(temp->Exception.name,ExceptionName);
            __UserExceptions = temp;
            ++lastcodeUsed;
            debug("Exception added to the system");
        }break;
        case -1:{
            debug("Bad Exception name");
        }break;
        case 0:{
            temp->next = NULL;
            temp->Exception.code = lastcodeUsed;
            strcpy(temp->Exception.name,ExceptionName);
            __UserExceptions->next = temp;
            ++lastcodeUsed;
            debug("Exception added to the system");
        }break;
        default:{
            debug ("Exception already defined in the system");
        }
    }
    
    error:{
        return ;
    }
}

inline int findException(const char ExceptionName[]){
    if(ExceptionName == NULL)
        return -1;
    
    if(__UserExceptions == NULL)
        return -2;
    
    if(ExceptionMatchingDefault(ExceptionName) == -1){
        int value = ExceptionMatchingCodeUserList(ExceptionName);
        if(	value != 0	)
            return value;
    }
    else{
        debug ("Exception found in the default system");
        return -3;
    }
    
    debug ("Exception not found");
    return 0;
}

inline void removeException(const char ExceptionName[], int position){
    UserExceptionList *node = NULL, *it = NULL;
    
    it = __UserExceptions;
    
    if(position < 0)
        return ;
    
    if(position != 0){
        int i = 0;
        while(i < position){
            i++;
            it = it->next;
        }
        debug("%s",it->Exception.name);
        if(it != NULL){
            node = it->next;
            debug("%s",node->Exception.name);
            if(node->next != NULL){
                it->next = node->next;
                debug("%s",it->next->Exception.name);
                node->next = NULL;
                free(node);
            }else{
                free(node);
            }
        }
    }
}

inline int ExceptionMatchingDefault(const char string[]){
	if(strcmp(string,tempstrings[0]) == 0)
        return NullPointer;
    
    if(strcmp(string,tempstrings[1]) == 0)
        return ArrayStore;
    
    if(strcmp(string,tempstrings[2]) == 0)
        return IllegalArgument;
    
    if(strcmp(string,tempstrings[3]) == 0)
        return NegativeArraySize;
    
    if(strcmp(string,tempstrings[4]) == 0)
        return ArrayIndexOutOfBounds;
    
    if(strcmp(string,tempstrings[5]) == 0)
        return ArithmeticException;
    
    if(strcmp(string,tempstrings[6]) == 0)
        return NoFileFound;
    
    if(strcmp(string,tempstrings[7]) == 0)
        return IllegalAccess;
    
    if(strcmp(string,tempstrings[8]) == 0)
        return Instantiation;
    
    if(strcmp(string,tempstrings[9]) == 0)
        return ClassNotFound;
    
    if(strcmp(string,tempstrings[10]) == 0)
        return ClassNotSupported;
    
    if(strcmp(string,tempstrings[11]) == 0)
        return IndexOutOfBounds;
    
    return -1;
}

inline int ExceptionMatchingCodeUserList(const char string[]){
    int value = 0;
    
    for(UserExceptionList *it = __UserExceptions; it != NULL; it = it->next, value++)
        if(strcmp(string,it->Exception.name) == 0){
            debug ("Exception %s was found %d in the system add by the user",string,value + __LastException);
            return value;
        }
    
    return 0;
}