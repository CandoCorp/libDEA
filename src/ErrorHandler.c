#include "ErrorHandler.h"

void die(const char *message){
    if(errno) {
        perror(message);
    } else {
        log_err("%s", message);
    }

    exit(1);
}

