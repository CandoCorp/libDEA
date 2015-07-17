
#include "character.h"

/**
* @file integer.c
*
* @author Johnny Suárez
*
* @date 03/27/2015
*/

Character charNew( char value ){
    Character g = NEW(char);
    *(char *)g = value;
    return g;
}

int characterCompare( Character x, Character y ){
    return compareTo( x, y, cmpChar );
/*
    if(charGet(a) == charGet(b)) return 0;
    else if(charGet(a) > charGet(b)) return 1;
    return -1;
*/
}

int cmpChar( Generic a, Generic b ){
    ( characterGet(a) == characterGet(b) ) ? 0 : ( characterGet(a) > characterGet(b) ) ? 1 : -1;
}

char characterGet( Character g ){
    return *(char *)g;
}

int characterHashCode( Character g ){
    char buf = characterGet(g);
    return (int)buf;
}

void characterSet( Character g, char value ){
    *(char *)g = value;
}

char * characterToString( Character g ){
    char *buf = malloc(2);
    buf[0] = characterGet(g);
    buf[1] = '\0';
    return buf;
}

void characterPrint(Generic *g){
    printf("%c", characterGet(g));
}