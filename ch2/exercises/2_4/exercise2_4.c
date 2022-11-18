// Exercise 2-4

// Write a program that prompts for the user’s weekly pay in dollars and the
// hours worked to be entered through the keyboard as floating-point values. The program
// should then calculate and output the average pay per hour in the following form:

//     Your average hourly pay rate is 7 dollars and 54 cents.

#include <stdio.h>
double checkInput(double input, double min, double max);

int main(int argc, char* argv[])
{
    double hours = 0, rate = 0;

    // Get input for hours:
    printf("Enter number of hours worked: ");
    while(hours == 0) {
        scanf(" %lf", &hours);
        hours = checkInput(hours, 1, 10000);
    }
    
    // Get input for salary:
    printf("Enter hourly rate: ");
    while(rate == 0)
    {
        scanf(" %lf", &rate);
        rate = checkInput(rate, 1, 100);
    }
    
    // Calculate pay:
    printf("Pay: $%.2f\n", hours * rate);

    return 0;
}

double checkInput(double input, double min, double max)
{
    double result = 0;

    if (input < min || input > max) // out of bounds, invalid!
        printf("Enter a number between %.f or %.f!\n", min, max);
    else // inbounds, validate!
        result = input;
    
    return result;
}