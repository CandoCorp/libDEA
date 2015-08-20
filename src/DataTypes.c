#include "DataTypes.h"
#include <stdio.h>
#include "MemHandlers.h"
#include "ErrorHandler.h"
#include <string.h>

static volatile int counter = 0;

struct __CustomDataType{
    char *name;
    int id;
    struct __CustomDataType *next;
};

static struct __CustomDataType *dataTypeList = NULL;

static int dataType_free();
inline int dataType_Add(const char name[]);
inline int dataTypeCodeCustom(const char name[]);
const char *restrict dataTypeCustomCodeToString(int opCode, int *errCode);

inline int dataTypeCode(const char *restrict name){
    
    if(name IS NULL){
        log_err("The name of the data type is null");
        return -1;
    }
    if(strcmp(name,"int") IS EQUAL)
        return INT;
    if(strcmp(name,"bool") IS EQUAL)
        return BOOL;
    if(strcmp(name,"char") IS EQUAL)
        return CHAR;
    if(strcmp(name,"float") IS EQUAL)
        return FLOAT;
    if(strcmp(name,"double") IS EQUAL)
        return DOUBLE;
    if(strcmp(name,"string") IS EQUAL)
        return STRING;
    if(strcmp(name,"complex") IS EQUAL)
        return COMPLEX;
    if(strcmp(name,"fraction") IS EQUAL)
		return FRACTION;
	if (strcmp(name, "unsigned int") IS EQUAL)
		return UNSIGNED_INT;
	if (strcmp(name, "signed char") IS EQUAL)
		return SIGNED_CHAR;
	if (strcmp(name, "unsigned char") IS EQUAL)
		return UNSIGNED_CHAR;
	if (strcmp(name, "long int") IS EQUAL)
		return LONG_INT;
	if (strcmp(name, "long double") IS EQUAL)
		return LONG_DOUBLE;
	if (strcmp(name, "unsigned long int") IS EQUAL)
		return UNSIGNED_LONG_INT;
	if (strcmp(name, "long long int") IS EQUAL)
		return LONG_LONG_INT;
	if (strcmp(name, "unsigned long long int") IS EQUAL)
		return UNSIGNED_LONG_LONG_INT;
    
	int type;
	
	debug_if_all_levels{
		type = dataType_Add(name);
	}
    
	switch(type){
        case -2:{
            debug("Somehow the name pointer is empty");
            return -2;
        }break;
        case -1:{
            debug("There was an assignation problem of memory");
            return -3;
        }break;
        default:{
            debug("The data type was found in the user system in %d position",counter + __LAST_DATA_TYPE);
            return counter + __LAST_DATA_TYPE;
        }break;
    }
}
const char *restrict dataTypeCodeToString(unsigned int code){
	switch (code){
		case BOOL:{
			debug("The data type was of type %s", DataTypesNames[BOOL]);
			return DataTypesNames[BOOL];
			break;
		}
		case CHAR:{
			debug("The data type was of type %s", DataTypesNames[CHAR]);
			return DataTypesNames[CHAR];
			break;
		}
		case UNSIGNED_CHAR:{
			debug("The data type was of type %s", DataTypesNames[UNSIGNED_CHAR]);
			return DataTypesNames[UNSIGNED_CHAR];
			break;
		}
		case SIGNED_CHAR:{
			debug("The data type was of type %s", DataTypesNames[SIGNED_CHAR]);
			return DataTypesNames[SIGNED_CHAR];
			break;
		}
		case UNSIGNED_SHORT_INT:{
			debug("The data type was of type %s", DataTypesNames[UNSIGNED_SHORT_INT]);
			return DataTypesNames[UNSIGNED_SHORT_INT];
			break;
		}
		case SHORT_INT:{
			debug("The data type was of type %s", DataTypesNames[SHORT_INT]);
			return DataTypesNames[SHORT_INT];
			break;
		}
		case INT:{
			debug("The data type was of type %s", DataTypesNames[INT]);
			return DataTypesNames[INT];
			break;
		}
		case UNSIGNED_INT:{
			debug("The data type was of type %s", DataTypesNames[UNSIGNED_INT]);
			return DataTypesNames[UNSIGNED_INT];
			break;
		}
		case LONG_INT:{
			debug("The data type was of type %s", DataTypesNames[LONG_INT]);
			return DataTypesNames[LONG_INT];
			break;
		}
		case UNSIGNED_LONG_INT:{
			debug("The data type was of type %s", DataTypesNames[LONG_INT]);
			return DataTypesNames[LONG_INT];
			break;
		}
		case LONG_LONG_INT:{
			debug("The data type was of type %s", DataTypesNames[LONG_LONG_INT]);
			return DataTypesNames[LONG_LONG_INT];
			break;
		}
		case UNSIGNED_LONG_LONG_INT:{
			debug("The data type was of type %s", DataTypesNames[UNSIGNED_LONG_LONG_INT]);
			return DataTypesNames[UNSIGNED_LONG_LONG_INT];
			break;
		}
		case FLOAT:{
			debug("The data type was of type %s", DataTypesNames[FLOAT]);
			return DataTypesNames[FLOAT];
			break;
		}
		case DOUBLE:{
			debug("The data type was of type %s", DataTypesNames[DOUBLE]);
			return DataTypesNames[DOUBLE];
			break;
		}
		case LONG_DOUBLE:{
			debug("The data type was of type %s", DataTypesNames[LONG_DOUBLE]);
			return DataTypesNames[LONG_DOUBLE];
			break;
		}
		case STRING:{
			debug("The data type was of type %s", DataTypesNames[STRING]);
			return DataTypesNames[STRING];
			break;
		}
		case COMPLEX:{
			debug("The data type was of type %s", DataTypesNames[COMPLEX]);
			return DataTypesNames[COMPLEX];
			break;
		}
		case FRACTION:{
			debug("The data type was of type %s", DataTypesNames[FRACTION]);
			return DataTypesNames[FRACTION];
			break;
		}
		default:{
			int errCode;
			char *dataTypeName;
			debug_if_all_levels{
				dataTypeName = dataTypeCustomCodeToString(code, &errCode);
			}
			return dataTypeName;
			break;
		}
	}
}

