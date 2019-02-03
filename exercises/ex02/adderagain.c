/*
 * adder.c
 *
 * A program that sums numbers.
 *
 * Siddharth Garimella
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SUM_BUFFER_SIZE 10
#define INP_BUFFER_SIZE 5

int get_input(char *input)
{
    int numbers[SUM_BUFFER_SIZE];
    int number_ct = 0;
    char *c;
    c = getchar(); 
    while (c != EOF)  
    { 
        if (number_ct < SUM_BUFFER_SIZE) {
            number_ct++;
            if (isdigit(c)) 
            {
                numbers[number_ct] = atoi(c);
            } else {
                puts("Input must be numerical\n");
            }
        } else {
            puts("Number of inputs cannot exceed SUM_BUFFER_SIZE (10)\n");
        }
        
    } 
}
