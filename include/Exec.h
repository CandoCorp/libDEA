/* 
 * File:   Exec.h
 * Author: kevin
 *
 * Created on August 5, 2015, 8:06 PM
 */

#ifndef EXEC_H
#define	EXEC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Const.h"

volatile int __exc_block_pass;		

	/* This counter is used by __EXC_BLOCK.  It works well even if nested. */
	//static volatile int __exc_block_pass;
#define __EXC_START(start)		\
	for (start, __exc_block_pass = 1;		\
	__exc_block_pass;		\
	__exc_block_pass = 0)

#define __EXC_BLOCK(start, end)              \
	for (start, __exc_block_pass = 1;          \
       __exc_block_pass;                     \
       end, __exc_block_pass = 0)

/* Likewise, but START block is empty. */

#define __EXC_END(end)                       \
	for (__exc_block_pass = 1;                 \
       __exc_block_pass;                     \
       end, __exc_block_pass = 0)

#if (!defined (__GNUC__) || __GNUC__ < 2 || \
     __GNUC_MINOR__ < (defined (__cplusplus) ? 6 : 4))

    #define __EXC_FUNCTION               (char *) 0
#else
    #define __EXC_FUNCTION	       __PRETTY_FUNCTION__
#endif

#ifndef __EXC_TYPE
#  define __EXC_TYPE               char * 

#  define __EXC_TYPE_DEFAULT
#endif

#ifndef __EXC_MAKE
#  define __EXC_MAKE(code)      code
#endif

#ifndef __EXC_ON
#  define __EXC_ON                 __EXC_MAKE
#endif

#ifndef __EXC_EQ
#  define __EXC_EQ(c1, c2)         (strcmp((c1),(c2)) == 0)
#endif

#if !defined (__EXC_PRINT) && defined (__EXC_TYPE_DEFAULT)
#  define __EXC_PRINT(e, stream)             \
     fprintf (stream, "%s", e)
#endif

/**
void
__exc_print (FILE *stream, char *file, char *function, unsigned line,
	     __EXC_TYPE code)
{
    fprintf (stream, "Exception in file \"%s\", at line %u",
             file, line);
    if (function){
        fprintf (stream, ", in function \"%s\"", function);
    }
    fprintf (stream, ".");

#ifdef __EXC_PRINT
    fprintf (stream, " Exception: ");
    __EXC_PRINT (code, stream);
#endif
    fprintf (stream, "\n");
}
*/
    
#ifdef	__cplusplus
}
#endif

#endif	/* EXEC_H */

