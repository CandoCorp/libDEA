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

#define NEW(type) ((type*)new_generic(sizeof(type)))
#define NEW_ARRAY(type,num_elem) (new_generic(sizeof(type)*num_elem))

#define MALLOC(type) ((type *)malloc(sizeof(type)))
#define MALLOC_ARRAY(type,num_elem) (type *)malloc((num_elem)*sizeof(type))
    
#define MALLOC_FLEX(type,num_elem,etype) ((type*)malloc(sizeof(type) + (num_elem) * sizeof(etype))
     

inline void destroy(void *ptr){
    
}

typedef char Word[MAX_WORD_SIZE];

struct _address{
    int id;
    Word addr;
};

typedef struct _address address; 

typedef address Table[MAX_SIZE_REF_ALLOW_BLOCK] ;

static Table ref_table;

Table *ref_table_act = ref_table;

int is_ref_Empty(address *a){
    if(strlen(a->addr) IS EMPTY)
        return EMPTY;
    return NOT_EMPTY;
}

void add_ref(void *p, int type){
    static int counter;
    static char buffer[MAX_WORD_SIZE] = "";
    
    if(counter > MAX_SIZE_REF_ALLOW_BLOCK){
        static Table new_table;
        ref_table_act = &new_table[0];
    }
    
    snprintf(buffer,sizeof(buffer),"%p",p);
    is_ref_Empty(&ref_table_act[counter]);
    strcpy(ref_table_act[counter]->addr,buffer);
    ref_table_act[counter]->id = type;
    
    ++counter;
}

int find_ref(void *ptr){
    int pos = -1;
    char buffer[MAX_WORD_SIZE] = "";
    
    snprintf(buffer,sizeof(buffer),"%p",ptr);
    
    for(int i = 0; i < MAX_SIZE_REF_ALLOW_BLOCK; i++){
        char *temp;
        address *tmp = &ref_table_act[i];
        temp = tmp->addr;
        if(strcmp(temp,buffer) IS EQUAL)
            pos = i;
    }
        
    return pos;
}


void remove_ref (void *ptr){
    int count = find_ref(ptr);
    
    if(count IS -1 )
        return ;
    
    
}

inline void *new_malloc(size_t value, int type){
    if(value IS 0 || value IS_LESS_THAT 0)
        return NULL;
    
    void *ptr = malloc(value);
    
    if(ptr != NULL)
        add_ref(ptr, type);
        
    return NULL;
}

#ifdef	__cplusplus
}
#endif

#endif	/* MEMMANAGMENT_H */

