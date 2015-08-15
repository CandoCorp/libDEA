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
    char str3[20], **strStr;
    
    debug_on();
    
    set_default_error_stream("log.txt");
    set_default_debug_print_stream("stdout.txt");
    set_default_information_stream("inf.txt");
    set_default_warning_stream("warn.txt");
    
    debug_off();
    
    char *const str2 = NEW_ARRAY(char,20);
    
    printf("%d\n",(int)(sizeof(str3)/sizeof(str3[0])));
    printf("%d\n",(int)(sizeof(*str2)));
    printf("%d\n",(int)(sizeof(str2[2])));
    
    for(int i = 0; i<(sizeof(str1)/sizeof(str1[0]));i++)
        printf("%c",i[str1]);
    
    /**
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
    */
    return (EXIT_SUCCESS);
}

