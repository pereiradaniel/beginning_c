// Compact for loop

// Perform calculation within the third control expression of a for loop.

#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int sum = 0, count = 0;
    char choice = 'y';

    do {
        do {
            printf("\nEnter a number from 1-100: ");
            scanf(" %d", &sum);

            if (sum == 0 || sum > 100)
                printf("\nOut of bounds! Try again.\n");
        } while(sum == 0 || sum > 100);

        for (unsigned int i = 1; i <= count; sum += i++);

        printf("\nTotal of the first %u numbers is %u\n", count, sum);

        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');
    


    return 0;
}