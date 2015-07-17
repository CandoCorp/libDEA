#ifndef     FRAMEWORK_H
#define	FRAMEWORK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <complex.h>
    

    
#define SELECT(s, v1, v2)   ((s) ? (v1) : (v2))
#define IN ,
#define FOR_EACH(ini, cond, increment) (for(ini;cond;increment))

// Cast functions 
#define STRING_CAST(void) ((char*)void)
#define INT_PTR_CAST(void) ((int*)void)
#define CHAR_CAST(void) ((char)void)
#define INT_CAST(void) ((int)void)
#define FLOAT_CAST(void) ((float)void)
#define INT_CONVERT_TO_STRING(int) (ItoStr(int,10))

// Functions to simplify the memory allocation
#define STRING_NEW_MAX() (STRING_CAST(malloc(sizeof(char)*MAX_BUFF)))
#define STRING_NEW_MIN() (STRING_CAST(malloc(sizeof(char)*MIN_BUFF)))
#define TRY {
    



#ifdef	__cplusplus
}
#endif

#endif	/* _LIST_H */
