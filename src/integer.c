
#include "generic.h"
#include "integer.h"

/**
* @file integer.c
*
* @author Johnny Suárez
*
* @date 03/27/2015
*/

//#define INT_SIZE_STRING ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)

Generic integerNew( int value ){
    Generic g = malloc( sizeof(int) );
    *(int *) g = value;
    return g;
}
//Generic integerNew( char *value );

int integerCompare( Generic x, Generic y ){
    return ( integerGet(x) == integerGet(y) ) ? 0 : ( integerGet(x) > integerGet(y) ) ? 1 : -1;
/*
    if(integerGet(x) == integerGet(y)) return 0;
    else if(integerGet(x) > integerGet(y)) return 1;
    return -1;
*/
}

double integerDoubleValue( Generic g ){
    return (double)integerGet(g);
}

float integerFloatValue( Generic g ){
    return (float)integerGet(g);
}

int integerGet( Generic g ){
    return *(int *)g;
}
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

void integerSet( Generic g, int value ){
    *(int *)g = value;
}

char * integerToString( Generic g ){
    char  buf[BUFSIZ]; //Falta definir el verdadero tamaño del char
    int check;
    int num = integerGet(g);
    check = snprintf(buf, sizeof(buf), "%d", num);
    if(check == -1) //Error
        check; //Hacer algo
    return buf;
}

int integerCompareMax( Generic a, Generic b ){
    
}

int integerCompareMin( Generic a, Generic b ){
    
}
