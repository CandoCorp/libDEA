/**
* @file integer.h
*
* @author Johnny Suárez
*
* @date 03/26/2015
*/

#ifndef INTEGER_H
#define	INTEGER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/**
* integerNew permite crear un nuevo Generic y asignarle
* como valor un entero
* @author Johnny Suárez
* @param value el valor a ser asignado en el Generic
* @return retorna un nuevo int en forma de Generic
* @date 03/26/2015
*/
Generic integerNew( int value );
//Generic integerNew( char *value );

/**
* integerCompare permite comparar dos Generic con sus valores enteros,
* retornando 0 si son iguales, 1 si el primero es mayor que el
* segundo y -1 si el primero es menor que el segundo.
* @author Johnny Suárez
* @param x primera variable Generic que se desea comparar
* @param y segunda variable Generic que se desea comparar
* @return  el valor entero (0, 1, -1), resultado de la comparación
* @date 03/26/2015
*/
int integerCompare( Generic x, Generic y );

/**
* integerDoubleValue retorna el valor del Generic como un double
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor como double
* @return  el valor double del Generic
* @date 03/26/2015
*/
double integerDoubleValue( Generic g );

/**
* integerFloatValue retorna el valor del Generic como un float
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor como float
* @return  el valor float del Generic
* @date 03/26/2015
*/
float integerFloatValue( Generic g );

/**
* integerGet retorna el valor int del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor int
* @return  el valor int
* @date 03/26/2015
*/
int integerGet( Generic g );
//int integerValue( Generic g );

/**
*PENDIENTE: VER CUAL ES LA DIFERENCIA CON integerValue

* integerHashCode retorna un hash code representando al Generic,
* hash code es simplemente el valor del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su hash code
* @return  el hash code del Generic
* @date 03/26/2015
*/
//int integerHashCode( Generic g );

/**
* integerSet permite asignar un valor int a un Generic
* @author Johnny Suárez
* @param g Generic que tendrá el valor del int enviado
* @param value el valor que se va a asignar al Generic
* @date 03/26/2015
*/
void integerSet( Generic g, int value );

/**
* integerToString convierte el valor del Generic a un string
* @author Johnny Suárez
* @param g Generic que se desea convertir a string
* @return  la representación del valor del Generic como string
* @date 03/26/2015
*/
char * integerToString( Generic g );

int integerCompareMax( Generic a, Generic b );
int integerCompareMin( Generic a, Generic b );
    
#ifdef	__cplusplus
}
#endif

#endif	/* INTEGER_H */

