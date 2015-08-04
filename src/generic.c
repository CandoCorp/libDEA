
#include <generic.h>
#include <stdlib.h>

/**
* @file generic.c
* @brief Este archivo contiene la implementacion del 
* TDA Generic que representa a cualquier tipo de dato. Una variable
* Generic puede ser asignada a cualquier tipo de puntero, se le
* puede recuperar su valor y modificar su valor con las funciones
* aqui especificadas.
*
* @author Kevin Cando
* @author Marisol Villacres
* @author Veronica Macias
*
* @date 03/28/2015

int equals(Generic a, Generic b){
    
}

int compareTo(Generic a, Generic b, cmpfn fn){
    
}

char *toString(const char* format, ...){
    
}

int StringWriteToFile(FILE *pf, Generic string){
    if(pf!=NULL||string!=NULL){
		fprintf(pf,"[");
		fprintf(pf,"%s",string);
		fprintf(pf,"]");
		fprintf(pf," ",string);
		fflush(pf);
		return EXITO;
	}
	fflush(pf);
	return ERROR;
}

Generic StringReadFromFile(FILE *pf){
    char *lee=STRING_NEW_MAX();
	int longi;
	
	//fflush(pf);
	fgetc(pf);
	if(pf!=NULL) fscanf(pf,"%[^]]",lee);
	longi=strlen(lee);
	//lee=STRING_CAST(realloc(lee,sizeof(char)*longi+1));
	fgetc(pf);
	fgetc(pf);
	return lee;
}

Generic StringSeekReadFromFile(FILE *pf, fpos_t *pos){
    char *lee=STRING_NEW_MAX();
	int longi;
	fgetpos(pf,pos);
	fgetc(pf);
	if(pf!=NULL) fscanf(pf,"%[^]]",lee);
	longi=strlen(lee);
	lee=STRING_CAST(realloc(lee,sizeof(char)*longi+1));
	fgetc(pf);
	fgetc(pf);
	return lee;
}

int Fseek(FILE *pf, readSeekfn leerLinea, Generic id, cmpfn comp){
    Generic g;
	fpos_t ini,fin;
	char *temp=STRING_NEW_MAX();
	if(pf==NULL||id==NULL) return ERROR;
	rewind(pf);
	while(!feof(pf)){
		g=leerLinea(pf,&ini);
		if(comp(id,g)==IGUALES){
			fgetpos(pf,&fin);
			fscanf(pf,"%[^-1]",temp);
			fsetpos(pf,&ini);
			fputs(temp,pf);
			free(temp);
			return EXITO;
		}
	}
	return ERROR;
}


int compareWithOrderType(Generic g, Generic h, cmpfn cmp, int type){
        if(type == 0)
            return (cmp(g,h) <=0);
        else if(type == 1)
            return (cmp(g,h) > 0);
        printf("a");
        
}
*/

