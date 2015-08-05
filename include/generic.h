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
#ifndef GENERIC_H
#define	GENERIC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <complex.h>
#include "Const.h"
#include "ErrorHandler.h"
#include "MemHandlers.h"
    
/** @defgroup hs TDA Generic
 * Estas definiciones y funciones componenen el TDA Generic
 * @{
 */
    
/**
* @brief Definicion del tipo de dato Generic, el cual permite crear variables a las cuales se les puede asignar cualquier tipo de dato.
*/
typedef void *Generic;
    

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
typedef CmpState (*cmpfn)(Generic, Generic);

/**
* @brief Definicion de las funciones que dado un generico pueden
 * imprimirlo
*/
typedef void (*printfn) (Generic);

typedef char* (*sprintfn) (char const *buffer, Generic);

typedef Generic (*getkeyfn) (Generic);

typedef int (*writefn)(FILE *pf, Generic g);

typedef Generic (*readSeekfn)(FILE *pf, fpos_t *g);

typedef void (*Gen_method) (Generic data, ...);

typedef void *(*Gen_function) (Generic data,...);

#ifdef	__cplusplus
}
#endif

#endif	/* GENERIC_H */

