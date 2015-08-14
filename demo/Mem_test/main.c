/* 
 * File:   main.c
 * Author: kevin
 *
 * Created on August 6, 2015, 12:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../../libDEA/include/MemManagement.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char str1[] = "This is a string for testing proposes";
    char *str2,*str3, **strStr;
    
    debug_on();
    
    set_default_error_stream("log.txt");
    set_default_print_stream("stdout.txt");
    set_default_information_stream("inf.txt");
    set_default_warning_stream("warn.txt");
    
    debug_off();
    
    strStr = NEW_ARRAY(char*,1024);
    str2 = NEW(char);
    
    DELETE(str2);
    DELETE(str1);
    
    for(int i = 3; i < 1000; i++){    
        strStr[i] = NEW(char);
    }
    
    for(int i = 3; i < 1000; i = i+2){
        DELETE(strStr[i]);
    }
    
    for(int i = 0; i < 500; i++){
        strStr[i] = NEW(char);
    }
    
    str3 = NEW(char);
    DELETE(str3);
    debug_off();
    
    return (EXIT_SUCCESS);
}

