/* 
 * File:   StringTokenizer.h
 * Author: kevin
 *
 * Created on March 29, 2015, 11:40 AM
 */

#ifndef     STRINGTOKENIZER_H
#define	STRINGTOKENIZER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "String.h"

 struct _StringTokenizer {
     bool has_next;
     String next;
     String tokens[];
 };
   
typedef _StringTokenizer StringTokenizer ;


#ifdef	__cplusplus
}
#endif

#endif	/* STRINGTOKENIZER_H */

