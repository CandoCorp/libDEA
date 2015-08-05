#include "exceptions.h"

typedef struct __UserDefException{
    int code;
    char name[30];
}UserDefException;

typedef struct __UserExceptionList{
    UserDefException Exception;
    struct __UserExceptionList *next;
}UserExceptionList;

UserExceptionList *UserExceptions;

const char *tempstrings[] = {     "NullPointer","ArrayStore","IllegalArgument",
                                "NegativeArraySize","ArrayIndexOutOfBounds","ArithmeticException",
                                "NoFileFound","IllegalAccess","Instantiation",
                                "ClassNotFound","ClassNotSupported","IndexOutOfBounds"
                                };

volatile int lastcodeUsed = LastException;

volatile int __exc_block_pass;

/* Flag to be set by ON? */
volatile int __exc_handled;

/* For indexing every call to TRY. */
volatile unsigned __exc_tries;

/* These identify the thrown exception.  File, function, line and
   the exception itself. */
char *__exc_file;
char *__exc_function;
unsigned __exc_line;
__EXC_TYPE __exc_code;

/* Stack is actually a linked list of catcher cells. */
struct __exc_stack
{
  unsigned num;
  jmp_buf j;
  struct __exc_stack *prev;
};

/* This is the global stack of catchers. */
struct __exc_stack *__exc_global;



#ifdef __EXC_DEBUG

/* Prints error message. */
void
__exc_debug (char *fmt, ...)
{
  va_list ap;

  fprintf (__EXC_STREAM, "__EXC: ");
  va_start (ap, fmt);
  vfprintf (__EXC_STREAM, fmt, ap);
  va_end (ap);
  fprintf (__EXC_STREAM, "\n");
}



/* For printing __exc_global. */
void
__exc_print_global ()
{
  struct __exc_stack *level = __exc_global;
  unsigned items;

  if (level == NULL)
    {
      fprintf (__EXC_STREAM, "Stack empty\n");
      return;
    }

  fprintf (__EXC_STREAM, "Current stack (from bottom to top):\n");
  for (items = 0; level; level = level->prev)
    {
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

#endif



/* Prints information about exception.  Called in debug mode, or when
   no handler is found. */

void
__exc_print (FILE *stream, char *file, char *function, unsigned line,
	     __EXC_TYPE code)
{
  fprintf (stream, "Exception in file \"%s\", at line %u",
	   file, line);
  if (function)
    {
      fprintf (stream, ", in function \"%s\"", function);
    }
  fprintf (stream, ".");

#ifdef __EXC_PRINT
  fprintf (stream, " Exception: ");
  __EXC_PRINT (code, stream);
#endif
  fprintf (stream, "\n");
}



/* Pop exception from stack, putting into J (if nonzero).  If stack is
   empty, print error message and exit.  Used in EXCEPT. */
void
__exc_pop (jmp_buf *j)
{
  struct __exc_stack *stored = __exc_global;

  __exc_debug ("POP () to %p", j);

  if (stored == NULL)
    {
      __exc_debug ("Unhandled exception.");

      fprintf (stderr, "Unhandled exception:\n");
      __exc_print (stderr, __exc_file, __exc_function,
		   __exc_line, __exc_code);

      exit (3);
    }

  __exc_global = stored->prev;

  if (j)
    {
      /* This assumes that JMP_BUF is a structure etc. and can be
	 copied rawely.  This is true in GLIBC, as I know. */
      memcpy (j, &stored->j, sizeof (jmp_buf));
    }

  __exc_debug ("Popped");
  __exc_print_global ();

  /* While with MALLOC, free.  When using obstacks it is better not to
     free and hold up. */
  free (stored);
}



/* Push J onto the stack, with RETURNED as value from SETJMP.  Return
   nonzero, if RETURNED is 0.  If RETURNED is nonzero, returns 0.
   Used in TRY. */

int
__exc_push (jmp_buf *j, int returned)
{
  struct __exc_stack *new;

  __exc_debug ("PUSH (), %p, %d", j, returned);

  /* SETJMP returns 0 first time, nonzero from __EXC_THROW.
     Returning false-like value here (0) will enter the
     else branch (that is, EXCEPT.) */
  if (returned != 0)
    {
      __exc_debug ("Returning from THROW");
      return 0;
    }

  /* Since this didn't come from THROW, fine to increase counter. */
  ++__exc_tries;
  __exc_debug ("This is PUSH () number %u", __exc_tries);

  /* Using memcpy here is the best alternative. */
  new = malloc (sizeof (struct __exc_stack));
  memcpy (&new->j, j, sizeof (jmp_buf));
  new->num = __exc_tries;
  new->prev = __exc_global;
  __exc_global = new;

  __exc_print_global ();

  return 1;
}



/* Throw an exception in FILE at LINE, with code CODE.  Used in THROW. */

void
__exc_throw (char *file, char *function, unsigned line, __EXC_TYPE code)
{
  jmp_buf j;

  __exc_debug ("THROW ()");
#if defined __EXC_DEBUG
  __exc_print (__EXC_STREAM, file, function, line, code);
#endif

    addException(code);
  
  __exc_file = file;
  __exc_function = function;
  __exc_line = line;
  __exc_code = code;

  /* Pop for jumping. */
  __exc_pop (&j);
  
  __exc_debug ("Jumping to the handler");

  /* LONGJUMP to J with nonzero value. */
  longjmp (j, 1);
}

/* Throw it in upper level of catcher blocks. */

void
__exc_rethrow ()
{
  jmp_buf j;

  __exc_debug ("RETHROW ()");
#ifdef __EXC_DEBUG
  __exc_print (__EXC_STREAM, __exc_file, __exc_function,
	       __exc_line, __exc_code);
#endif

  __exc_pop (&j);
  longjmp (j, 1);
}



#ifdef __EXC_DEBUG
#  define __EXC_NDEBUG_UN(decl)         decl
#else
#  define __EXC_NDEBUG_UN(decl)         decl __attribute__((unused))
#endif

int
__exc_on (__EXC_NDEBUG_UN(char *file),
	  __EXC_NDEBUG_UN(char *function),
	  __EXC_NDEBUG_UN(unsigned line),
	  __EXC_TYPE code)
{
  /* It is impossible to jump to the end of EXCEPT block, nor it is
     possible to mix ELSE with IF, so use before-defined __EXC_HANDLED
     flag. 

     Actually, use of
      on (...) ...;
      else on (...) ...;

     Is possible, but don't force the *user* to care about it. */

  __exc_debug ("ON ()");
  __exc_debug ("Trying to handle in file \"%s\", at line %u", file, line);
#ifdef __EXC_DEBUG
  if (function)
    {
      __exc_debug ("In function \"%s\".", function);
    }
#endif

  if (__exc_handled == 1)
    {
      __exc_debug ("Exception already handled in this level, skip");
      return 0;
    }
    if(findException(code,NULL) != 0)    
        if (__EXC_EQ (code, __exc_code))
            {
              __exc_debug ("This handler FITS");

              __exc_handled = 1;
              return 1;
            }

  __exc_debug ("This handler DOESN'T FIT");

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
            __exc_debug("Exception Not Found!..");
        }
    }
    
    return NULL;
}

