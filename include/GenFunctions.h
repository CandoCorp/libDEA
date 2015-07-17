/* 
 * File:   GenFunctions.h
 * Author: kevincando
 *
 * Created on July 17, 2015, 1:38 PM
 */

#ifndef GENFUNCTIONS_H
#define	GENFUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

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

typedef char* (*sprintfn) (const char *format,...);

typedef Generic (*getkeyfn) (Generic);

typedef int (*writefn)(FILE *pf, Generic g);

typedef Generic (*readSeekfn)(FILE *pf, fpos_t *g);

#ifndef
    #define BUFFER_STRING_FILE "tmp.data" 
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* GENFUNCTIONS_H */

