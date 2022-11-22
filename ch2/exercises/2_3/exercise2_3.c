// Exercise 2-3

// You’re selling a product that’s available in two versions: type 1 is a
// standard version priced at $3.50, and type 2 is a deluxe version priced at $5.50.
// Write a program using only what you’ve learned up to now that prompts for the user to
// enter the product type and a quantity, and then calculates and outputs the price for
// the quantity entered.

#include <stdio.h>
#include <limits.h> // Makes use of INT_MAX
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

int main(int argc, char* argv[])
{
    int type = 0, quantity = 0;
    double price = 0;

    // USER SELECTS TYPE:
        // Can be either 1 or 2
        // Loops until input is valid and not == 0

    printf("Select product type (1 or 2): ");
    while(type == 0) {
        scanf(" %d", &type);
        type = checkInput(type, 1, 2);
    };

    // USER SELECTS QUANTITY:
        // Min value is 1
        // Max value for quantity is largest possible INT value!
        // Loops until input is valid and not == 0

    printf("\nSelect quantity: ");
    while(quantity == 0)
    {
        scanf(" %d", &quantity);
        quantity = checkInput(quantity, 1, INT_MAX);
    };

    // CALCULATE AND DISPLAY RESULTS:
    
    // Display user's selection:
    calcStats(type, quantity);
    
    // Calculate and display results:
    price = calculatePrice(type, quantity);
    display(type, quantity, price);

    return 0;
}

void calcStats(int type, int quantity)
{
    printf("\nProduct type %d selected @ %d units.", type, quantity);
}

double calculatePrice(int input, int quantity)
{
    double mult = 0;
    switch(input)
    {
        case 1:
            mult = TYPE1;
            break;
        case 2:
            mult = TYPE2;
            break;
    }
    return mult * (double)quantity;
}

void display(int input, int quantity, double price)
{
    printf("\n\nRESULTS:\nProduct type: %d, quantity: %d, total: $%.2f\n", input, quantity, price);
}

int checkInput(int input, int min, int max)
{
    int result = 0;

    if (input < min || input > max) // out of bounds, invalid!
        printf("\nEnter a number between %d or %d!\n", min, max);
    else // inbounds, validate!
        result = input;

    return result;
}