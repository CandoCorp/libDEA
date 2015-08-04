/* 
 * File:   Const.h
 * Author: kevincando
 *
 * Created on July 15, 2015, 7:38 PM
 */

#ifndef CONST_H
#define	CONST_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef ISO646_H
    #include <iso646.h>
#endif

// String templates for better understanding of code    
#define APPEND "a+"
#define READ "r"
#define WRITE "w"
#define WRITE_UPDATE "w+"
#define READ_UPDATE "r+"
#define APPEND_UPDATE "a+"
//#define MAX_BUFF 50000
//#define MIN_BUFF 20

#define IS ==
#define IS_NOT !=
#define IS_LESS_THAT <
#define IS_GREATER_THAT >
#define IS_LESS_EQUAL_THAT <=
#define IS_GREATER_EQUAL_THAT >=
    
#define AND &&
#define OR ||
#define BIT_AND &
#define BIT_OR |
#define NOT !
#define NOT_EQ !=
#define XOR ^
#define XOR_EQ ^=
#define OR_EQ |=
#define AND_EQ &=
#define COMPL ~
    
#define elif else if
        
typedef enum _CmpState{ LESS=-1, EQUAL, GREATER }CmpState;

enum{ MAX_BUFF = 64000, MIN_BUFF = 20 };

enum{ EMPTY = 0, NOT_EMPTY = 1 };

#ifdef __cplusplus
}
#endif

#endif	/* CONST_H */

