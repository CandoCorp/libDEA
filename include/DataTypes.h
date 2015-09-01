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

extern inline int dataTypeCode(const char *restrict name);
const char  *restrict dataTypeCodeToString(unsigned int code);

#ifdef	__cplusplus
}
#endif

#endif	/* DATATYPES_H */

