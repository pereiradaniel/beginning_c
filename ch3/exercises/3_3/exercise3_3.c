// Exercise 3-3

// Write a program that will calculate the price for a quantity entered from
// the keyboard, given that the unit price is $5 and there is a discount of
// 10 percent for quantities over 30 and a 15 percent discount for quantities over 50.

#include <stdio.h>



double calculatePrice(int quantity);

int main(int argc, char*argv[])
{
    const int q1 = 30; // Discount quantity level 1: 30 or more items.
    const int q2 = 50; // Discount quantity level 2: 50 or more items.
    const int discount1 = 0.10;   // 10% discount
    const int discount2 = 0.15;   // 15% discount
    const int unit_price = 5.0;   // Price for single item.

    int quantity = 0;       // Quantity
    int total_price = 0;

    printf("\nEnter quantity:\n");
    scanf(" %d", &quantity);

    total_price = calculatePrice(quantity);

    printf("\nQuantity: %d, Total price after discount: %lf.", quantity, total_price);

    return 0;
}

double calculatePrice(int quantity)
{
    double result = 0.0;
    
    if (quantity < 31)
    {
        result = (double)quantity * unit_price * discount1;
    }

    return result;
};