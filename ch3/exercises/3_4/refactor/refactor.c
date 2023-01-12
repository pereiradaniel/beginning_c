// Exercise 3-4
// Refactored
#include <stdio.h>
#include <ctype.h>

void calculator(double number1, double number2, char operation);

int main(void)
{
  double number1 = 0.0;  // First operand
  double number2 = 0.0;  // Second operand
  char operation = 0;    // Operation
  char choice = 'Y';     // Repeat calculation

  do {
    // Get calculation:
    printf("\nEnter the calculation\n");
    scanf("%lf %c %lf", &number1, &operation, &number2);

    // Calculate:
    calculator(number1, number2, operation);
    
    // Repeat?
    printf("\nEnter y to repeat or any key to quit: ");
    scanf(" %c", &choice);
  } while(toupper(choice) == 'Y');

  return 0;
}

void calculator(double number1, double number2, char operation)
{
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
};