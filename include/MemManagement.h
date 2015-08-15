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

#include <stdio.h>
#include "debugSys.h"
    
enum { MAX_SIZE_REF_ALLOW_BLOCK = 1000, MAX_WORD_SIZE = 15 };

#define NEW(type) ((type*)__new_malloc(sizeof(type),#type))
#define DELETE(x) (__delete(x,#x))

#define NEW_ARRAY(type,num_elem) ((type*)__new_calloc(num_elem,sizeof(type),#type))
#define NEW_FLEX(type,num_elem,etype) ((type*)__new_calloc(sizeof(type) + (num_elem) * sizeof(etype)),#type)

void *__new_malloc(size_t value, char *type);

void __delete(void *ptr,char *objName);

void *__new_calloc(size_t numElem, size_t size, char *type);

void *__new_realloc(void *ptr, size_t numElem,size_t size, char *type);

#ifdef	__cplusplus
}
#endif

#endif	/* MEMMANAGMENT_H */

