// ecape_chars.c
// Daniele Grech Pereira, 02 November 2022

// Experiment with escape characters.

#include <stdio.h>
int main()
{
    printf("TABLE\n");
    printf("\t1. Item one\n");
    printf("\t2. Item two\n");
    printf("\t3. Item three\n");
    printf("\"double quotes\"\n");
    printf("\aAlert!\n");

    return 0;
}

// Escape chars:
// https://devdocs.io/c/language/escape
//
// Escape sequences are used to represent special characters within string literals
// and character constants.
// \t   Horizontal tab.
// \a   audible bell.