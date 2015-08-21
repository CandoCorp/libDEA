//
//  main.c
//  Tests_XCode
//
//  Created by Kevin Cando on 8/14/15.
//  Copyright (c) 2015 WhiteFox. All rights reserved.
//

#include <stdio.h>
#include "MemManagement.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",(int)sizeof(int));
    printf("%d\n",(int)sizeof(char));
    printf("%s\n",__func__);
    printf("%s\n",__FUNCTION__);
    printf("Hello, World!\n");
    char *const temp = NEW(char);
    
    debug_on();
    DELETE(temp);
    debug_off();
    return 0;
}
