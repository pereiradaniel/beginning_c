// Exercise 4-3
// Extend the previous program to output the appropriate name, such as
// “newline”, “space”, “tab”, and so on, for each whitespace character.

// REFACTOR: User selects range of char codes

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COLS 8   // Maximum columns to allow
#define CHAR_MAX 127 // Max char to print

void decodeChar(char c); // Prints a label for non printable characters.
void printTable(int min_char, int max_char, int cols); // Prints character code table.
void warnUser(int min_char, int max_char); // Warns user if input for table is invalid.

int main(int argc, char* argv[])
{
    int cols = 0;       // columns for user input
    int min_char = 0;   // min range for char codes
    int max_char = 0;   // max range for char codes

    bool repeat = true; // main repeat
    char again = 'n';   // user choice

    while (repeat == true)
    {
        while (cols <= 0 || cols > MAX_COLS)    // Loop until user input is within bounds
        {
            printf("\nThis program will output printable characters for code values from 0-%d.", CHAR_MAX);
            printf("\nHow many columns of character/code pairs per row would you like to see? (1-%d): ", MAX_COLS);
            scanf(" %d", &cols);

            if (cols <= 0 || cols > MAX_COLS)   // Warn user if input is out of bounds
                printf("\n%d is out of bounds! Enter a number from 1-%d.", cols, MAX_COLS);
        }
        
        while ((max_char <= 0 && min_char <= 0) || min_char >= max_char || max_char > CHAR_MAX || min_char == max_char)    // Loop until min and max char are valid
        {
            printf("\nWhat range of char codes do you want? (Range 0-%d, example input \"0 %d\"): ", CHAR_MAX, CHAR_MAX);
            scanf(" %d%d", &min_char, &max_char);

            warnUser(min_char, max_char);
        }

        printTable(min_char, max_char, cols);   // Print character code table
        
        printf("\n");

        printf("\nAgain ? (y/n): ");
        scanf(" %c", &again);

        if (again == 'n' || again == 'N')
            repeat = false;
        else if (again == 'y' || 'Y')
            max_char = 0, min_char = 0, cols = 0;            
    };
    
    return 0;
}

void warnUser(int min_char, int max_char)
{
    if (min_char < 0)
        printf("\n%d is out of bounds! Minimum number must be from  0-%d.", min_char, CHAR_MAX-1);
    if (max_char > CHAR_MAX)
        printf("\n%d is out of bounds! Maximum number must be less than 0-%d.", max_char, CHAR_MAX+1);
    if (min_char > max_char)
        printf("\n%d greater than %d! Minimum number must be less than maximum.", min_char, max_char);
    if (min_char == max_char)
        printf("\n%d is equal to %d! Minimum number must be less than maximum.", min_char, max_char);
}

void printTable(int min_char, int max_char, int cols)
{
    for(int i = min_char, j = 0; i <= max_char; ++i, ++j)      // Decode and print a character.
    {
        if (j%cols==0)
            printf("\n");                   // Print new line if num of cols reached.
        
        printf("  %4d",i);                  // Print code number
        
        if (isgraph(i))
            printf("               %c",i);  // Prints printable character
        else
            decodeChar(i);                  // Returns label for non-printable character
    }
}

void decodeChar(char c) // Prints a label for non printable characters.
{
    switch(c)
    {
        case '\n':
            printf("         newline");
            break;
        case ' ':
            printf("           space");
            break;
        case '\t':
            printf("  horizontal tab");
            break;
        case '\v':
            printf("    vertical tab");
            break;
            case '\f':
            printf("       form feed");
            break;
        default:
            printf("                ");
            break;
    }
}