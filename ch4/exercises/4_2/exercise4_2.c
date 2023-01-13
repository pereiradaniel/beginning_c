// Exercise 4-2
// Write a program that will output the printable characters for character
// code values from 0 to 127. Output each character code along with its symbol with two
// characters to a line. Make sure the columns are aligned. (Hint: You can use the isgraph()
// function that’s declared in ctype.h to determine when a character is printable.)

#include <stdio.h>
#include <ctype.h>
#define MAX_COLS 8
#define MAX_CHAR_CODE 128
char isPrintable(char c);
int main(int argc, char* argv[])
{
    int columns = 0;
    
    while (columns == 0)
    {
        printf("\nThis program will output printable characters for code values from 0-127.");
        printf("\nHow many character/code pairs per row would you like to see? (1-%d): ", MAX_COLS);
        scanf(" %d", &columns);

        if (columns <= 0 || columns > MAX_COLS)
        {
            printf("\n%d is out of bounds! Enter a number from 1-%d.", columns, MAX_COLS);
            columns = 0;
        }
    }

    for(int i = 0; i < MAX_CHAR_CODE; i+=columns) // Loop through numbers 0-127
    {
        for (int j = 0; j<columns && (j+i) < MAX_CHAR_CODE; ++j) // Loop through columns
        {
            //if (i+j < MAX_CHAR_CODE)    
            printf("%d\t%c\t", i+j, isPrintable(i+j));
        }
        
        printf("\n"); // End of row
    }

    return 0;
}

char isPrintable(char c)
{
    return isgraph(c) ? c : ' ';
}