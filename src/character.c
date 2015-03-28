
#include "generic.h"
#include "character.h"

/**
* @file integer.c
*
* @author Johnny Suárez
*
* @date 03/27/2015
*/

Generic charNew( char value ){
    Generic g = malloc( sizeof(char) );
    *(char *)g = value;
    return g;
}

int characterCompare( Generic x, Generic y ){
    return ( integerGet(x) == integerGet(y) ) ? 0 : ( integerGet(x) > integerGet(y) ) ? 1 : -1;
/*
    if(charGet(a) == charGet(b)) return 0;
    else if(charGet(a) > charGet(b)) return 1;
    return -1;
*/
}

char characterGet( Generic g ){
    return *(char *)g;
}

int characterHashCode( Generic g ){
    char buf = charGet(g);
    return (int)buf;
}

void characterSet( Generic g, char value ){
    *(char *)g = value;
}

char * characterToString( Generic g ){
    char *buf = malloc(2);;
    buf[0] = charGet(g);
    buf[1] = '\0';
    return buf;
}