// Exercise 3-1

// Write a program that will first allow a user to choose one of two options:

//     1. Convert a temperature from degrees Celsius to degrees Fahrenheit.
//     2. Convert a temperature from degrees Fahrenheit to degrees Celsius.

// The program should then prompt for the temperature value to be entered and output the new value that results
// from the conversion. To convert from Celsius to Fahrenheit you can multiply the value by 1.8 and then add 32.

#include <stdio.h>
#include <ctype.h>
#define TOFARENHEIT(a) a*1.8+32.0
#define TOCELSIUS(a) (a-32.0)/1.8

int main(int argc, char* argv[])
{
    int choice = 0;     // Stores user's menu choice.
    double temp = 0.0;  // Stores user's temperature input.

    char repeat = 'Y';

    while (toupper(repeat)=='Y')
    {
        choice = 0;
        while (choice == 0)
        {
            printf("Choose 1 or 2 from the following options:\n");
            printf("\t1. Convert a temperature from degrees Celsius to degrees Fahrenheit.\n");
            printf("\t2. Convert a temperature from degrees Fahrenheit to degrees Celsius.\n");
            scanf(" %d", &choice);
            
            if (choice != 1 && choice != 2)
            {
                printf("\nInvalid selection! Choose 1 or 2. Try again.\n");
                choice = 0;
            }
        }

        printf("Enter temperature to convert:\n");
        scanf(" %lf", &temp);

        if (choice == 1)
            printf("\nConversion:\n%.2f celsius is %.2lf fahreneit.\n", temp, TOFARENHEIT(temp));
        if (choice == 2)
            printf("\nConversion:\n%.2f farenheit is %.2lf celsius.\n", temp, TOCELSIUS(temp));

        printf("\nAgain? (Y to repeat, any other key to quit.)\n");
        scanf(" %c", &repeat);
    }

    return 0;
}