// arithm.c
// Daniele Grech Pereira, 02 November 2022

// Use basic arithmetic operators.

#include <stdio.h>
int main (int argc, char* argv[])
{

    // Declare and initialize vars:
    // int     add1=0, add2=0, mult1=0, mult2=0, div1=0, div2=0;
    int add[2] = {0}, mult[2] = {0}, div[2] = {0};
    // double  div3=0, div4=0;
    double div2[2] = {0};

    printf("All vars have been declared and initialized:\n");
    printf("add1: %d, add2: %d, mult1: %d, mult2: %d, div1: %d, div2: %d, div3: %.2lf, div4: %.2lf.\n", add[0], add[1], mult[0], mult[1], div[0], div[1], div2[0], div2[1]);

    printf("Enter first whole number to add: \n");
    scanf(" %d", &add[0]);
    printf("Enter second whole number to add: \n");
    scanf(" %d", &add[1]);
    printf("add1 + add2 = ?\n%d + %d = %d\n", add[0], add[1], add[0]+add[1]);

    printf("Enter first whole number to multiply: \n");
    scanf(" %d", &mult[0]);
    printf("Enter second whole number to multiply: \n");
    scanf(" %d", &mult[1]);
    printf("mult1 * mult2 = ?\n%d * %d = %d\n", mult[0], mult[1], mult[0]*mult[1]);

    printf("Enter first whole number to divide: \n");
    scanf(" %d", &div[0]);
    printf("Enter second whole number to divide: \n");
    scanf(" %d", &div[1]);
    printf("div1 / div2 = ?\n%d / %d = %d\n", div[0], div[1], div[0]/div[1]);
    printf("div1 %% div2 = ?\n%d %% %d = %d\n", div[0], div[1], div[0]%div[1]);

    printf("Enter first decimal number to divide: \n");
    scanf(" %lf", &div2[0]);
    printf("Enter second decimal number to divide: \n");
    scanf(" %lf", &div2[1]);
    printf("div3 / div4 = ?\n%.2lf / %.2lf = %.2lf\n", div2[0], div2[0], div2[0]/div2[1]);

    return 0;
}

// Arithmetic Operators
// https://devdocs.io/c/language/operator_arithmetic
//
// Binary additive arithmetic operator:         lhs + rhs
// Binary multiplicative arithmetic operator:   lhs * rhs
// Binary division arithmetic operator:         lhs / rhs
// Binary remainder arithmetic operator:        lhs % rhs
