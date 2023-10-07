/* Program 4.7 A Guessing Game */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int chosen = 15; /* The lucky number */
    int guess = 0; /* Stores a guess */
    int count = 3; /* The maximum number of tries */
    
    char play_again = 'Y'; // Loops game

    printf("\nThis is a guessing game.");
    printf("\nI have chosen a number between 1 and 20 which you must guess.\n");
 
    do
    {
        if (count != 3) // check if game needs to be reset 
        {
            // reset counters
            guess = 0;
            count = 3;
        }

        for( ; count>0 ; --count)
        {
            printf("\nYou have %d tr%s left.", count, count == 1 ? "y" : "ies");
            printf("\nEnter a guess: "); /* Prompt for a guess */
            scanf(" %d", &guess); /* Read in a guess */
        
            /* Check for a correct guess */
            if(guess == chosen)
                count = 0; //  Answer is correct, break for loop to end game.
            
            /* Check for an invalid guess */
            if(guess<1 || guess > 20)
                printf("I said between 1 and 20.\n ");
            else
                printf("Sorry. %d is wrong.\n", guess);
        }

        // Check result        
        if (guess == chosen)
            printf("\nYou guessed it!\n");
        else
            printf("\nYou have had three tries and failed. The number was %d\n",chosen);
            
        // Ask for new game:
        printf("\nPlay again? (y/n) ");
        scanf(" %c", &play_again);

    } while (toupper(play_again) == 'Y');
    
    
 
    return 0;
}