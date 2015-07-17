/*
 * File:   Mem_managment_test.c
 * Author: kevincando
 *
 * Created on Jul 16, 2015, 3:42:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "MemManagement.h"
/*
 * Simple C Test Suite
 */

void test1() {
    printf("Mem_management_test test 1\n");
}

void test2() {
    printf("Mem_management_test test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (Mem_ management_test) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% Mem_managment_test\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (Mem_managment_test)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (Mem_managment_test) \n");

    printf("%%TEST_STARTED%% test2 (Mem_managment_test)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (Mem_managment_test) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
