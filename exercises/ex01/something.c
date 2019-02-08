#include <stdio.h>
#include <stdlib.h>

void update_count(char *card_name) {
    puts("test\n");
    printf("%2s\n", card_name);
}

int main() {
    char card_name[3];
    scanf("%2s",card_name);
    update_count(card_name);
}