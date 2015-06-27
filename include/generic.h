/**
   \mainpage TDA Generic \n Estructura de Datos 
   <br>
   Profesores: Angel Lopez, Daniel Ochoa, Marisol Villacres <br>
   <hr>
   \author Kevin Cando
   \author Johny Suarez
   \date Marzo-2015

*/

/**
* @file generic.h
* @brief Este archivo contiene la definicion del 
* TDA Generic que representa a cualquier tipo de dato. Una variable
* Generic puede ser asignada a cualquier tipo de puntero, se le
* puede recuperar su valor y modificar su valor con las funciones
* aqui especificadas.
*
* @author Kevin Cando
*
* @date 03/28/2015
*/
#ifndef     GENERIC_H
#define	GENERIC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>   
#include "FrameWork.h"

/** @defgroup hs TDA Generic
 * Estas definiciones y funciones componenen el TDA Generic
 * @{
 */
    
/**
* @brief Definicion del tipo de dato Generic, el cual permite crear variables a las cuales se les puede asignar cualquier tipo de dato.
*/
typedef void * Generic;

/**
* @brief Definicion de las funciones que pueden leer una linea de un archivo
 * y retornar un registro de algun TDA en forma de una variable Generica
*/
typedef Generic (*readfn)(FILE *F);

/**
* @brief Definicion de las funciones que dados dos genericos pueden
 * compararlos y retornar 0 si son iguales, 1 si el primero es mayor que el
 * segundo y -1 si el primero es menor que el segundo
*/
typedef CmpEstate (*cmpfn)(Generic, Generic);

/**
* @brief Definicion de las funciones que dado un generico pueden
 * imprimirlo
*/
typedef void (*printfn) (Generic);

typedef char* (*sprintfn) (const char *format,...);

typedef Generic (*getkeyfn) (Generic);

typedef int (*writefn)(FILE *pf, Generic g);

typedef Generic (*readSeekfn)(FILE *pf, fpos_t *g);

#ifndef
#define BUFFER_STRING_FILE "tmp.data" 
#endif

//Numeric Constants for better visualization of data
#define ACTUALIZAR "a+"
#define READ "r"
#define WRITE "w"
#define REWRITE "w+"
#define READ_AND_WRITE "r+"
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


#define SELECT(s, v1, v2)   ((s) ? (v1) : (v2))
#define IN ,
#define FOR_EACH(ini, cond, increment) (for(ini;cond;increment))


int equals(Generic a, Generic b);

int compareTo(Generic a, Generic b, cmpfn fn);

char *toString(const char* format, ...);

int StringWriteToFile(FILE *pf, Generic string);

Generic StringReadFromFile(FILE *pf);

Generic StringSeekReadFromFile(FILE *pf, fpos_t *pos);

int Fseek(FILE *pf, readSeekfn leerLinea, Generic id, cmpfn comp);

#ifdef	__cplusplus
}
#endif

#endif	/* GENERIC_H */

