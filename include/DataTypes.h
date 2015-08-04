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

enum __DataTypes{
    INT = 0,
    CHAR,
    FLOAT,
    DOUBLE,
    LONG,
    STRING,
    COMPLEX,
    FRACTION
};

typedef enum __DataTypes DataTypes;

#ifdef	__cplusplus
}
#endif

#endif	/* DATATYPES_H */

