#include <ctype.h>
#include "generic.h"

//Constantes numericas o de cadena de caracteres fijas
#define ACTUALIZAR "a+"
#define LEER "r"
#define ESCRIBIR "w"
#define SOBREESCRIBIR "w+"
#define LEER_Y_ESCRIBIR "r+"
#define MAX_BUFF 50000
#define MIN_BUFF 20

//Funciones de "Cast" para tipos de datos basicos
#define STRING_CAST(void) ((char*)void)
#define INT_PTR_CAST(void) ((int*)void)
#define CHAR_CAST(void) ((char)void)
#define INT_CAST(void) ((int)void)
#define FLOAT_CAST(void) ((float)void)
#define INT_PTR(int) (INT_POINTER_CAST(integerNew(int)))
#define CHAR_TO_INT_PTR(char) (INT_POINTER_CAST(integerNew(atoi(char))))
#define INT_CONVERT_TO_STRING(int) (ItoStr(int,10))

//Funciones para simplificar la asignacion de memoria dinamica
#define STRING_NEW_MAX() (STRING_CAST(malloc(sizeof(char)*MAX_BUFF)))
#define STRING_NEW_MIN() (STRING_CAST(malloc(sizeof(char)*MIN_BUFF)))
#define NEW(type) ((type*)malloc(sizeof(type)))
#define NEW_ARRAY(type,num_elem) (malloc(sizeof(type)*num_elem))

typedef enum Estado_Retorno{ 
	ERROR=-1, EXITO=1 
}Estado_Retorno;

typedef enum CmpEstate{ MENOR=-1, IGUALES, MAYOR }CmpEstate;

typedef enum Boolean { FALSE, TRUE }Boolean;

typedef int (*writefn)(FILE *pf, Generic g);
typedef Generic (*readSeekfn)(FILE *pf, fpos_t *g);

int StringWriteToFile(FILE *pf, Generic string);

Generic StringReadFromFile(FILE *pf);

Generic StringSeekReadFromFile(FILE *pf, fpos_t *pos);

int Fseek(FILE *pf, readSeekfn leerLinea, Generic id, cmpfn comp);

char *ItoStr(int num, int radix);

#ifdef	__cplusplus
}
#endif

#endif	/* _LIST_H */
