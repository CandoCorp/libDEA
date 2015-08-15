#include "debugSys.h"
#include "MemHandlers.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <err.h>
#include <time.h>
#include <stdbool.h>

FILE *deferr = NULL;
FILE *defstream = NULL;
FILE *defwarn = NULL;
FILE *definfo = NULL;

static char file_name_error[FILENAME_MAX];
static char file_name_warn[FILENAME_MAX];
static char file_name_info[FILENAME_MAX];
static char file_name_stream[FILENAME_MAX];

volatile int debug_flag;

/* Prints error message. */
void __exc_debug (unsigned line,const char *actualFunction,const char *fmt, ...){
    va_list ap;

    volatile bool debug_macro = false;
    //unsigned line = line;
    //char *actualFunction = __func__;
    static char *lastFunction = NULL;
    
    va_start (ap, fmt);
    
    if(lastFunction == NULL)
        lastFunction = actualFunction;
                
    if(strcmp(actualFunction,lastFunction) == 0)
        debug_macro = true;
    
    if(!defstream){
        fflush(stdout);
        if(debug_macro){
            fprintf (stdout, "[Debug in function: %s]: \n",actualFunction);
            fprintf(stdout,"\t in line %u: \t",line);
            vfprintf (stdout, fmt, ap);
            fprintf (stdout, "\n");
        }else{
            fprintf(stdout,"\t in line %u: \t",line);
            vfprintf (stdout, fmt, ap);
            fprintf (stdout, "\n");
        }
        lastFunction = actualFunction;
    }else{
        if(debug_macro){
            fprintf (defstream, "[Debug in function: %s]: \n",actualFunction);
            fprintf(defstream,"\t in line %u: \t",line);
            vfprintf (defstream, fmt, ap);
            fprintf (defstream, "\n");
        }else{
            fprintf(defstream,"\t in line %u: \t",line);
            vfprintf (defstream, fmt, ap);
            fprintf (defstream, "\n");
        }
        lastFunction = actualFunction;
    }
    
    va_end (ap);
    
}

void __debug_on(){
    debug_flag = 1;
}

void __debug_off(){
    debug_flag = 0;
}

int __set_default_log_stream(const char fileName[],int switchStream){
    FILE *pf;
    FILE *fileStream;
    
    //time_t current_time = time(NULL);
    
    if( fileName == NULL ){
        debug("The fileName was Null");
        return -1;
    }
    /**
    if(current_time == ((time_t)-1)){
        debug("The current time couldn't be calculated");
        return -2;
    }
    */
    int len = strlen(fileName);
            
    switch(switchStream){
        case __ERROR_MSG:{
            if(strcmp(file_name_stream,fileName) == 0) goto error_stream_equal;
            if(strcmp(file_name_info,fileName) == 0) goto error_info_equal;
            if(strcmp(file_name_warn,fileName) == 0) goto error_warn_equal;
            fileStream = deferr;
            strncpy(file_name_error,fileName,len);
        }break;
        case __WARN_MSG:{
            if(strcmp(file_name_stream,fileName) == 0) goto error_stream_equal;
            if(strcmp(file_name_error,fileName) == 0) goto error_error_equal;
            if(strcmp(file_name_info,fileName) == 0) goto error_info_equal;
            fileStream = defwarn;
            strncpy(file_name_warn,fileName,len);
        }break;
        case __INFO_MSG:{
            if(strcmp(file_name_stream,fileName) == 0) goto error_stream_equal;
            if(strcmp(file_name_error,fileName) == 0) goto error_error_equal;
            if(strcmp(file_name_warn,fileName) == 0) goto error_warn_equal;
            fileStream = definfo;
            strncpy(file_name_info,fileName,len);
        }break;
        default:{
            goto error_switch_stream;
        }
    }
    
    if( len >= FILENAME_MAX){
        debug("The name for the file is more long than the permitted");
        return -3;
    }
    pf = fopen(fileName,"r");
    
    if( pf == NULL ){
        pf = fopen(fileName,"w");
        
        if( pf == NULL )
            goto error;
        
        debug("The file %s was created successfully",fileName);
        /**
        char *str_time = ctime(&current_time);
        
        if(str_time == NULL)
            goto error_time;
        else{
            
        str_time[strlen(str_time)-1] = '\0';
         */
        fprintf(pf,"[----------------------- Log started on: %s at %s -----------------------]\n",__DATE__,__TIME__);
        fileStream = pf;
        strncpy(file_name_error,fileName,len);
        return 0;
    }else{
        
        fclose(pf);
        pf = fopen(fileName,"a+");
        if( pf == NULL )
            goto error;
        
        debug("The file %s was opened successfully",fileName);
        
        /**
        char *str_time = ctime(&current_time);
        
        if(str_time == NULL)
            goto error_time;
        else{
         
        str_time[strlen(str_time)-1] = '\0';
        */
        fprintf(pf,"[----------------------- Log started on: %s at %s -----------------------]\n",__DATE__,__TIME__);
        fileStream = pf;
        strncpy(file_name_error,fileName,len);
        return 0;
    }
    error:{
        debug("The file couldn't be opened");
        return -4;
    }
    error_time:{
        debug("There was an error in getting the system's time ");
        return -5;
    }
    error_switch_stream:{
        debug("The selection code for the log switch was wrong");
        return -6;
    }
    error_stream_equal:{
        debug("The name of the defined information system is equal to the name proposed");
        return -7;
    }
     error_info_equal:{
        debug("The name of the defined information system is equal to the name proposed");
        return -8;
    }
    error_error_equal:{
        debug("The name of the defined error system is equal to the name proposed");
        return -9;
    }
    error_warn_equal:{
        debug("The name of the defined warning system is equal to the name proposed");
        return -10;
    }
}

