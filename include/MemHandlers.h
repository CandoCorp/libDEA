/* 
 * File:   MemHandlers.h
 * Author: kevin
 *
 * Created on August 5, 2015, 2:39 PM
 */

#ifndef MEMHANDLERS_H
#define	MEMHANDLERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
    
#define MALLOC(type) ((type *)malloc(sizeof(type)))
#define MALLOC_ARRAY(type,num_elem) (type *)malloc((num_elem)*sizeof(type))
    
#define MALLOC_FLEX(type,num_elem,etype) ((type*)malloc(sizeof(type) + (num_elem) * sizeof(etype))

#define CALLOC(number,type) ((type*)calloc(number,sizeof(type)))

#define REALLOC_ARRAY(pointer, number, type) ((type*)realloc(pointer, (number)*sizeof(type)))
#define REALLOC_FLEX(pointer, stype, number, etype) ((stype*)realloc(pointer, sizeof(stype) + (number)*sizeof(etype))

#ifdef	__cplusplus
}
#endif

#endif	/* MEMHANDLERS_H */

