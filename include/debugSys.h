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

#include <errno.h>
#include "Exec.h"

#define __ERROR_MSG 0
#define __WARN_MSG 1
#define __INFO_MSG 2

    //enum { __ERROR_MSG = 0, __WARN_MSG, __INFO_MSG };

void __debug_on();
void __debug_off();

void __exc_debug (unsigned line,const char *actualFunction,const char *restrict fmt, ...);
void __exc_error();

int __set_default_log_stream(const char fileName[],int switchStream);
int __set_default_debug_print_stream(const char fileName[]);

const char *__get_default_error_stream();
const char *__get_default_info_stream();
const char *__get_default_warn_stream();
const char *__get_default_debug_print_stream();

void __log_msg(int, unsigned, const char *restrict, const char *restrict, const char *restrict, ...);

unsigned int __get_debug_flag();

void __debug_after_levels_start();
void __debug_after_levels_end(int sub_levels);

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) (__log_msg(__ERROR_MSG,__LINE__,__func__,__FILE__, M, ##__VA_ARGS__))

#define log_warn(M, ...) (__log_msg(__WARN_MSG,__LINE__,__func__,__FILE__, M, ##__VA_ARGS__))

#define log_info(M, ...) (__log_msg(__INFO_MSG,__LINE__,__func__,__FILE__, M, ##__VA_ARGS__))

#define debug_on() (__debug_on())

#define debug_off() (__debug_off())

#define __debug(M, ...) (__exc_debug(__LINE__,__func__,M, ##__VA_ARGS__))

#define __debug_empty(M, ...) 

#define debug(M,...) {if(get_debug_flag()) __debug(M,##__VA_ARGS__); else __debug_empty(M,##__VA_ARGS__);}

#define debug_all_levels __EXC_BLOCK(__set_debug_all_levels_on(),__set_debug_all_levels_off())

#define debug_if_all_levels(has_sub_levels) __EXC_BLOCK(__debug_after_levels_start(),__debug_after_levels_end(has_sub_levels))

#define set_default_error_stream(filename) (__set_default_log_stream(filename,__ERROR_MSG))

#define set_default_warning_stream(filename) (__set_default_log_stream(filename,__WARN_MSG))

#define set_default_information_stream(filename) (__set_default_log_stream(filename,__INFO_MSG))

#define set_default_debug_print_stream(filename) (__set_default_debug_print_stream(filename))

#define get_default_error_stream() (__get_default_error_stream())

#define get_default_info_stream() (__get_default_info_stream())

#define get_default_warn_stream() (__get_default_warn_stream())

#define get_default_debug_print_stream() (__get_default_debug_print_stream())

#define get_debug_flag() (__get_debug_flag())

#define get_debug_all_levels_flag() (__get_debug_all_levels_flag())

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUGSYS_H */

