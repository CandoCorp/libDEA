#include "MemManagement.h"
#include <string.h>
#include <stdlib.h>
#include "DataTypes.h"
#include "MemHandlers.h"
#include <stdbool.h>

typedef long Word;

struct _address{
    Word addr;
    int id;
};

typedef struct _address address; 

typedef address Table[MAX_SIZE_REF_ALLOW_BLOCK] ;

static Table ref_table;

Table *ref_table_act = &ref_table;

void add_ref(void *p, char *type);
int is_ref_Empty(address *a);
void init_ref(address *a);
void init_table();

int find_ref(void *ptr);

 void *__new_malloc(size_t value, char *type){
    if(value IS 0){
        return NULL;
        debug("You can't assign a malloc of 0 bytes");
    }
    
    void *ptr = malloc(value);
    
    check_mem(ptr);
    
	if (ptr != NULL){
		add_ref(ptr, type);
        return ptr;
    }
    
    error:
        return NULL;
}

void __delete(void *ptr,char *objName){
    void remove_ref (void *ptr,char *objName);
	remove_ref(ptr,objName);
}

 void *__new_calloc(size_t numElem, size_t size, char *type){
    if(numElem IS_LESS_EQUAL_THAT 0){
        debug("You can't assign 0 or a negative value to the elements of the pointer");
        return NULL;
    }
    if(size IS_LESS_EQUAL_THAT 0){
        debug("You can't assign 0 or a negative value to the pointer");
        return NULL;
    }
    void *ptr = calloc(numElem,size);
    
    check_mem(ptr);
    
    if(ptr IS_NOT NULL){
		add_ref(ptr,type);
        return ptr;
    }
    
	error:    
	    return NULL;
}

 void *__new_realloc(void *ptr, size_t numElem,size_t size,char *type){
    if(ptr IS NULL){
        debug("The pointer in %p was a null pointer",ptr);
        return NULL;
    }
    
    if(numElem IS_LESS_EQUAL_THAT 0){
        debug("You can't assign 0 or a negative value to the elements of the pointer");
        return NULL;
    }
    
    if(size IS_LESS_EQUAL_THAT 0){
        debug("You can't assign 0 or a negative value to the pointer");
        return NULL;
    }
    
    void *ptr2 = realloc(ptr,numElem * size);
    
    check_mem(ptr2);
    
    if(ptr2 IS_NOT NULL){
        add_ref(ptr2,type);
        return ptr2;
    }
    
    error:
        return NULL;
}

int is_ref_Empty(address *a){
    if(a->addr IS EMPTY)
        return EMPTY;
    return NOT_EMPTY;
}

void init_ref(address *a){
    if(a IS_NOT NULL)
        return;
    
    a->addr = 0;
    a->id = 0;
}

void init_table(){
    for (int i = 0; i < MAX_SIZE_REF_ALLOW_BLOCK; i++){
        init_ref(ref_table_act[i]);
        ref_table_act[i]->id = 0;
    }
}

void add_ref(void *p, char *type){
    static int counter;
    static char buffer[MAX_WORD_SIZE] = "";
    
    if(p IS NULL){
        log_err("The object created wasn't allocated");
        return ;
    }
    snprintf(buffer,sizeof(buffer),"%p",p);
	
    if(counter IS MAX_SIZE_REF_ALLOW_BLOCK){
        static Table new_table;
        ref_table_act = &new_table;
        counter = 0;
    }
    
    do{
        if(counter IS MAX_SIZE_REF_ALLOW_BLOCK){
            debug("The number of references has exceeded the maximum per page");
            debug("Searching for free spaces in current page");
            counter = 0;
        }
        if(is_ref_Empty(&((*ref_table_act)[counter])) IS EMPTY){
            debug("Found empty reference in current page in ");
            (*ref_table_act)[counter].addr = (long)p;
            debug_if_all_levels(false){
                    (*ref_table_act)[counter].id = dataTypeCode(type);
            }
            break;
        }else{
            ++counter;
        }
    }while(1);
    
    ++counter;
}

int find_ref(void *ptr){
    int pos = -2;
    char buffer[MAX_WORD_SIZE] = "";
    
    if(ptr IS_NOT NULL){
        long ptrDir = (long)ptr;
        
        for(int i = 0; i < MAX_SIZE_REF_ALLOW_BLOCK; i++){
            long temp = 0;
            temp = (*ref_table_act)[i].addr;
            
            if(temp IS ptrDir){
                pos = i;
                debug("Reference found in position %d",pos);
                return pos;
            }
        }
        
        debug("No reference found");
        return -1;
    }
    
    debug("Null reference");
    return pos;
}

void remove_ref (void *ptr,char *objName){
    int count;

    debug_if_all_levels(false)
        count = find_ref(ptr);

    debug("The position of the reference is %d",count);

    if(count IS -2 ){
        log_err("%s can't be referenced because it's a null pointer",objName);
        return ;
    }
    
    if(count IS -1){
        log_err("%s can't be referenced because it wasn't stablish with new method",objName);
        return;
    }
    
    address *a = &ref_table[count];
    char *type;
    debug_if_all_levels(false)
        type = dataTypeCodeToString(a->id);

    debug("The object %s of type %s in the %lx location has been removed",objName,type,a->addr);
    init_ref(a);

    free(ptr);
    ptr = NULL;
}