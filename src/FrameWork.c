#include "FrameWork.h"
#include <string.h>

int StringWriteToFile(FILE *pf,Generic string){
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

Generic StringSeekReadFromFile(FILE *pf,fpos_t *pos){
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

/*
int ListCmp(List *L1,List *L2){
	if(L1==L2||sizeof(L1)==sizeof(L2))	return IGUALES;
	if(sizeof(L1)>=sizeof(L2))	return MAYOR;
	if(sizeof(L1)<=sizeof(L2)) return MENOR;
}

int ListCmpXContenido(List *L1,List *L2,cmpfn fn){
	NodeList *it,*it2;
	if(!ListCmp(L1,L2)) return IGUALES;
	for(it=listGetHeader(L1);it!=NULL;it=nodeListGetNext(it)){
		for(it2=listGetHeader(L2);it2!=NULL;it2=nodeListGetNext(it2)){
			if(fn(it->cont,it2->cont)!=0) return MAYOR;
		}
	}
	return IGUALES;
}

int ListDECmp(ListDE *L1,ListDE *L2){
	if(L1==L2||sizeof(L1)==sizeof(L2))	return IGUALES;
	if(sizeof(L1)>=sizeof(L2))	return MAYOR;
	if(sizeof(L1)<=sizeof(L2)) return MENOR;
}

int ListDECmpXContenido(ListDE *L1,ListDE *L2,cmpfn fn){
	NodeListDE *it,*it2;
	if(!ListDECmp(L1,L2)) return IGUALES;
	for(it=listDE_GetHeader(L1);it!=NULL;it=nodeListDE_GetNext(it)){
		for(it2=listDE_GetHeader(L2);it2!=NULL;it2=nodeListDE_GetNext(it2)){
			if(fn(it->cont,it2->cont)!=0) return MAYOR;
		}
	}
	return IGUALES;
}

List *ListCpy(List *L2){
	NodeList *it;
	List *L1=listNew();
	if(L2!=NULL){
		for(it=listGetHeader(L2);it!=NULL;it=nodeListGetNext(it)){
			listAddNode(L1,nodeListNew(nodeListGetCont(it)));
		}
	}
	return L1;
}

ListDE *ListDECpy(ListDE *L2){
	NodeListDE *it,*it2;
	ListDE *L1=listDE_New();
	if(L1!=NULL&&L2!=NULL){
		for(it=listDE_GetHeader(L2);it!=NULL;it=nodeListDE_GetNext(it)){
			listDE_AddNode(L1,nodeListDE_New(nodeListDE_GetCont(it)));
		}
	}
	return L1;
}

int ListCat(List *L1,List *L2){
	NodeList *it;
	if(L1==NULL&&L2==NULL) return ERROR;
	for(it=listGetHeader(L2);it!=NULL;it=nodeListGetNext(it))
		listAddNode(L1,nodeListNew(nodeListGetCont(it)));
	return EXITO;
}

List *ListGen(List *L1,Generic g,cmpfn fn){
	NodeList *it;
	List *L2=listNew();
	int cont=0;

	if(L1==NULL||g==NULL) return NULL;
	for(it=listGetHeader(L1);it!=NULL;it=nodeListGetNext(it)){
		if(fn(nodeListGetCont(it),g)==0)
			cont++;
		if(cont!=0)
			listAddNode(L2,nodeListNew(nodeListGetCont(it)));
	}
	return L2;
}

List *ListList(List *L1,List *L2,cmpfn fn){
	NodeList *it,*it2=listGetHeader(L2),*it3,*it4;
	int cont=0,num_elem=0;
	List *L3=listNew();
	for(it=listGetHeader(L2);it!=NULL;it=nodeListGetNext(it)){
		for(it2=listGetHeader(L1);it2!=NULL;it2=nodeListGetNext(it2)){
			if(fn(nodeListGetCont(it),nodeListGetCont(it2))==0){
				if(cont==0){
					it3=it2;
					cont++;
					num_elem++;
				}else
					num_elem++;
			}
		}
	}
	if(num_elem==listGetSize(L2))
		while(it3!=NULL){
			listAddNode(L3,nodeListNew(nodeListGetCont(it3)));
			it3=nodeListGetNext(it3);
		}
	
	return L3;
}

int ListDECat(ListDE *L1,ListDE *L2){
	NodeListDE *it;
	if(L1==NULL&&L2==NULL) return ERROR;
	for(it=listDE_GetHeader(L2);it!=NULL;it=nodeListDE_GetNext(it))
		listDE_AddNode(L1,nodeListDE_New(nodeListDE_GetCont(it)));
	return EXITO;
}

ListDE *ListDEGen(ListDE *L1,Generic g,cmpfn fn){
	NodeListDE *it;
	ListDE *L2=listDE_New();
	int cont=0;

	if(L1==NULL||g==NULL) return NULL;
	for(it=listDE_GetHeader(L1);it!=NULL;it=nodeListDE_GetNext(it)){
		if(fn(nodeListDE_GetCont(it),g)==0)
			cont++;
		if(cont!=0)
			listDE_AddNode(L2,nodeListDE_New(nodeListDE_GetCont(it)));
	}
	return L2;
}

ListDE *ListDEListDE(ListDE *L1,ListDE *L2,cmpfn fn){
	NodeListDE *it,*it2,*it3;
	int cont=0,num_elem=0;
	ListDE *L3=listDE_New();
	for(it=listDE_GetHeader(L2);it!=NULL;it=nodeListDE_GetNext(it)){
		for(it2=listDE_GetHeader(L1);it2!=NULL;it2=nodeListDE_GetNext(it2)){
			if(fn(nodeListDE_GetCont(it),nodeListDE_GetCont(it2))==0){
				if(cont==0){
					it3=it2;
					cont++;
					num_elem++;
				}else
					num_elem++;
			}
		}
	}
	if(num_elem==listDE_GetSize(L2))
		while(it3!=NULL){
			listDE_AddNode(L3,nodeListDE_New(nodeListDE_GetCont(it3)));
			it3=nodeListDE_GetNext(it3);
		}
	
	return L3;
}

int ListWriteFile(FILE *pf,List *L,writefn fn){
	NodeList *it;
	
	if(listIsEmpty(L)) return ERROR;
	for(it=listGetHeader(L);it!=NULL;it=nodeListGetNext(it)){
		if(fn(pf,nodeListGetCont(it))!=ERROR);
	}
	printf("No se pudo escribir en el archivo");
}
char *StringLeerLinea(FILE *pf){
	char *buff=STRING_CAST(malloc(sizeof(char)*MAX_BUFF));
	fgets(buff,MAX_BUFF,pf);
	return buff;
}
int StringEscribirLinea(FILE *pf,char *linea){
	fputs(linea,pf);
}
int MakeFileFromHash(char *filename,HashMap M){
	FILE *pf=fopen(filename,SOBREESCRIBIR);

	fclose(pf);
}
int HashMapGetSize(HashMap M){
	int i=0,cont=0;
	for(i=0;i<B;i++){
		if(M[B].e==FULL)
			cont++;
	}
	return cont;
}

int Fseek(FILE *pf,readSeekfn leerLinea,Generic id,cmpfn comp){
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

char *ItoStr(int num,int radix){
	char *string=STRING_CAST(NEW_ARRAY(char,10));
	char *string1;
	//string1=itoa(num,string,radix);
	return string;
}

Estado_bool listElementoExiste(List *L,Generic cont,cmpfn cmp){
	NodeList *iterator;
    for(iterator = L->header; iterator!=NULL; iterator = iterator->next){
		if(cmp(iterator->cont, cont) == 0) return TRUE;
    }
	return FALSE;
}

Estado_bool listDestroy(List **L){
	NodeList *it;
	int i;
	for(i=0;i<listGetSize(*L);i++){
		it=listGetLast(*L);
		free(it);
	}
	free(*L);
}

*/