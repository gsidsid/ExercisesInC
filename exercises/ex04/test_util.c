/*
  Siddharth Garimella
  Test code for util.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trout.h"
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char *res = icmpcode_v4(5);
    char *message = "test1 failed: icmpcode_v4(\"5\") should return \"source route failed\"";
    mu_assert(message, strcmp(res,"source route failed") == 0);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