const char *restrict dataTypeCustomCodeToString(int opCode,int *errCode){
	struct __CustomDataType *it;

	if (dataTypeList IS NULL){
		log_err("There are not data types defined by the system");
		*errCode = -2;
		return NULL;
	}

	for (struct __CustomDataType *it = dataTypeList; it != NULL; it = it->next){
		debug("[Actual Node] : %s", it->name);
		if (opCode IS it->id){
			debug("The name of the data type is found");
			return it->name;
		}
		debug("[Next Node] : %p", it->next);
	}

	log_err("The data type wasn't found in the system");
	*errCode = -1;
	return NULL;
}

int dataTypeCodeCustom(const char name[]){
    struct __CustomDataType *it;
    
    if(dataTypeList IS NULL){
        log_err("There are not data types defined by the system");
        return -2; 
    }
    for(struct __CustomDataType *it = dataTypeList; it!=NULL; it = it->next){
        debug("[Actual Node] : %s",it->name);
        if(strcmp(name,it->name) IS EQUAL){
            debug("The name of the data type is found");
            return it->id;
        }
        debug("[Next Node] : %p",it->next);
    }
    
    log_err("The data type wasn't found in the system");
    return -1;
}

int dataType_Add(const char name[]){
    struct __CustomDataType *it = MALLOC(struct __CustomDataType);
    
    check_mem(it);
    
    if(name IS NULL){
        log_err("The name pointer was null");
        free(it);
        return -2;
	}
	int pos;

	debug_if_all_levels{
		pos = dataTypeCodeCustom(name);
	}

    switch(pos){
        case -2:{
            debug("The data type list is empty");
            char *temp = MALLOC_ARRAY(char,strlen(name)+1);
            check_mem(temp);
            strcpy(temp,name);
            it->id = __LAST_DATA_TYPE;
            it->name = temp;
            it->next = dataTypeList;
            dataTypeList = it;
            debug("Iterator node added to the end of the list");
            //++counter;
        }break;
        case -1:{
            int i = 0;
            debug("I have begun to add the node to the end of the system");
            for(struct __CustomDataType *node = dataTypeList; node IS_NOT NULL; node = node->next,i++){
                debug("[Current node]: %s",node->name);
                if(node->next IS NULL){
                    debug("Last node found!");
                    debug("Last node: %s",node->name);
                    char *temp = MALLOC_ARRAY(char,strlen(name)+1);
                    check_mem(temp);
                    strcpy(temp,name);
                    it->id = counter + __LAST_DATA_TYPE;
                    it->name = temp;
                    it->next = NULL;
                    debug("New last node: %s",it->name);
                    node->next = it;
					++counter;
					return 0;
                }
                debug("[Next node]: %p",node);
            }
        }break;
        default:{
			free(it);
            debug("Already found in the system\n");
        }
    }
    
    return 1;
    
    error:
			return -1;
}

static int dataType_free(){
    if(dataTypeList IS NULL)
        return -1;
    
    for(struct __CustomDataType *node = dataTypeList; node IS_NOT NULL ; node = node->next){
        struct __CustomDataType *it;
        if(node->next IS_NOT NULL){
            it = node;
            node = node->next;
            it->next = NULL;
            free(it->name);
            free(it);
            it = NULL;
        }else{
            free(node->name);
            free(node);
            node = NULL;
        }
    }
}
