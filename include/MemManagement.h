/* 
 * File:   MemManagment.h
 * Author: kevincando
 *
 * Created on July 15, 2015, 7:36 PM
 */

#ifndef MEMMANAGEMENT_H
#define	MEMMANAGEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef CONST_H
    #include "Const.h"
#endif

#include <stdlib.h>
#include <stdio.h>

enum { MAX_SIZE_REF_ALLOW_BLOCK = 1000, MAX_WORD_SIZE = 15 };

#define NEW(type) ((type*)new_malloc(sizeof(type),atoi(#type)))
#define DESTROY(x) (destroy(x))

#define NEW_ARRAY(type,num_elem) (new_malloc(sizeof(type)*num_elem))
#define NEW_FLEX(type,num_elem,etype) ((type*)new_malloc(sizeof(type) + (num_elem) * sizeof(etype))

#define MALLOC(type) ((type *)malloc(sizeof(type)))
#define MALLOC_ARRAY(type,num_elem) (type *)malloc((num_elem)*sizeof(type))
    
#define MALLOC_FLEX(type,num_elem,etype) ((type*)malloc(sizeof(type) + (num_elem) * sizeof(etype))

#define CALLOC(number,type) ((type*)calloc(number,sizeof(type)))

#define REALLOC_ARRAY(pointer, number, type) ((type*)realloc(pointer, (number)*sizeof(type)))
#define REALLOC_FLEX(pointer, stype, number, etype) ((stype*)realloc(pointer, sizeof(stype) + (number)*sizeof(etype))

inline void *new_malloc(size_t value, int type){
    void add_ref(void *p, int type);
    if(value IS 0)
        return NULL;
    
    void *ptr = malloc(value);
    
    if(ptr != NULL){
        add_ref(ptr, type);
        return ptr;
    }
    
    return NULL;
}

inline void destroy(void *ptr){
    void remove_ref (void *ptr);
    remove_ref(ptr);
}

inline void *new_calloc(size_t numElem, size_t size, int type){
    void add_ref(void *p,int type);
    
    if(numElem IS 0 OR size IS 0)
        return NULL;
    
    void *ptr = CALLOC(numElem,size);
    
    if(ptr IS_NOT NULL){
        add_ref(ptr,type);
        return ptr;
    }
        
    return NULL;
}

#ifdef	__cplusplus
}
#endif

#endif	/* MEMMANAGMENT_H */

