// Exercise 3-4

// Modify the last example in the chapter that implemented a calculator so
// that the user is given the option to enter y or Y to carry out another calculation, and n or
// N to end the program. (Note: You’ll have to use a goto statement for this here, but you’ll
// learn a better way of doing this in the next chapter.)

#include <stdio.h>
#include <ctype.h> // Modification: toupper(choice)

int main(void)
{
  double number1 = 0.0;  // First operand
  double number2 = 0.0;  // Second operand
  char operation = 0;    // Operation

start:
    printf("\nEnter the calculation\n");
    scanf("%lf %c %lf", &number1, &operation, &number2);

  switch(operation)
  {
    case '+':
      printf("= %lf\n", number1 + number2);
      break;

    case '-':
      printf("= %lf\n", number1 - number2);
      break;

    case '*':
      printf("= %lf\n", number1 * number2);
      break;                              

    case '/':
    // Check for division by zero!!!
      if(number2 == 0)
        printf("\n\n\aDivision by zero error!\n");
      else
        printf("= %lf\n", number1 / number2);
      break;

    case '%':
    // Check for division by zero!!!
      if((long)number2 == 0) 
         printf("\n\n\aDivision by zero error!\n");
      else
        printf("= %ld\n", (long)number1 % (long)number2);
      break;

    // Catch invalid operations
    default:
      printf("\n\n\aIllegal operation!\n");
      break;
  }

  // MODIFICATION!!!
  char choice = 'n';

  printf("\nEnter y to repeat or any key to quit: ");
  scanf(" %c", &choice);

  if(toupper(choice) == 'Y')
    goto start;

  return 0;
}
