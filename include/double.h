/**
* @file double.h
*
* @author Johnny Suárez
*
* @date 03/28/2015
*/

#ifndef DOUBLE_H
#define	DOUBLE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "generic.h"

typedef Generic Double;

/**
* doubleNew permite crear un nuevo Generic y asignarle
* como valor un double
* @author Johnny Suárez
* @param value el valor a ser asignado en el Generic
* @return retorna un nuevo double en forma de Generic
* @date 03/26/2015
*/
Double doubleNew( double value );
//Double doubleNew( char *value );

/**
* doubleCompare permite comparar dos Generic con sus valores double,
* retornando 0 si son iguales, 1 si el primero es mayor que el
* segundo y -1 si el primero es menor que el segundo.
* @author Johnny Suárez
* @param x primera variable Generic que se desea comparar
* @param y segunda variable Generic que se desea comparar
* @return  el valor entero (0, 1, -1), resultado de la comparación
* @date 03/26/2015
*/
int doubleCompare( Double x, Double y );


/**
* doubleFloatValue retorna el valor del Generic como un float
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor como float
* @return  el valor float del Generic
* @date 03/26/2015
*/
float doubleFloatValue( Double g );

/**
* doubleGet retorna el valor double del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor double
* @return  el valor double
* @date 03/26/2015
*/
double doubleGet( Double g );

/**
* doubleHashCode retorna un hash code representando al Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su hash code
* @return  el hash code del Generic
* @date 03/26/2015
*/
int doubleHashCode( Double g );

/**
* doubleIntValue retorna el valor int del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor int
* @return  el valor int
* @date 03/26/2015
*/
int doubleIntValue( Double g );

/**
* doubleSet permite asignar un valor double a un Generic
* @author Johnny Suárez
* @param g Generic que tendrá el valor del double enviado
* @param value el valor que se va a asignar al Generic
* @date 03/26/2015
*/
void doubleSet( Double g, double value );

/**
* doubleToString convierte el valor del Generic a un string
* @author Johnny Suárez
* @param g Generic que se desea convertir a string
* @return  la representación del valor del Generic como string
* @date 03/26/2015
*/
char * doubleToString( Double g );

int doubleCompMax( Double a, Double b );
int doubleCompMin( Double a, Double b );

int doubleValueOfMax( Double a, Double b );
int doubleValueOfMin( Double a, Double b );

void doublePrint( Double *g );

#ifdef	__cplusplus
}
#endif

#endif	/* DOUBLE_H */

