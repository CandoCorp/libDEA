/**
* @file float.h
*
* @author Johnny Suárez
*
* @date 03/28/2015
*/

#ifndef FLOAT_H
#define	FLOAT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "generic.h"

typedef Generic Float;

/**
* floatNew permite crear un nuevo Generic y asignarle
* como valor un float
* @author Johnny Suárez
* @param value el valor a ser asignado en el Generic
* @return retorna un nuevo float en forma de Generic
* @date 03/26/2015
*/
Float floatNew( float value );
//Float floatNew( double *value );
//Float floatNew( char *value );

/**
* floatCompare permite comparar dos Generic con sus valores float,
* retornando 0 si son iguales, 1 si el primero es mayor que el
* segundo y -1 si el primero es menor que el segundo.
* @author Johnny Suárez
* @param x primera variable Generic que se desea comparar
* @param y segunda variable Generic que se desea comparar
* @return  el valor entero (0, 1, -1), resultado de la comparación
* @date 03/26/2015
*/
int floatCompare( Float x, Float y );


/**
* floatDoubleValue retorna el valor del Generic como un double
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor como double
* @return  el valor double del Generic
* @date 03/26/2015
*/
double floatDoubleValue( Float g );

/**
* floatGet retorna el valor float del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor float
* @return  el valor float
* @date 03/26/2015
*/
float floatGet( Float g );

/**
* floatHashCode retorna un hash code representando al Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su hash code
* @return  el hash code del Generic
* @date 03/26/2015
*/
int floatHashCode( Float g );

/**
* floatIntValue retorna el valor int del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor int
* @return  el valor int
* @date 03/26/2015
*/
int floatIntValue( Float g );

/**
* floatSet permite asignar un valor float a un Generic
* @author Johnny Suárez
* @param g Generic que tendrá el valor del float enviado
* @param value el valor que se va a asignar al Generic
* @date 03/26/2015
*/
void floatSet( Float g, float value );

/**
* floatToString convierte el valor del Generic a un string
* @author Johnny Suárez
* @param g Generic que se desea convertir a string
* @return  la representación del valor del Generic como string
* @date 03/26/2015
*/
char * floatToString( Float g );

int floatCompMax( Float a, Float b );
int floatCompMin( Float a, Float b );

float floatValueOfMax( Float a, Float b );
float floatValueOfMin( Float a, Float b );

void floatPrint( Float *g );

#ifdef	__cplusplus
}
#endif

#endif	/* FLOAT_H */

