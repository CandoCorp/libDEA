#include "debugSys.h"
#include <stdarg.h>

volatile int debug_flag;
/* Prints error message. */
void __exc_debug (const char *fmt, ...){
  va_list ap;

  fprintf (__EXC_STREAM, "[Debug]: ");
  va_start (ap, fmt);
  vfprintf (__EXC_STREAM, fmt, ap);
  va_end (ap);
  fprintf (__EXC_STREAM, "\n");
}


void __debug_on(){
    debug_flag = 1;
}

void __debug_off(){
    debug_flag = 0;
}