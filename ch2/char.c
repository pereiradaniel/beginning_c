// Chars
// Daniel Pereira, 16 November 2022.

// Display a char and it's numerical value.

#include <stdio.h>

int main(int argv, char* argc[])
{
    char c = 0;
    printf("Enter a character: \n");
    scanf(" %c", &c);
    printf("The character: %c\nIt's numerical value: %d\n", c, c);

    return 0;
}