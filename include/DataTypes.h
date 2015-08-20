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
	
#include "Const.h"

static enum __DataTypes{
    BOOL = 0,
    CHAR,
    UNSIGNED_CHAR,
    SIGNED_CHAR,
    UNSIGNED_SHORT_INT,
    SHORT_INT,
    INT,
    UNSIGNED_INT,
    LONG_INT,
    UNSIGNED_LONG_INT,
    LONG_LONG_INT,
    UNSIGNED_LONG_LONG_INT,
    FLOAT,
    DOUBLE,
    LONG_DOUBLE,
    STRING,
    COMPLEX,
    FRACTION,
    __LAST_DATA_TYPE
};

typedef enum __DataTypes DataTypes;

static const char *restrict DataTypesNames[] = {"bool","char","unsigned char","signed char",
                                "unsigned short int","short int","int","unsigned int",
                                "long int","unsigned long int","long long int","unsigned long long int",
                                "float","double","long double","string","complex",
                                "fraction"};

extern inline int dataTypeCode(const char *restrict name);
const char *restrict dataTypeCodeToString(unsigned int code);

#ifdef	__cplusplus
}
#endif

#endif	/* DATATYPES_H */

