// Exercise 4-3
// repli.it https://replit.com/@pereiradaniel/Exercise-4-3-refactor-3
// Extend the previous program to output the appropriate name, such as
// “newline”, “space”, “tab”, and so on, for each whitespace character.

// REFACTOR: User selects range of char codes
// REFACTOR2: Main program loops until user quits
// REFACTOR3: Count and report how many printable and non-printable chars.
// Edit: Improved functions of refactor3.
// REFACTOR4: Display codes in ascending or descending order.

#include <stdio.h>
#include <ctype.h>      // isgraph()
#include <stdbool.h>    // boolean

void decodeChar(const char* c);
void endMessage(const int non_printable, const int printable, const  int total);
int charPrint(const int i, const int np);
int ascendingOrder(const int min_char,const int max_char, const int cols);
int descendingOrder(const int min_char,const int max_char, const int cols);

int main(int argc, char* argv[])
{
    const int CHAR_MAX = 127;   // Max char to print
    const int MAX_COLS = 8;     // Maximum columns to allow

    int cols = 0;       // columns for user input
    int min_char = 0;   // min range for char codes
    int max_char = 0;   // max range for char codes
    int np = 0;         // non-printable char counter

    bool repeat = true;     // main repeat
    bool ascending = true;  // ascending or descending order
    
    char choice = 'n';      // user choice

    while (repeat == true) // Main program loop
    {
        // USER INPUTS NUMBER OF COLUMNS
        while (cols <= 0 || cols > MAX_COLS)    // Loop until user input is within bounds.
        {
            printf("\nThis program will output printable characters for code values from 0-%d.", CHAR_MAX);
            printf("\nHow many columns of character/code pairs per row would you like to see? (1-%d): ", MAX_COLS);

            if (scanf(" %d", &cols) != 1)
                printf("\nFailed to read integer!");
          
            if (cols <= 0 || cols > MAX_COLS)   // Warn user if input is out of bounds.
                printf("\n%d is out of bounds! Enter a number from 1-%d.", cols, MAX_COLS);
        }
        
        // USER SPECIFIES RANGE OF CHARACTER CODES
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

        // USER SELECTS ASCENDING OR DESCENDING ORDER FOR PRINTOUT
        printf("\nOutput codes in ascending or descending order? (A/D)");
        if (scanf(" %c", &choice) != 1)
          printf("\nFailed to read character!\n");
        
        if(toupper(choice) == 'D')      // Descending order selected.
            ascending = false;
        else if(toupper(choice) == 'A') // Ascending order selected.
            ascending = true;
        else if(toupper(choice) != 'A' || toupper(choice) != 'D') // Default behaviour.
            ascending = true;

        ascending == true ? printf("\nAscending") : printf("\nDescending");
        printf(" order selected.\n");

        // PRINT OUT CHAR/CODE TABLE ACCORDING TO USER PREFERENCES
        if (ascending == true)
            np = ascendingOrder(min_char, max_char, cols);
        else
            np = descendingOrder(min_char, max_char, cols);

        // PRINT RESULTS OF NON-PRINTABLE CHARS
        endMessage(np, (max_char-min_char+1)-np, max_char - min_char + 1);

        // USER DECIDES WHETHER TO REPEAT THE PROGRAM
        printf("\nAgain ? (y/n): ");            // Repeat program?
        if (scanf(" %c", &choice) != 1)
          printf("\nFailed to read character!\n");

        // PROGRAM BREAKS LOOP AND QUITS OR RESETS VARS AND REPEATS
        if (choice == 'n' || choice == 'N')         // Quit.
            repeat = false;                         // Breaks main loop.
        else if (choice == 'y' || choice == 'Y')    // Repeat.
            max_char = 0, min_char = 0, cols = 0, np = 0, choice = 'n';  // Reset values for another run.
    };
    
    return 0;
}

void endMessage(const int non_printable, const int printable, const  int total) // Prints end message for table.
{
    printf("\n\nThere were %d non printable and %d printable chars out of a total of %d character codes.\n",
                non_printable,              // no. of non printable chars
                printable,                  // no. of printable chars, +1 for zero inclusive counting
                total);                     // no. of total character codes scanned, +1 for zero inclusive counting
}

int charPrint(const int i, const int np) // Prints a char or decodes a char, returns counter.
{
    int ctr = np;
    printf("  %4d",i);                  // Print code number.
    
    if (isgraph(i))
        printf("               %c",i);  // Prints printable character.
    else
    {
        decodeChar((char*)(&i));        // Returns label for non-printable character.
        ++ctr;                          // Count a non-printable char.
    }
    return ctr;                         // Return counter.
}

int descendingOrder(const int min_char,const int max_char, const int cols) // Prints table in descending order.
{
    int np = 0;
    for(int i = max_char, j = cols; i >= min_char; --i, --j)      // Print table.
        {
            if (j%cols==0 && i != max_char)
                printf("\n");                   // Print new line if num of cols reached.

            np = charPrint(i, np);
        }
        return np;
}

int ascendingOrder(const int min_char,const int max_char, const int cols) // Prints table in ascending order.
{
    int np = 0;
    for(int i = min_char, j = 0; i <= max_char; ++i, ++j)      // Print table.
        {
            if (j%cols==0)
                printf("\n");                   // Print new line if num of cols reached.

            np = charPrint(i, np);
        }
    return np;
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
