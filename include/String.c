#include "String.h"

struct _StringStruct{
    long long unsigned int len;
    unsigned char content[];
};

typedef _StringStruct StringStruct;

String stringNew(){
    String str = NEW(StringStruct);
    
}

String stringNew(const char *format,...);

String stringNew(char cont[]);

String stringNew(const char *cont);

String stringNew(String string);

void stringCpy(String dest, const String src);

void stringCpy(String dest, const String src, int );