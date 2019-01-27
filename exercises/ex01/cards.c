/*
 * cards.c
 *
 * A program that receives card 
 * inputs and keeps a running
 * count of the card game
 *
 * Siddharth Garimella
 */
#include <stdio.h>
#include <stdlib.h>

int count = 0;

/* Display prompt and store user input
 * 
 * card_name: the variable to store user input
 */
void getCardInput(char *card_name) 
{
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
}

/* Converts numerical input to integer and returns a valid card value
 * 
 * card_name: numerical user input
 *
 * returns: card value
 */
int parseCardName(char *card_name)
{
    int val = atoi(card_name);
    if ((val < 1) || (val > 10)) {
        puts("I don't understand that value!");
    }
    return val;
}

/* Defines card values for valid alphanumerical card descriptors
 * 
 * card_name: user input
 *
 * returns: card value
 */
int getCardValue(char card_name[3])
{
    int val = 0;
    switch(*card_name) {    
    case 'K':
    case 'Q':
    case 'J':
        val = 10;
        break;
    case 'A':
        val = 11;
        break;
    case 'X':
        break;
    default:
        val = parseCardName(card_name);
    }
    return val;
}

/* Modifies running count depending on identified card value
 * 
 * val: card value
 */
void countCard(int val)
{
    if ((val > 2) && (val < 7)) {
        count++;
    } else if (val == 10) {
        count--;
    }
    if (val != 0) {
        printf("Current count: %i\n", count);
    }
}

int main()
{
    char card_name[3];
    int card_value = 0;
    while (card_name[0] != 'X') {
        getCardInput(card_name);
        card_value = getCardValue(card_name);
        countCard(card_value);
    }
    return 0;
}
