# EXERCISES

---

The following exercises enable you to try out what you’ve learned in this chapter. If you get stuck, look back over
the chapter for help. If you’re still stuck, you can download the solutions from the Source Code/Downloads section
of the Apress web site (http://www.apress.com), but that really should be a last resort.

*Exercise 4-1* Write a program that will generate a multiplication table of a size entered
by the user. A table of size 4, for instance, would have four rows and four columns. The
rows and columns would be labeled from 1 to 4. Each cell in the table will contain the
product of the corresponding row and column numbers, so the value in the position
corresponding to the third row and the fourth column would contain 12.

*Exercise 4-2* Write a program that will output the printable characters for character
code values from 0 to 127. Output each character code along with its symbol with two
characters to a line. Make sure the columns are aligned. (Hint: You can use the isgraph()
function that’s declared in ctype.h to determine when a character is printable.)

*Exercise 4-3* Extend the previous program to output the appropriate name, such as
“newline”, “space”, “tab”, and so on, for each whitespace character.

*Exercise 4-4* Modify Program 4.13 to determine the random digits by selecting a digit
based on where the number returned by rand() lies within the entire range of possible
values.

*Exercise 4-5* Modify the Simon Says game implemented in Program 4.7A so that the
program will continue with an option to play another game when the player fails to guess
the number correctly and will allow as many games as the player requires.
