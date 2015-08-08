/* 
 * File:   debugSys.h
 * Author: kevin
 *
 * Created on August 5, 2015, 3:17 PM
 */

#ifndef DEBUGSYS_H
#define	DEBUGSYS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <err.h>
#include "Exec.h"
        
#ifndef __EXC_STREAM

    #define __EXC_STREAM        stdout
    #define __EXC_ERROR         stderr 

#endif

extern volatile int debug_flag;

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(__EXC_ERROR, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(__EXC_ERROR, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(__EXC_ERROR, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)


#define debug_on() __debug_on()
#define debug_off() __debug_off()

#define debug(M,...) {if(debug_flag) __debug(M,##__VA_ARGS__); else __debug_empty(M,##__VA_ARGS__);}

void __debug_on();
void __debug_off();

void __exc_debug(const char *, ...);
void __exc_error();

#define __debug(M, ...) __exc_debug(M, ##__VA_ARGS__)
#define __debug_empty(M, ...) 

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUGSYS_H */

