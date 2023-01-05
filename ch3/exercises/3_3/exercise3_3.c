// Exercise 3-3

// Write a program that will calculate the price for a quantity entered from
// the keyboard, given that the unit price is $5 and there is a discount of
// 10 percent for quantities over 30 and a 15 percent discount for quantities over 50.

#include <stdio.h>

#define DISCOUNTED_PRICE(quantity,unit_price,discount) quantity * unit_price * discount

int main(int argc, char*argv[])
{
    const int q1 = 30; // Discount quantity level 1: 30 or more items.
    const int q2 = 50; // Discount quantity level 2: 50 or more items.
    const int discount1 = 0.10;   // 10% discount
    const int discount2 = 0.15;   // 15% discount
    const int unit_price = 5.0;   // Price for single item.

    int quantity = 0;       // Quantity
    double total_price = 0;

    printf("\nEnter quantity:\n");
    scanf(" %d", &quantity);
    
    if (quantity > q2)
        total_price = DISCOUNTED_PRICE(quantity, unit_price, discount2);
    else if (quantity > 30 && quantity < 50)
        total_price = DISCOUNTED_PRICE(quantity, unit_price, discount1);
    else
        total_price = quantity * unit_price;

    printf("\nQuantity: %d, Total price after discount: %.2lf.", quantity, total_price);

    return 0;
}