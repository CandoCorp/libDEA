
#include "integer.h"

/**
* @file integer.c
*
* @author Johnny Suárez
*
* @date 03/27/2015
*/

//#define INT_SIZE_STRING ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)
GenObject IntegerProto = {
    .toString = integerToString(Integer g);
    .init ;
}

Integer integerNew( int value ){
    Integer g = NEW(int);
    *(int *) g = value;
    return g;
}
//Generic integerNew( char *value );

int integerCompare( Integer x, Integer y ){
    return compareTo( x, y, cmpInt );
/*
    if(integerGet(x) == integerGet(y)) return 0;
    else if(integerGet(x) > integerGet(y)) return 1;
    return -1;
*/
}

double integerDoubleValue( Integer g ){
    return (double)integerGet(g);
}

float integerFloatValue( Integer g ){
    return (float)integerGet(g);
}

int integerGet( Integer g ){
    return *(int *)g;
}

//PENDIENTE: VER CUAL ES LA DIFERENCIA CON integerValue
int integerHashCode( Generic g ){
    
}

void integerSet( Integer g, int value ){
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

int integerCmpMax( Integer x, Integer y ){
    return compareTo( x, y, cmpMax );
}

int integerCmpMin( Generic x, Generic y ){
    return compareTo( x, y, cmpMin );
}

int integerValueOfMax( Integer a, Integer b ){
    
}

int integerValueOfMin( Integer a, Integer b ){
    
}

void integerPrint( Integer *g ){
    printf(" %d ", integerGet(g));
}





int cmpInt( Generic a, Generic b ){
    return ( integerGet(a) == integerGet(b) ) ? 0 : ( integerGet(a) > integerGet(b) ) ? 1 : -1;
}

int cmpMax( Generic a, Generic b ){
    return ( integerGet(b) > integerGet(a) ) ? 1 : 0;
}

int cmpMin( Generic a, Generic b ){
    return ( integerGet(b) < integerGet(a) ) ? 1 : 0;;
}