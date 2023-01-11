// Exercise 2-1

// Write a program that prompts the user to enter a distance in inches and
// then outputs that distance in yards, feet, and inches.

// There are 12 inches in a foot and 3 feet in a yard.

#include <stdio.h>

int main(int argc, char* argv[])
{
    // Constants for conversion process:
    const int inches_per_foot = 12;
    const int feet_per_yard   = 3;

    // Variables for user input and calculations:
    int input = 0, inches = 0, yards = 0, feet = 0;

    // Prompt user for input in inches:
    printf("Enter number of inches for conversion to yards, feet, inches: ");
    scanf(" %d", &input);

    inches = input;

    // Convert inches into yards, feet, inches:
    feet   =  inches / inches_per_foot;
    yards  =  feet   / feet_per_yard;

    feet   %= feet_per_yard;    // Remainder of feet!
    inches %= inches_per_foot;  // Remainder of inches!

    // Display result:
    printf("User's input: %d inches.\n", input);
    printf("%d yards, %d feet, %d inches.\n", yards, feet, inches);

    return 0;
}