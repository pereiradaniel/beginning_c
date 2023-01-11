// Compact for loop

// Perform calculation within the third control expression of a for loop.
//      for (unsigned int i = 1; i <= count; sum += i++);
// Third control expression uses postfix operator:
// The i is incremented after the sum is calculated!

#include <stdio.h>
#include <limits.h> // INT_MAX

int main(int argc, char* argv[])
{
    unsigned long long sum = 0;
    unsigned int count = 0;
    char choice = 'y';

    do
    {
        if (sum != 0) // Reset sum if looping
            sum = 0;

        do
        {
            printf("\nEnter a number from 1-%u: ", INT_MAX);
            scanf(" %u", &count);

            if (count == 0 || count > INT_MAX)
                printf("\nOut of bounds! Try again.");
        }
        while(count == 0 || count > INT_MAX);

        for (unsigned int i = 1; i <= count; sum += i++); // compact for loop

        printf("\nTotal of the first %u numbers is %llu", count, sum);

        printf("\nAgain? (y\\n)\n");
        scanf(" %c", &choice);
    }
    while(choice == 'y' || choice == 'Y');

    return 0;
}