# EXERCISES

The following exercises enable you to try out what you’ve learned in this chapter. If you get stuck, look back
over the chapter for help. If you’re still stuck, you can download the solutions from the Source Code/Download
area of the Apress web site [http://www.apress.com], but that really should be a last resort.

## Exercise 3-1

Write a program that will first allow a user to choose one of two options:

    1. Convert a temperature from degrees Celsius to degrees Fahrenheit.
    2. Convert a temperature from degrees Fahrenheit to degrees Celsius.

The program should then prompt for the temperature value to be entered and output the new value that results
from the conversion. To convert from Celsius to Fahrenheit you can multiply the value by 1.8 and then add 32.

To convert from Fahrenheit to Celsius, you can subtract 32 from the value, then multiply by 5, and divide the
result by 9.

## Exercise 3-2

Write a program that prompts the user to enter the date as three integer
values for the month, the day in the month, and the year. The program should then output
the date in the form 31st December 2003 when the user enters 12 31 2003, for example.

You will need to work out when th, nd, st, and rd need to be appended to the day value. Don’t forget 1st, 2nd, 3rd,
4th; but 11th, 12th, 13th, 14th; and 21st, 22nd, 23rd, and 24th.

## Exercise 3-3

Write a program that will calculate the price for a quantity entered from
the keyboard, given that the unit price is $5 and there is a discount of 10 percent for
quantities over 30 and a 15 percent discount for quantities over 50.

## Exercise 3-4

Modify the last example in the chapter that implemented a calculator so
that the user is given the option to enter y or Y to carry out another calculation, and n or
N to end the program. (Note: You’ll have to use a goto statement for this here, but you’ll
learn a better way of doing this in the next chapter.)
