// vars.c
// Daniele Grech Pereira, 02 November 2022

// Demonstrate and explain briefly the simple usage of variables.

#include <stdio.h>
int main(int argc, char* argv[])
{
    int num,    // // Variable declaration, also a definition*.
        num2;   // Declare a second int variable for user input.
    
    num = 777;  // Arithmetic assignment statement**.

    // FOR DEMONSTRATION ONLY!!
    // Uncomment these two lines to see what happens when you try to print a var that has not been initialized.
    // printf("If you try to print num2 before it has a value assigned, you will retrieve the last data that was stored at that memory address!\n");
    // printf("num: %d, num2: %d\n", num, num2);
    
    printf("Enter a number to assign to num2: ");
 
    scanf(" %d", &num2);
    
    printf("Accessing int variable num: %d\n", num); // ***
    printf("Accessing int variable num2: %d\n", num2);

    return 0;
}

// * Even though nothing was assigned, whatever data may be stored at
//   that location will be the definition.

// ** Simple Arithmetic Assignment Statement
// https://devdocs.io/c/language/operator_assignment
//
// Operator	Operator name	    Example	    Description	            Equivalent of
// =	    basic assignment	a = b	    a becomes equal to b	N/A

// *** printf()
// https://devdocs.io/c/io/fprintf
//
// Writes the results to output stream stdout.
// 1st argument, "Enter a number...": Takes a pointer to a null-terminated
// multibyte string specifying how to interpret the data.
// 2nd argument, num: Arguments specifying data to print.
//
// %d: The conversion specifier for the variable. Determines how var is displayed
// on the screen. d = decimal (base 10) number.
