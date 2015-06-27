/**
   \mainpage TDA Generic \n Estructura de Datos 
   <br>
   Profesores: Angel Lopez, Daniel Ochoa, Marisol Villacres <br>
   <hr>
   \author Marisol Villacres
   \author Daniel Ochoa
   \author Angel Lopez
   \date Octubre-2011

   <br><img src="../imagenes/paneta.jpg"><br>
*/

/**
* @file generic.h
* @brief Este archivo contiene la definicion del 
* TDA Generic que representa a cualquier tipo de dato. Una variable
* Generic puede ser asignada a cualquier tipo de puntero, se le
* puede recuperar su valor y modificar su valor con las funciones
* aqui especificadas.
*
* @author Marcelo Loor
* @author Marisol Villacres
* @author Veronica Macias
*
* @date 27/06/2015
*/
#ifndef GENERIC_H
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
typedef int (*cmpfn)(Generic, Generic);

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


typedef enum Estado_Retorno{ 
	ERROR=-1, EXITO=1 
}Estado_Retorno;

typedef enum CmpEstate{ MENOR=-1, IGUALES, MAYOR }CmpEstate;

typedef enum Boolean { FALSE, TRUE }Boolean;

typedef int (*writefn)(FILE *pf, Generic g);
typedef Generic (*readSeekfn)(FILE *pf, fpos_t *g);

int StringWriteToFile(FILE *pf, Generic string);

Generic StringReadFromFile(FILE *pf);

Generic StringSeekReadFromFile(FILE *pf, fpos_t *pos);

int Fseek(FILE *pf, readSeekfn leerLinea, Generic id, cmpfn comp);

char *ItoStr(int num, int radix);

//char *toString(sprintf fn, ...);

/**
* integerNew permite crear un nuevo entero, asignarle un valor y retornarlo listo
* para almacenarlo en una variable de tipo Generic.
* @author Marisol Villacres
* @param newValue el valor a ser asignado en el nuevo entero
* @return retorna un nuevo entero en forma de Generic
* @date 10/26/2011
*/

/**
* integerNew permite crear un nuevo entero, asignarle un valor y retornarlo listo
* para almacenarlo en una variable de tipo Generic.
* @author Marisol Villacres
* @param newValue el valor a ser asignado en el nuevo entero
* @return retorna un nuevo entero en forma de Generic
* @date 10/26/2011
*/
Generic integerNew(int newValue);


/**
* integerSet permite asignar un valor entero a una variable de tipo Generic.
* @author Marisol Villacres
* @param g la variable generica cuyo valor se desea modificar
* @param newValue el valor que se va a asignar a la variable g
* @date 10/26/2011
*/
void integerSet(Generic g, int newValue);

/**
* integerGet permite recuperar el valor entero almacenado en una variable Generic.
* @author Marisol Villacres
* @param g la variable Generic
* @return  el valor entero almacenado dentro de un Generic
* @date 10/26/2011
*/
int integerGet(Generic g);


void integerPrint(Generic *g);

int integerCmp(Generic a, Generic b);

int integerMax(Generic a, Generic b);
int integerMin(Generic a, Generic b);

/**
* charNew permite crear un nuevo char, asignarle un valor y retornarlo listo
* para almacenarlo en una variable de tipo Generic.
* @author Marisol Villacres
* @param newValue el valor a ser asignado en el nuevo entero
* @return retorna un nuevo char en forma de Generic
* @date 10/26/2011
*/
Generic charNew(char newValue);

/**
* charSet permite asignar un valor char a una variable de tipo Generic.
* @author Marisol Villacres
* @param g la variable generica cuyo valor se desea modificar
* @param newValue el valor que se va a asignar a la variable g
* @date 10/26/2011
*/

void charSet(Generic g, char newValue);

/**
* charGet permite recuperar el valor char almacenado en una variable Generic.
* @author Marisol Villacres
* @param g la variable Generic
* @return  el valor char almacenado dentro de un Generic
* @date 10/26/2011
*/
char charGet(Generic g);

void charPrint(Generic *g);

int charCmp(Generic a, Generic b);
/** @}
 */

#ifdef	__cplusplus
}
#endif

#endif	/* GENERIC_H */

