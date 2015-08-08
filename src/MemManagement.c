#include "MemManagement.h"
#include <string.h>
#include "ErrorHandler.h"
#include "DataTypes.h"
#include "Const.h"

typedef char Word[MAX_WORD_SIZE];

struct _address{
    int id;
    Word addr;
};

typedef struct _address address; 

typedef address Table[MAX_SIZE_REF_ALLOW_BLOCK] ;

static Table ref_table;

Table *ref_table_act = &ref_table;

int is_ref_Empty(address *a);
void init_ref(address *a);
void init_table();

int find_ref(void *ptr);

inline void *new_malloc(size_t value, char *type){
    void add_ref(void *p, char *type);
    if(value IS 0)
        return NULL;
    
    void *ptr = malloc(value);
    
    check_mem(ptr);
    
    if(ptr != NULL){
        add_ref(ptr, type);
        return ptr;
    }
    
    error:
        return NULL;
}

inline void Delete(void *ptr,char *objName){
    void remove_ref (void *ptr,char *objName);
    remove_ref(ptr,objName);
}

inline void *new_calloc(size_t numElem, size_t size, char *type){
    void add_ref(void *p,char *type);
    
    if(numElem IS 0 OR size IS 0)
        return NULL;
    
    void *ptr = calloc(numElem,size);
    
    check_mem(ptr);
    
    if(ptr IS_NOT NULL){
        add_ref(ptr,type);
        return ptr;
    }
    
error:    
    return NULL;
}

int is_ref_Empty(address *a){
    if(strlen(a->addr) IS EMPTY)
        return EMPTY;
    return NOT_EMPTY;
}

void init_ref(address *a){
    if(a IS_NOT NULL)
        return;
    for(int j = 0; j < MAX_WORD_SIZE; j++)
        a->addr[j] = '\0';
    
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
            strcpy((*ref_table_act)[counter].addr,buffer);
            (*ref_table_act)[counter].id = dataTypeCode(type);
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
        snprintf(buffer,sizeof(buffer),"%p",ptr);

        for(int i = 0; i < MAX_SIZE_REF_ALLOW_BLOCK; i++){
            char *temp;
            temp = (*ref_table_act)[i].addr;
            
            if(strcmp(temp,buffer) IS EQUAL){
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
    int count = find_ref(ptr);
    
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
    debug("The object %s of type %d in the %s location has been removed\n",objName,a->id,a->addr);
    init_ref(a);
    a->id = 0;
    
    free(ptr);
    ptr = NULL;
}