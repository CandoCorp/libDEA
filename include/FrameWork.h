#ifndef     FRAMEWORK_H
#define	FRAMEWORK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <complex.h>
//Constantes numericas o de cadena de caracteres fijas
/*
 * Opens the file
*/
    
#define APPEND "a+"
#define READ "r"
#define WRITE "w"
#define WRITE_UPDATE "w+"
#define READ_UPDATE "r+"
#define APPEND_UPDATE "a+"
#define MAX_BUFF 50000
#define MIN_BUFF 20

//Funciones de "Cast" para tipos de datos basicos
#define STRING_CAST(void) ((char*)void)
#define INT_PTR_CAST(void) ((int*)void)
#define CHAR_CAST(void) ((char)void)
#define INT_CAST(void) ((int)void)
#define FLOAT_CAST(void) ((float)void)
#define INT_PTR(int) (INT_POINTER_CAST(integerNew(int)))
#define CHAR_TO_INT_PTR(char) (INT_POINTER_CAST(integerNew(atoi(char))))
#define INT_CONVERT_TO_STRING(int) (ItoStr(int,10))


//Funciones para simplificar la asignacion de memoria dinamica
#define STRING_NEW_MAX() (STRING_CAST(malloc(sizeof(char)*MAX_BUFF)))
#define STRING_NEW_MIN() (STRING_CAST(malloc(sizeof(char)*MIN_BUFF)))
#define NEW(type) ((type*)malloc(sizeof(type)))
#define NEW_ARRAY(type,num_elem) (malloc(sizeof(type)*num_elem))
#define TRY {
    
typedef enum Estado_Retorno{ 
	ERROR=-1, EXITO=1 
}Estado_Retorno;

typedef enum CmpEstate{ LESS=-1, EQUAL, GREATER }CmpEstate;

inline void* New(void *type){
    if(type != NULL)
        ;
}


#ifdef	__cplusplus
}
#endif

#endif	/* _LIST_H */
