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

#define NEW(type) ((type*)new_malloc(sizeof(type),#type))
#define DELETE(x) (Delete(x,#x))

#define NEW_ARRAY(type,num_elem) (new_malloc(sizeof(type)*num_elem,#type))
#define NEW_FLEX(type,num_elem,etype) ((type*)new_malloc(sizeof(type) + (num_elem) * sizeof(etype)),#type)

extern inline void *new_malloc(size_t value, char *type);

extern inline void Delete(void *ptr,char *objName);

extern inline void *new_calloc(size_t numElem, size_t size, char *type);

#ifdef	__cplusplus
}
#endif

#endif	/* MEMMANAGMENT_H */

