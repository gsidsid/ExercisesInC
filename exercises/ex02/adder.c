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
#define INPUT_BUFFER_SIZE 5

int get_input = 1;
int scanf_flag;

int validate_input(char input[INPUT_BUFFER_SIZE])
{
    if (scanf_flag == EOF) {
        return 2;
    }

    if (strlen(input) > INPUT_BUFFER_SIZE) {
        printf("Input must not exceed buffer size (5).\n");
        return 0;
    }

    int i = 0; 
    while (input[i] != '\0')
    {
        if (!isdigit(input[i])) 
        {
            printf("Input must be numeric. Found: %s\n", input);
            return 0;
        } 
        i++;
    }
    return 1;
}

int next_number() 
{
    char input[INPUT_BUFFER_SIZE];
    printf("Enter a number: ");
    scanf_flag = scanf("%9s", input);
    if (validate_input(input) == 2)
    {
        get_input = 0;
        return 0;
    }
    else if (validate_input(input) == 1)
    {
        return atoi(input);
    } else 
    {
        return 0;
    }
}

int main() 
{
    int numbers[SUM_BUFFER_SIZE];
    int i = 0;
    int a;
    int sum = 0;
    while (get_input == 1) {
        a = next_number();
        if (i < SUM_BUFFER_SIZE && a != 0) 
        {
            numbers[i] = a;
            i++;
        } else if (i >= SUM_BUFFER_SIZE-1)
        {
            puts("\nNumber of entries must not exceed buffer size. Enter Ctrl+Z to sum and exit.\n");
        }
    }
    
    for (int j = 0; j < i; j++)
    {
        sum = sum + numbers[j];
    }

    printf("SUM: %d\n", sum);
}