// Exercise 2-2

// Write a program that prompts for input of the length and width of a room in
// feet and inches, and then calculates and outputs the floor area in square yards with two
// decimal places after the decimal point.

#include <stdio.h>

double getYards(int feet, int inches)
{
    double result = (double)feet * 0.3333333 + (double)inches * 0.02777778;
    return result;
}

int main(int argc, char* argv[])
{
    int feet = 0, inches = 0; // vars for storing user input
    double length = 0, width = 0; // room dimensions in yards

    // Prompt user for length and width of a room in feet and inches.
    printf("ROOM LENGTH\n-----------\nEnter room length:\nFEET: ");
    scanf(" %d", &feet);
    printf("INCHES: ");
    scanf(" %d", &inches);

    length = getYards(feet, inches);

    printf("\nROOM WIDTH\n----------\nEnter room width:\nFEET: ");
    scanf(" %d", &feet);
    printf("INCHES: ");
    scanf(" %d", &inches);

    width = getYards(feet, inches);

    printf("\nRoom area: %.2f square yards.\n", length * width);

    return 0;
}