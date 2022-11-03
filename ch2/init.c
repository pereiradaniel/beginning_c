// init.c
// Daniele Grech Pereira, 02 November 2022

// It is better to initialize variables when they are declared.
// If a variable is declared but not initialized, its value will
// be whatever has been left in memory from the last program to
// use that piece of memory!

#include <stdio.h>
int main(int argc, char* argv[])
{
    int num = 10; // Simultaneously declare and initialize a variable.

    for (int i = 0; i<num; ++i)
        printf("%d\n", i);

    return 0;
}