int __set_default_debug_print_stream(const char fileName[]){
    FILE *pf;
    
    //time_t current_time = time(NULL);
    
    if( fileName == NULL ){
        debug("The fileName was Null");
        return -1;
    }
    /**
    if(current_time == ((time_t)-1)){
        debug("The current time couldn't be calculated");
        return -2;
    }
    */
    int len = strlen(fileName);
    
    if( len >= FILENAME_MAX){
        debug("The name for the file is more long than the permitted");
        return -3;
    }
    
    if(strcmp(file_name_info,fileName) == 0) goto error_info_equal;
    if(strcmp(file_name_error,fileName) == 0) goto error_error_equal;
    if(strcmp(file_name_warn,fileName) == 0) goto error_warn_equal;
            
    pf = fopen(fileName,"r");
    
    if( pf == NULL ){
        pf = fopen(fileName,"w");
        
        if( pf == NULL )
            goto error;
        
        debug("The file %s was created successfully",fileName);
        /**
        char *str_time = ctime(&current_time);
        
        if(str_time == NULL)
            goto error_time;
        else{
            str_time[strlen(str_time)-1] = '\0';
            */
        fprintf(pf,"[----------------------- Debug started on: %s at %s -----------------------]\n",__DATE__,__TIME__);
        defstream = pf;
        strncpy(file_name_error,fileName,len+1);
        return 0;
    }else{
        fclose(pf);
        pf = fopen(fileName,"a+");
        
        if( pf == NULL )
            goto error;
        
        debug("The file %s was opened successfully",fileName);
        /**
        char *str_time = ctime(&current_time);
        
        if(str_time == NULL)
            goto error_time;
        else{
            str_time[strlen(str_time)-1] = '\0';
           */
        fprintf(pf,"[----------------------- Debug started on: %s at %s -----------------------]\n",__DATE__,__TIME__);
        defstream = pf;
        strncpy(file_name_error,fileName,len);
        return 0;
    }
    error:{
        debug("The file couldn't be opened");
        return -4;
    }    
    error_time:{
        return -5;
    }
    error_info_equal:{
        debug("The name of the defined information system is equal to the name proposed");
        return -6;
    }
    error_error_equal:{
        debug("The name of the defined error system is equal to the name proposed");
        return -7;
    }
    error_warn_equal:{
        debug("The name of the defined warning system is equal to the name proposed");
        return -8;
    }
}

const char *__get_default_error_stream(){
    return file_name_error;
}

const char *__get_default_info_stream(){
    return file_name_info;
}

const char *__get_default_warn_stream(){
    return file_name_warn;
}

const char *__get_default_debug_print_stream(){
    return file_name_stream;
}

void __log_msg(int op_code,unsigned line,const char function[],const char file[], const char *format, ...){
    va_list ap;
    va_start (ap, format);
    fflush(stderr);
    switch(op_code){
        case 0:{
            if(!deferr){
                fprintf(stderr, "[Error in %s in function %s:%d: ErrNo.: %s]\n\t", file, function, line, clean_errno());
                vfprintf (stderr, format, ap);
                fprintf(stderr,"\n");
            }
            else{
                fprintf(deferr, "[Error in %s in function %s:%d: ErrNo.: %s]\n\t", file, function, line, clean_errno());
                vfprintf (deferr, format, ap);
                fprintf(deferr,"\n");
            }
        }break;
        case 1:{
            if(!defwarn){
                fprintf(stderr, "[Warn in %s in function %s:%d: ErrNo.: %s]\n\t", file, function, line, clean_errno());
                vfprintf (stderr, format, ap);
                fprintf(stderr,"\n");
            }
            else{
                fprintf(defwarn, "[Warn in %s in function %s:%d: ErrNo.: %s]\n\t", file, function, line, clean_errno());
                vfprintf (defwarn, format, ap);
                fprintf(defwarn,"\n");
            }
        }break;
        case 2:{
            if(!definfo){
                fprintf(stderr, "[Info in %s in function %s:%d) ErrNo.: %s]\n\t", file, function, line, clean_errno());
                vfprintf (stderr, format, ap);
                fprintf(stderr,"\n");
            }
            else{
                fprintf(definfo, "[Info in %s in function %s:%d) ErrNo.: %s]\n\t", file, function, line, clean_errno());
                vfprintf (definfo, format, ap);
                fprintf(definfo,"\n");
            }
        }break;
        default:{
            if(!deferr)
                fprintf(stderr, "There was an internal problem with the code");
            else
                fprintf(deferr, "There was an internal problem with the code");
        }
    }
    va_end (ap);
}

int __get_debug_flag(){
    return debug_flag;
}