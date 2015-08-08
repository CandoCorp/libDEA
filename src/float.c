#include "float.h"

/**
* @file float.c
*
* @author Johnny Suárez
*
* @date 03/28/2015
*/


Float floatNew( float value ){
    Float g ;
    *(float *) g = value;
    return g;
}
//Float floatNew( double *value );
//Float floatNew( char *value );

int floatCompare( Float x, Float y ){
    return 1;
}

double floatDoubleValue( Float g ){
    return (double)floatGet(g);
}

float floatGet( Float g ){
    return *(float *)g;
}

int floatHashCode( Float g ){
    
}

int floatIntValue( Float g ){
    return (int)floatGet(g);
}

void floatSet( Float g, float value ){
    *(float *)g = value;
}

char * floatToString( Float g ){

}

int floatCompMax( Float a, Float b ){
    return 1;
}

int floatCompMin( Float a, Float b ){
    return 1;
}

void floatPrint( Float *g ){
    printf(" %f ", floatGet(g));
}

float floatValueOfMax( Float a, Float b ){
    
}

float floatValueOfMin( Float a, Float b ){
    
}



int cmpFloat( Generic a, Generic b ){
    return ( floatGet(a) == floatGet(b) ) ? 0 : ( floatGet(a) > floatGet(b) ) ? 1 : -1;
}

int cmpMax( Generic a, Generic b ){
    return ( floatGet(b) > floatGet(a) ) ? 1 : 0;
}

int cmpMin( Generic a, Generic b ){
    return ( floatGet(b) < floatGet(a) ) ? 1 : 0;;
}