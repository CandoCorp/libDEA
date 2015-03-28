/**
* @file character.h
*
* @author Johnny Suárez
*
* @date 03/27/2015
*/

#ifndef CHARACTER_H
#define	CHARACTER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/**
* charNew permite crear un nuevo Generic y asignarle
* como valor un char
* @author Johnny Suárez
* @param value el valor a ser asignado en el char
* @return retorna un nuevo char en forma de Generic
* @date 03/27/2015
*/
Generic charNew( char value );

/**
* characterCompare permite comparar dos Generic con sus valores char,
* retornando 0 si son iguales, 1 si el primero es mayor que el
* segundo y -1 si el primero es menor que el segundo.
* @author Johnny Suárez
* @param x primera variable Generic que se desea comparar
* @param y segunda variable Generic que se desea comparar
* @return  el valor entero (0, 1, -1), resultado de la comparación
* @date 03/27/2015
*/
int characterCompare( Generic x, Generic y );

/**
* characterGet retorna el valor char del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su valor char
* @return  el valor char
* @date 03/27/2015
*/
char characterGet( Generic g );

/**
* characterHashCode retorna un hash code representando al char del Generic
* @author Johnny Suárez
* @param g Generic que se desea obtener su hash code
* @return  el hash code que representa al caracter
* @date 03/27/2015
*/
int characterHashCode( Generic g );

/**
* characterSet permite asignar un valor int a un Generic
* @author Johnny Suárez
* @param g Generic que tendrá el valor del int enviado
* @param value el valor que se va a asignar al Generic
* @date 03/27/2015
*/
void characterSet( Generic g, char value );

/**
* characterToString convierte el valor del Generic a un string
* @author Johnny Suárez
* @param g Generic que se desea convertir a string
* @return  la representación del valor del Generic como string
* @date 03/27/2015
*/
char * characterToString( Generic g );

#ifdef	__cplusplus
}
#endif

#endif	/* CHARACTER_H */

