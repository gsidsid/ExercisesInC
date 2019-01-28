/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* Returns a pointer to unallocated memory!
 * 
 * returns: pointer to unallocated memory in stack
 */
int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }

    return array;
}

/* Prints address of pointer to array
 * 
 */
void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    /*
        After foo() is executed its locals are unallocated 
        and array is a meaningless pointer to space on the stacc.
    */
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
