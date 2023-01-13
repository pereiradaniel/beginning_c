// Exercise 4-2
// Write a program that will output the printable characters for character
// code values from 0 to 127. Output each character code along with its symbol with two
// characters to a line. Make sure the columns are aligned. (Hint: You can use the isgraph()
// function that’s declared in ctype.h to determine when a character is printable.)

#include <stdio.h>
#include <ctype.h>

#define MAX_COLS 8   // Maximum columns to allow
#define CHAR_MAX 127 // Max char to print

int main(int argc, char* argv[])
{
    int cols = 0; // columns for user input
    
    while (cols <= 0 || cols > MAX_COLS) // Loop until user input is within bounds
    {
        printf("\nThis program will output printable characters for code values from 0-127.");
        printf("\nHow many character/code pairs per row would you like to see? (1-%d): ", MAX_COLS);
        scanf(" %d", &cols);

        if (cols <= 0 || cols > MAX_COLS) // Warn user if input is out of bounds
            printf("\n%d is out of bounds! Enter a number from 1-%d.", cols, MAX_COLS);
    }

    for(int i = 0; i <= CHAR_MAX; i+=cols) // Print row
    {
        for (int j = 0; j<cols && (j+i) <= CHAR_MAX; ++j) // Print col
            printf("%4d\t%4c\t", i+j, isgraph(i+j) ? i+j : ' ');
        printf("\n");
    }

    return 0;
}