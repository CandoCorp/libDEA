/* 
 * File:   DataTypes.h
 * Author: kevin
 *
 * Created on August 4, 2015, 5:20 PM
 */

#ifndef DATATYPES_H
#define	DATATYPES_H

#include "debugSys.h"


#ifdef	__cplusplus
extern "C" {
#endif

static enum __DataTypes{
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

static char *DataTypesNames[] = {"int","bool","char","float"
                                "double","long","string","complex",
                                "fraction"};

extern inline int dataTypeCode(const char name[]);

#ifdef	__cplusplus
}
#endif

#endif	/* DATATYPES_H */

