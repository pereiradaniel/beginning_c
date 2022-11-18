// Exercise 2-1

// Write a program that prompts the user to enter a distance in inches and
// then outputs that distance in yards, feet, and inches.

// There are 12 inches in a foot and 3 feet in a yard.

#include <stdio.h>

int main(int argc, char* argv[])
{
    double input = 0, inches = 0, yards = 0, feet = 0, rem = 0;

    // Prompt user for input in inches:
    printf("Enter number of inches for conversion to yards, feet, inches: ");
    scanf(" %lf", &input);

    inches = input;

    // Convert inches into yards, feet, inches:

    yards = inches / 36;        // Get number of yards:
    rem = (int)inches % 36;     // Store remainder of inches.
    inches -= yards * 36 - rem; // Subtract yards from total inches.

    feet = inches / 12;        // Get number of feet:
    rem = (int)inches % 12;    // Store remainder of inches.
    inches -= feet * 12 - rem; // Subtract feet from total inches.

    // Display result:
    printf("User's input: %f inches.\n", input);
    printf("%f yards, %f feet, %f inches.\n", yards, feet, inches);

    return 0;
}