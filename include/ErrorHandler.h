/* 
 * File:   ErrorHandler.h
 * Author: kevincando
 *
 * Created on July 26, 2015, 6:24 PM
 */

#ifndef ERRORHANDLER_H
#define	ERRORHANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "debugSys.h"

#define check(A, M, ...) if(!(A)) { sentinel(M,##__VA_ARGS__) }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory. In:")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }
    
typedef enum { 
	ERROR=-1, SUCCESS = 0 
}Return_type;

void die(const char *message);

#ifdef	__cplusplus
}
#endif

#endif	/* ERRORHANDLER_H */

