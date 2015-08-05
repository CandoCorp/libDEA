/* 
 * File:   DataTypes.h
 * Author: kevin
 *
 * Created on August 4, 2015, 5:20 PM
 */

#ifndef DATATYPES_H
#define	DATATYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "generic.h"
    
enum __DataTypes{
    INT = 0,
    BOOL,
    CHAR,
    FLOAT,
    DOUBLE,
    LONG,
    STRING,
    COMPLEX,
    FRACTION,
    __LAST_DATA_TYPE
};

typedef enum __DataTypes DataTypes;

static volatile int counter;

static struct __CustomDataType{
    char *name;
    int id;
    struct __CustomDataType *next;
};

static struct __CustomDataType *dataTypeList;

inline int dataTypeCode(char name[]){
    if(name IS NULL)
        return -2;
    
    if(strcmp(name,"int") IS EQUAL)
        return INT;
    if(strcmp(name,"bool") IS EQUAL)
        return INT;
    if(strcmp(name,"char") IS EQUAL)
        return CHAR;
    if(strcmp(name,"float") IS EQUAL)
        return FLOAT;
    if(strcmp(name,"double") IS EQUAL)
        return DOUBLE;
    if(strcmp(name,"long") IS EQUAL)
        return LONG;
    if(strcmp(name,"string") IS EQUAL)
        return STRING;
    if(strcmp(name,"complex") IS EQUAL)
        return COMPLEX;
    if(strcmp(name,"fraction") IS EQUAL)
        return FRACTION;
}

static int dataTypeCodeCustom(char name[]){
    struct __CustomDataType *it;
    
    if(dataTypeList IS NULL)
        return -2;
    
    for(struct __CustomDataType *it = dataTypeList; it!=NULL; it = it->next){
        if(strcmp(name,it->name) IS EQUAL)
            return it->id;
    }
    
    return -1;
}

static int dataType_Add(char name[]){
    struct __CustomDataType *it = MALLOC(struct __CustomDataType);
    
    if(name IS NULL){
        free(it);
        return -2;
    }
    if(it IS NULL){
        return -1;
    }
    switch(dataTypeCodeCustom(name)){
        case -2:{
            
        }break;
        case -1:{
            
        }break;
        default:{
            printf("Already found in the system\n");
        }
    }
    if(dataTypeList IS NULL){
        it->id = __LAST_DATA_TYPE;
        it->name = strdupa(name);
        it->next = dataTypeList;
        dataTypeList = it;
        ++counter;
    }else{
        int i = 0;
        for(struct __CustomDataType *node = dataTypeList; node IS_NOT NULL AND i IS_LESS_THAT counter; node = node->next,i++){
            if(node->next IS NULL){
                it->id = __LAST_DATA_TYPE;
                it->name = strdupa(name);
                it->next = NULL;
                node->next = it;
                ++counter;
                return 0;
            }
        }
    }
    
    return 1;
}

#ifdef	__cplusplus
}
#endif

#endif	/* DATATYPES_H */

