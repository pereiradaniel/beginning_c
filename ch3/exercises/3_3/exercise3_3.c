// Exercise 3-3

// Write a program that will calculate the price for a quantity entered from
// the keyboard, given that the unit price is $5 and there is a discount of
// 10 percent for quantities over 30 and a 15 percent discount for quantities over 50.

#include <stdio.h>

#define UNIT_PRICE 5.0  // Single unit price
#define DISCOUNT1 0.10  // Level 1 discount > 30 < 50 items
#define DISCOUNT2 0.15  // Level 2 discount > 50 items
#define Q1 30           // Quantity threshold for level 1 discount > 30
#define Q2 50           // Quantity threshold for level 2 discount > 50

double calculatePrice(int quantity, double discount);

int main(int argc, char*argv[])
{
    int quantity = 0;       // Quantity
    double total_price = 0; // Total price after discount is applied

    printf("\nPlease enter number of items: ");
    scanf(" %d", &quantity);
    
    if (quantity > Q2)
        total_price = calculatePrice(quantity, DISCOUNT2);
    else if (quantity > Q1)
        total_price = calculatePrice(quantity, DISCOUNT1);
    else
        total_price = calculatePrice(quantity, 0.0);

    printf("\nTotal price after discount: %.2lf.\n", total_price);

    return 0;
}

double calculatePrice(int quantity, double discount)
{
    printf("\nApplying discount for %d items: %.2lf", quantity, discount);
    return (quantity * UNIT_PRICE) - (quantity * UNIT_PRICE * discount);
}