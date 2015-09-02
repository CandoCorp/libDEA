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

#include "ErrorHandler.h"
    
#include <setjmp.h>
    
	
enum __Exception {
    NullPointer = 1,
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
    __LastException
};

typedef enum __Exception Exception;

/* For function name.  GCC includes things which expand to
   the name of current function's name.  */

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

/* All variables are declared volatile to force non-optimization. 
   They should also be declared as thread-local. */

/* Flag to be set by ON? */
extern volatile int __exc_handled;

/* Throw it in upper level of catcher blocks. */
extern void __exc_rethrow();

#ifdef _WIN32
/* Throw an exception in FILE at LINE, with code CODE.  Used in THROW. */
extern void __exc_throw (char *, char *, unsigned, __EXC_TYPE);

/* What a f...  Somewhy I can't get GCC's __attribute__ working here
to tell that FILE and LINE are unused in non-debuging mode. */

extern int __exc_on (char *, char *, unsigned, __EXC_TYPE);

extern void __exc_pop(jmp_buf *j);

#else
/* Throw an exception in FILE at LINE, with code CODE.  Used in THROW. */
extern __attribute__((noreturn)) void __exc_throw (char *, char *, unsigned, __EXC_TYPE);

/* What a f...  Somewhy I can't get GCC's __attribute__ working here
   to tell that FILE and LINE are unused in non-debuging mode. */

extern __attribute__ ((noreturn)) int __exc_on (char *, char *, unsigned, __EXC_TYPE);
#endif

/* Start catching. */

/* Obviously, there is no way to check if appropriate EXCEPT exists.
   Its non-exsistence won't do segfault etc.; program will simply do
   the thing after TRY, without any error handling.  Raising from
   there works. */

#define try                                 \
	jmp_buf __exc_j;						\
    int __exc_ret;							\
    __exc_ret = setjmp (__exc_j);		    \
	if (__exc_push (&__exc_j, __exc_ret)) \
		__EXC_END(__exc_pop (0))

#define throw(code)                       \
  __exc_throw_new (__FILE__, __func__,     \
	       __LINE__, (#code))

/* THROW in EXCEPT block won't go into itself, because corresping item
   from __EXC_GLOBAL was already popped. */

#define except									\
    else										\
    __EXC_BLOCK (	__exc_handled = 0,          \
					__exc_handled == 0 ? __exc_rethrow() : 0	)
                 /*if (__exc_handled == 0)  \
                     __exc_rethrow (); )*/

/* EXPECT is an alias for EXCEPT. */

#define expect		except

/* CATCH is an alias for EXCEPT. */

#define catch		except 

/* Try to handle an exception. */

#define on(code)                          \
  if (__exc_on (__FILE__, __func__,    \
		__LINE__, (#code)))

extern inline const char *exceptionString(Exception code);
extern inline Exception exceptionCode(const char string[]);
extern inline void addException(const char ExceptionName[]);
extern inline int findException(const char ExceptionName[]);
extern inline void removeException(const char ExceptionName[],int position);
extern inline int ExceptionMatchingCodeUserList(const char string[]);
extern inline int ExceptionMatchingDefault(const char string[]);

#ifdef	__cplusplus
}
#endif

#endif	/* EXCEPTIONS_H */

