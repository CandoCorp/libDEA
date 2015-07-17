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

#include "character.h"
    
enum _Exception {
    NullPointer = 0,
    ArrayStore,
    IllegalArgument,        
    NegativeArraySize,
    ArrayIndexOutOfBounds,
    ArithmeticException        
};

typedef _Exception Exception;

static int *user_defined_exceptions = NULL;

typedef void *(_gen_method) (void*,...);

typedef void (_gen_procedure)(void*,...);


inline void Try(Exception e,...){
    
}

inline void Catch(Exception e,void (*catch_method) (void*,...)){
    
}

#ifdef	__cplusplus
}
#endif

#endif	/* EXCEPTIONS_H */

