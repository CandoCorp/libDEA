/* 
 * File:   exceptions.h
 * Author: kevincando
 *
 * Created on July 15, 2015, 12:18 PM
 */

#ifndef EXCEPTIONS_H
#define	EXCEPTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "generic.h"

#include <setjmp.h>
    
enum __Exception {
    NullPointer = 0,
    ArrayStore,
    IllegalArgument,        
    NegativeArraySize,
    ArrayIndexOutOfBounds,
    ArithmeticException,
    NoFileFound, 
    IllegalAccess,
    Instantiation,
    ClassNotFound,
    ClassNotSupported,
    IndexOutOfBounds,
    LastException
};


typedef enum __Exception Exception;

extern struct __UserExceptionList *UserExceptions;



#define __EXC_BLOCK(start, end)              \
  for (start, __exc_block_pass = 1;          \
       __exc_block_pass;                     \
       end, __exc_block_pass = 0)

/* Likewise, but START block is empty. */

#define __EXC_END(end)                       \
  for (__exc_block_pass = 1;                 \
       __exc_block_pass;                     \
       end, __exc_block_pass = 0)


/* For function name.  GCC includes things which expand to
   the name of current function's name.  */

#if (!defined (__GNUC__) || __GNUC__ < 2 || \
     __GNUC_MINOR__ < (defined (__cplusplus) ? 6 : 4))
   /* Otherwise stick to unknown. */
#  define __EXC_FUNCTION               (char *) 0
#else
#  define __EXC_FUNCTION	       __PRETTY_FUNCTION__
#endif



/* The exception value. */

/* You'll want to make local changes to these.  For example, to use
   your own exception structure. */

/* Exception is by default an int.  Anyway, it can be anything from
   string to some structure.

   Whatever the implementation you choose, type name should be
   defined as __EXC_TYPE.  The THROW (and ON) macro accepts as
   many arguments, s it is given, so your function may use all
   the power of argument passing.  Define your function's name
   as __EXC_MAKE. Exceptions are compared in ON macro.  You
   should define comparing function as __EXC_EQ.

   For example, if you'd like to use strings in place of numbers,
   use this snippet:

   1) #define __EXC_TYPE         char *
   2) #define __EXC_EQ(s1, s2)   (strcasecmp (s1, s2) == 0)
   3) #define __EXC_PRINT(e, stream) \
	         fprintf (stream, "%s", e)

*/

#ifndef __EXC_TYPE
#  define __EXC_TYPE               char * 

/* Include the default __EXC_PRINT. */
#  define __EXC_TYPE_DEFAULT
#endif

#ifndef __EXC_MAKE
#  define __EXC_MAKE(code...)      code
#endif

#ifndef __EXC_ON
#  define __EXC_ON                 __EXC_MAKE
#endif

#ifndef __EXC_EQ
#  define __EXC_EQ(c1, c2)         (strcmp((c1),(c2)) == 0)
#endif


/* Optional exception printer.  This is used for debugging purposes
   only.  Define yourself's one as __EXC_PRINT. Arguments are
   exception of type __EXC_TYPE and stream to print to. */

#if !defined (__EXC_PRINT) && defined (__EXC_TYPE_DEFAULT)
#  define __EXC_PRINT(e, stream)             \
     fprintf (stream, "%s", e)
#endif

/* All variables are declared volatile to force non-optimization. 
   They should also be declared as thread-local. */

/* This counter is used by __EXC_BLOCK.  It works well even if nested. */
extern volatile int __exc_block_pass;

/* Flag to be set by ON? */
extern volatile int __exc_handled;

/* For indexing every call to TRY. */
extern volatile unsigned __exc_tries;

/* These identify the thrown exception.  File, function, line and
   the exception itself. */
extern char *__exc_file;
extern char *__exc_function;
extern unsigned __exc_line;
extern __EXC_TYPE __exc_code;

/* This is the global stack of catchers. */
extern struct __exc_stack *__exc_global;


#define __EXC_DEBUG 1

/* Debugging of exceptions.  Nothing interesting for you.  (Just for me.) 
   Anyway, it generates many (really) messages telling what is going
   to happen.  I order to work with it successfully, you should define
   __EXC_PRINT (see above.)
*/
#ifdef __EXC_DEBUG
#  include <stdarg.h>
#  ifndef __EXC_STREAM
/* I often redirect debugging information to a file. */
#    define __EXC_STREAM                     stdout
#  endif

/* Prints error message. */
extern void __exc_debug(char *, ...);

/* For printing __exc_global. */
extern void __exc_print_global(void);

#else
#  define __exc_debug(args...)
#  define __exc_print_global()
#endif



/* Prints information about exception.  Called in debug mode, or when
   no handler is found. */
extern void __exc_print (FILE *, char *, char *,
			 unsigned, __EXC_TYPE);

/* Pop exception from stack, putting into J (if nonzero).  If stack is
   empty, print error message and exit.  Used in EXCEPT. */
extern void __exc_pop (jmp_buf *);



/* Push J onto the stack, with RETURNED as value from SETJMP.  Return
   nonzero, if RETURNED is 0.  If RETURNED is nonzero, returns 0.
   Used in TRY. */
extern int __exc_push (jmp_buf *, int);



/* Throw an exception in FILE at LINE, with code CODE.  Used in THROW. */
extern __attribute__((noreturn)) void __exc_throw (char *, char *, unsigned, __EXC_TYPE);

/* Throw it in upper level of catcher blocks. */
extern void __exc_rethrow ();



/* What a f...  Somewhy I can't get GCC's __attribute__ working here
   to tell that FILE and LINE are unused in non-debuging mode. */

/* TODO: define __attribute__ (foo) to do nothing if this is not GCC.
   (Check if GNUC is predefined.) */

extern int __exc_on (char *, char *, unsigned, __EXC_TYPE);



/* Start catching. */

/* Obviously, there is no way to check if appropriate EXCEPT exists.
   Its non-exsistence won't do segfault etc.; program will simply do
   the thing after TRY, without any error handling.  Raising from
   there works. */

#define try                                  \
  if (({jmp_buf __exc_j;                     \
        int __exc_ret;                       \
        __exc_ret = setjmp (__exc_j);        \
        __exc_push (&__exc_j, __exc_ret);})) \
    __EXC_END(__exc_pop (0))

#define throw(code...)                       \
  __exc_throw (__FILE__, __EXC_FUNCTION,     \
	       __LINE__, (#code))

/* THROW in EXCEPT block won't go into itself, because corresping item
   from __EXC_GLOBAL was already popped. */

#define except                               \
  else                                       \
    __EXC_BLOCK (__exc_handled = 0,          \
                 ({ if (__exc_handled == 0)  \
                     __exc_rethrow (); }))

/* EXPECT is an alias for EXCEPT. */

#define expect                         except

/* CATCH is an alias for EXCEPT. */

#define catch      except 

/* Try to handle an exception. */

#define on(code...)                          \
  if (__exc_on (__FILE__, __EXC_FUNCTION,    \
		__LINE__, (#code)))

extern inline const char *exceptionString(Exception code);
extern inline Exception exceptionCode(const char string[]);
extern inline void addException(const char ExceptionName[]);
extern inline int findException(const char ExceptionName[], struct __UserExceptionList *node);
extern inline void removeException(const char ExceptionName[]);
extern inline int ExceptionMatchingCodeUserList(const char string[]);
extern inline int ExceptionMatchingToCode(const char string[]);
            
#ifdef	__cplusplus
}
#endif

#endif	/* EXCEPTIONS_H */