inline void addException(const char ExceptionName[]){
    UserExceptionList *temp = malloc(sizeof(UserExceptionList));
    
    if(findException(ExceptionName, NULL) == 0){
        temp->next = UserExceptions;
        temp->Exception.code = lastcodeUsed;
        strcpy(temp->Exception.name,ExceptionName);
        UserExceptions = temp;
        ++lastcodeUsed;
        __exc_debug("Exception added to the system\n");
    }
    else
        __exc_debug ("Exception already defined in the system\n");
    
}

inline int findException(const char ExceptionName[], struct __UserExceptionList *node){
    if(UserExceptions == NULL)
        return 0;
    
    int i = 1;
    
    if(ExceptionMatchingToCode(ExceptionName) == -1){
        for(UserExceptionList *it = UserExceptions; it != NULL; it = it->next, i++)
            if(strcmp(ExceptionName,it->Exception.name) == 0){
                if(node != NULL)
                    node = it;
                __exc_debug ("Exception found in the system add by the user\n");
                return i;
            }
    }
    else{
        __exc_debug ("Exception found in the default system\n");
        return 1;
    }
    
    __exc_debug ("Exception not found\n");
    return 0;
}

inline void removeException(const char ExceptionName[]){
    UserExceptionList *node = NULL, *it = NULL;
    int position = findException(ExceptionName,node);
    
    it = UserExceptions;
    if(position != 0){
        for(int i = 0; i < (position - 1); i++, it = it->next){
            if(it->next == node){
                break;
            }
        }
    
        it->next = node->next;
        node->next = NULL;
        free(node);
    }
    
}

inline int ExceptionMatchingToCode(const char string[]){
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
    UserExceptionList *node = NULL;
    int value = 0;
    
    for(UserExceptionList *it = UserExceptions; it != NULL; it = it->next, value++)
        if(strcmp(string,it->Exception.name) == 0){
            __exc_debug ("Exception %s was found %d in the system add by the user\n",string,value + lastcodeUsed);
            return value;
    }
    
    return 0;
}
