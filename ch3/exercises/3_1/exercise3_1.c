// Exercise 3-1

// Write a program that will first allow a user to choose one of two options:

//     1. Convert a temperature from degrees Celsius to degrees Fahrenheit.
//     2. Convert a temperature from degrees Fahrenheit to degrees Celsius.

// The program should then prompt for the temperature value to be entered and output the new value that results
// from the conversion. To convert from Celsius to Fahrenheit you can multiply the value by 1.8 and then add 32.

#include <stdio.h>
int main(int argc, char* argv[])
{
    int choice = 0;
    double temp = 0.0;

    printf("Choose 1 or 2 from the following options:\n");
    printf("\t1. Convert a temperature from degrees Celsius to degrees Fahrenheit.\n");
    printf("\t2. Convert a temperature from degrees Fahrenheit to degrees Celsius.\n");
    scanf(" %d", &choice);

    printf("Enter temperature to convert:\n");
    scanf(" %lf", &temp);

    if (choice == 1)
        printf("\nConversion: %.2lf fahreneit.\n", temp*1.8+32.0);
    if (choice == 2)
        printf("\nConversion: %.2lf celsius.\n", (temp-32.0)/1.8);

    return 0;
}