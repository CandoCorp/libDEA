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
#include "MemManagement.h"
    
#ifndef BUFFER_STRING_FILE
    #define BUFFER_STRING_FILE "tmp.data" 
#endif

typedef struct __GenericClass__{ 
    Generic data;
    int dataType;
    int(*equals)(GenObject self,GenObject data);
    int (*compareTo)(Generic self,Generic data);
    char *(*toString)(Generic self, const char *format);
    int (*destroy)(Generic self);
    int (*init)(Generic self);
}GenObject;

int equals(GenObject self, GenObject that);

int compareTo(Generic self, Generic b);

char *toString(GenObject self, const char* format);

int GenObject_destroy(Generic self);

int init(GenObject self);

void *GenObject_new(size_t size,GenObject proto);

int StringWriteToFile(FILE *pf, Generic string);

Generic StringReadFromFile(FILE *pf);

Generic StringSeekReadFromFile(FILE *pf, fpos_t *pos);

int Fseek(FILE *pf, readSeekfn leerLinea, Generic id, cmpfn comp);

#ifdef	__cplusplus
}
#endif

#endif	/* GENOBJECT_H */

