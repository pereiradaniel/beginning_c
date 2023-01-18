// Exercise 4-3
// repli.it https://replit.com/@pereiradaniel/Exercise-4-3-refactor-3
// Extend the previous program to output the appropriate name, such as
// “newline”, “space”, “tab”, and so on, for each whitespace character.

// REFACTOR: User selects range of char codes
// REFACTOR2: Main program loops until user quits
// REFACTOR3: Count and report how many printable and non-printable chars.
// Edit: Improved functions of refactor3.

#include <stdio.h>
#include <ctype.h>      // isgraph()
#include <stdbool.h>    // boolean

void decodeChar(const char* c); // Prints a label for non printable characters.

int main(int argc, char* argv[])
{
    const int CHAR_MAX = 127;   // Maximum columns to allow
    const int MAX_COLS = 8;     // Max char to print

    int cols = 0;       // columns for user input
    int min_char = 0;   // min range for char codes
    int max_char = 0;   // max range for char codes

    bool repeat = true; // main repeat
    char again = 'n';   // user choice

    while (repeat == true) // Main program loop
    {
        while (cols <= 0 || cols > MAX_COLS)    // Loop until user input is within bounds.
        {
            printf("\nThis program will output printable characters for code values from 0-%d.", CHAR_MAX);
            printf("\nHow many columns of character/code pairs per row would you like to see? (1-%d): ", MAX_COLS);

            if (scanf(" %d", &cols) != 1)
                printf("\nFailed to read integer!");
          
            if (cols <= 0 || cols > MAX_COLS)   // Warn user if input is out of bounds.
                printf("\n%d is out of bounds! Enter a number from 1-%d.", cols, MAX_COLS);
        }
        
        while ((max_char <= 0 && min_char <= 0) || min_char >= max_char || max_char > CHAR_MAX || min_char == max_char || min_char < 0)    // Loop until input is valid.
        {
            printf("\nWhat range of char codes do you want? (Range 0-%d, example input \"0 %d\"): ", CHAR_MAX, CHAR_MAX);
            if (scanf(" %d %d", &min_char, &max_char) != 2)
                printf("\nFailed to read integers!\n");

            // Warn user if input is out of bounds.
            if (min_char < 0)           // Low number is less than 0.
                printf("\n%d is out of bounds! Minimum number must be from  0-%d.", min_char, CHAR_MAX-1);
            if (max_char > CHAR_MAX)    // High number is higher than allowed.
                printf("\n%d is out of bounds! Maximum number must be less than 0-%d.", max_char, CHAR_MAX+1);
            if (min_char > max_char)    // Low number is greater than high number.
                printf("\n%d greater than %d! Minimum number must be less than maximum.", min_char, max_char);
            if (min_char == max_char)   // Low number is same as high number.
                printf("\n%d is equal to %d! Minimum number must be less than maximum.", min_char, max_char);
        }

        for(int i = min_char, j = 0, np = 0; i <= max_char; ++i, ++j)      // Print table.
        {
            if (j%cols==0)
                printf("\n");                   // Print new line if num of cols reached.
            
            printf("  %4d",i);                  // Print code number.
            
            if (isgraph(i))
                printf("               %c",i);  // Prints printable character.
            else
            {
                decodeChar((char*)(&i));        // Returns label for non-printable character.
                ++np;                           // Count a non-printable char.
            }

            if (i == max_char)                  // If finished table, print this message.
                printf("\n\nThere were %d non printable and %d printable chars out of a total of %d character codes.\n",
                np,                         // no. of non printable chars
                (max_char-min_char+1)-np,   // no. of printable chars, +1 for zero inclusive counting
                max_char - min_char + 1);   // no. of total character codes scanned, +1 for zero inclusive counting
        }
    
        printf("\nAgain ? (y/n): ");            // Repeat program?
        if (scanf(" %c", &again) != 1)
          printf("\nFailed to read character!\n");

        if (again == 'n' || again == 'N')
            repeat = false;                     // Breaks main loop.
        else if (again == 'y' || again == 'Y')
            max_char = 0, min_char = 0, cols = 0;  // Reset values for another run.
    };
    
    return 0;
}

void decodeChar(const char* c) // Prints a label for non printable characters.
{
    switch(*c)
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
            printf("                ");  // 16 spaces
            break;
    }
}
