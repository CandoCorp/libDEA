/* 
 * File:   String.h
 * Author: Kevin Cando
 *
 * Created on March 29, 2015, 11:41 AM
 */

#ifndef     STRING_H
#define	STRING_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <string.h>
#include "generic.h"
    
typedef Generic String;

typedef const Generic const_String;

String stringNew();

String stringNew(const char *format,...);

String stringNew(char cont[]);

String stringNew(const char *cont);

String stringNew(String string);

void stringCpy(String dest, const String src);

void stringCpy(String dest, const String src, int );

#ifdef	__cplusplus
}
#endif

#endif	/* STRING_H */

