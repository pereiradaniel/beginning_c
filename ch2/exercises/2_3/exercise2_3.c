// Exercise 2-3

// You’re selling a product that’s available in two versions: type 1 is a
// standard version priced at $3.50, and type 2 is a deluxe version priced at $5.50.
// Write a program using only what you’ve learned up to now that prompts for the user to
// enter the product type and a quantity, and then calculates and outputs the price for
// the quantity entered.

#include <stdio.h>
#include <ctype.h>  // toupper
#include <limits.h> // INT_MAX

// FIXED PRODUCT PRICES:
#define TYPE1 3.5f  // Type1 price
#define TYPE2 5.5f  // Type2 price

// A function that prints the user's input to the screen.
void calcStats(int type, int quantity);
// A function that returns the calculated the price.
double calculatePrice(int input, int quantity);
// A function that displays the results.
void display(int input, int quantity, double price);
// A function that validates a user's input.
int checkInput(int input, int min, int max);
// A function that returns the user's validated input.
int getInput(char* msg, int min, int max);

int main(int argc, char* argv[])
{
    // Set and initialize vars for main program:
    int type = 0, quantity = 0; // Vars for storing user input.
    double price = 0;           // Stores calculated results.

    char repeat = 'Y';          // Loop var for main program to repeat.

    // Main program loop:
    while (toupper(repeat) == 'Y')
    {
        // Get type from user, can be either 1 or 2:
        type = getInput("Select product type (1 or 2): ", 1, 2);
        
        // Get quantity from user, can be from 1 to largest possible INT value:
        quantity = getInput("Select quantity: ", 1, INT_MAX);

        // Display user's selection before calculating:
        calcStats(type, quantity);    

        // Calculate price based on user's input:
        price = calculatePrice(type, quantity);
        
        // Display final results:
        display(type, quantity, price);

        // Ask if user wants to repeat the main program:
        printf("\nAgain? (Y to repeat/any other key to quit) ");
        scanf(" %c", &repeat);
    };

    return 0;
}

int getInput(char* msg, int min, int max)
{
    int var = 0;
    printf("%s", msg);
    while(var == 0) {
        scanf(" %d", &var);
        var = checkInput(var, min, max);
    }; // Loops until input is valid and not == 0
    return var;
}

void calcStats(int type, int quantity)
{
    printf("\nProduct type %d selected @ %d units.", type, quantity);
}

double calculatePrice(int input, int quantity)
{
    double unit_price = 0;

    if (input == 1)
        unit_price = TYPE1;
    if (input == 2)
        unit_price = TYPE2;

    return unit_price * (double)quantity;
}

void display(int input, int quantity, double price)
{
    printf("\n\nRESULTS:\nProduct type: %d, quantity: %d, total: $%.2f\n", input, quantity, price);
}

int checkInput(int input, int min, int max)
{
    int result = 0; // Return 0 if input is invalid.

    if (input < min || input > max)     // out of bounds, invalid!
        printf("\nEnter a number between %d or %d!\n", min, max);
    
    if (input >= min && input <= max)   // inbounds, validate!
        result = input;

    return result;
}
