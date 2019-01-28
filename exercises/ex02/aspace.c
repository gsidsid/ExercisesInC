/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int printLocalVarAddress() {
    int local = 2;
    printf("Address of local is: %p\n", &local);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *np = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("np points to %p\n", np);
    printf ("s points to %p\n", s);

    printLocalVarAddress();

    return 0;
}
