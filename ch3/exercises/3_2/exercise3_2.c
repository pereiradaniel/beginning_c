// Exercise 3-2

// Write a program that prompts the user to enter the date as three integer
// values for the month, the day in the month, and the year. The program should then output
// the date in the form 31st December 2003 when the user enters 12 31 2003, for example.

// You will need to work out when th, nd, st, and rd need to be appended to the day value. Don’t forget 1st, 2nd, 3rd,
// 4th; but 11th, 12th, 13th, 14th; and 21st, 22nd, 23rd, and 24th.

#include <stdio.h>

void printDay(int day);
const char* daySuffix(int day);
void printMonth(int month);
void printYear(int year);

int main(int argc, char* argv[])
{
    // INPUT
    // Declare variables:
        int month, day, year = 0;
    
    // Prompt user for input:
        printf("\nEnter the date as three integer values, separated by spaces (month day year).\nExample 12 31 2003\n");
        scanf(" %d", &month);
        scanf(" %d", &day);
        scanf(" %d", &year);
    
    // OUTPUT
    // Detect day and and append suffix, print:
    printDay(day);

    // Detect month and print:
    printMonth(month);
  
    // Print year:
    printYear(year);
    
    return 0;
}

void printDay(int day)
{
    if (day > 3 && day < 21 || day > 23 && day < 31)
        printf("\n%dth ", day);
    else
        printf("\n%d%s ", day, daySuffix(day));
}

const char* daySuffix(int day)
{
    return (day%10 == 1 ? "st": (day%10 ==2 ? "nd" : "rd"));
}

void printMonth(int month)
{
    switch(month)
    {
        case 1:
        printf("January ");
        break;
        case 2:
        printf("February ");
        break;
        case 3:
        printf("March ");
        break;
        case 4:
        printf("April ");
        break;
        case 5:
        printf("May");
        break;
        case 6:
        printf("June");
        break;
        case 7:
        printf("July");
        break;
        case 8:
        printf("August");
        break;
        case 9:
        printf("September");
        break;
        case 10:
        printf("October");
        break;
        case 11:
        printf("November");
        break;
        case 12:
        printf("December");
        break;
    }
}

void printYear(int year)
{
    printf(" %d\n", year);
}