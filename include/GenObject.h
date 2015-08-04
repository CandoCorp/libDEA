/* 
 * File:   GenObject.h
 * Author: kevincando
 *
 * Created on July 25, 2015, 9:39 PM
 */

#ifndef GENOBJECT_H
#define	GENOBJECT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "generic.h"
    
#ifndef BUFFER_STRING_FILE
    #define BUFFER_STRING_FILE "tmp.data" 
#endif

typedef struct __GenericClass__{ 
    Generic data;
    int(*equals)(Generic self,Generic data);
    int (*compareTo)(Generic self,Generic data,cmpfn fn);
    char *(*toString)(Generic self, const char *format);
    int (*destroy)(Generic self);
    int (*init)(Generic self);
}GenObject;

int equals(Generic self, Generic b);

int compareTo(Generic self, Generic b, cmpfn fn);

char *toString(Generic self, const char* format);

int destroy(Generic self);

int init(Generic self);



int StringWriteToFile(FILE *pf, Generic string);

Generic StringReadFromFile(FILE *pf);

Generic StringSeekReadFromFile(FILE *pf, fpos_t *pos);

int Fseek(FILE *pf, readSeekfn leerLinea, Generic id, cmpfn comp);

#ifdef	__cplusplus
}
#endif

#endif	/* GENOBJECT_H */

