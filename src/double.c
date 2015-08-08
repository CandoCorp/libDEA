#include "double.h"

/**
* @file double.c
*
* @author Johnny Suárez
*
* @date 03/28/2015
*/


Double doubleNew( double value ){
    Double g ;
    *(double *) g = value;
    return g;
}
//Double doubleNew( char *value )

int doubleCompare( Double x, Double y ){
    return 1;
}

float doubleFloatValue( Double g ){
    return (float)doubleGet(g);
}

double doubleGet( Double g ){
    return *(double *)g;
}

int doubleHashCode( Double g ){
    
}

int doubleIntValue( Double g ){
    return (int)doubleGet(g);
}

void doubleSet( Double g, double value ){
    *(double *)g = value;
}

char * doubleToString( Double g ){

}

int doubleCompMax( Double a, Double b ){
    return 1;
}

int doubleCompMin( Double a, Double b ){
    return 1;
}

void doublePrint( Double *g ){
    printf(" %f ", doubleGet(g));
}

int doubleValueOfMax( Double a, Double b ){
    
}

int doubleValueOfMin( Double a, Double b ){
    
}

int cmpDouble( Generic a, Generic b ){
    return ( doubleGet(a) == doubleGet(b) ) ? 0 : ( doubleGet(a) > doubleGet(b) ) ? 1 : -1;
}

int cmpMax( Generic a, Generic b ){
    return ( doubleGet(b) > doubleGet(a) ) ? 1 : 0;
}

int cmpMin( Generic a, Generic b ){
    return ( doubleGet(b) < doubleGet(a) ) ? 1 : 0;;
}
