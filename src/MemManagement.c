#include "MemManagement.h"
#include "string.h"

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

void add_ref(void *p, int type){
    static int counter;
    static char buffer[MAX_WORD_SIZE] = "";
    
    if(p IS NULL)
        return ;
    
    snprintf(buffer,sizeof(buffer),"%p",p);
    
    if(counter IS MAX_SIZE_REF_ALLOW_BLOCK){
        static Table new_table;
        ref_table_act = &new_table;
        counter = 0;
    }
    
    do{
        if(counter IS MAX_SIZE_REF_ALLOW_BLOCK)
            counter = 0;
        
        if(is_ref_Empty(&((*ref_table_act)[counter])) IS EMPTY){
            strcpy((*ref_table_act)[counter].addr,buffer);
            (*ref_table_act)[counter].id = type;
            break;
        }else{
            ++counter;
        }
    }while(1);
    
    ++counter;
}

int find_ref(void *ptr){
    int pos = -1;
    char buffer[MAX_WORD_SIZE] = "";
    
    if(ptr IS_NOT NULL){
        snprintf(buffer,sizeof(buffer),"%p",ptr);

        for(int i = 0; i < MAX_SIZE_REF_ALLOW_BLOCK; i++){
            char *temp;
            temp = (*ref_table_act)[i].addr;
            
            if(strcmp(temp,buffer) IS EQUAL)
                pos = i;
        }
    }
    
    return pos;
}

void remove_ref (void *ptr){
    int count = find_ref(ptr);
    
    if(count IS -1 ){
        printf("The object can't be referenced because it wasn't stablish with new method or it's a null pointer\n");
        return ;
    }
    
    address *a = &ref_table[count];
    printf("The object of type %d in the %s location has been removed\n",a->id,a->addr);
    init_ref(a);
    a->id = 0;
    
    free(ptr);
    ptr = NULL;
}

