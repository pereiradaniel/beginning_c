// Exercise 4-1
// Write a program that will generate a multiplication table of a size entered
// by the user.
#include <stdio.h>
#define TABLE_MAX 10

int queryUser(int table_size);
void printTable(int table_size);
void printRow(int row, int col);
void printLine(int table_size);

int main(int argc, char* argv[])
{
    int table_size = -1; // Set to -1 for loop

    // Get user input
    while (table_size < 0 || table_size > TABLE_MAX)
        table_size = queryUser(table_size);
    
    printTable(table_size);

    printf("\n");
    return 0;
}

int queryUser(int table_size)
{
        printf("\nEnter size for multiplication table between 1 and %d: ", TABLE_MAX);
        scanf(" %d", &table_size);

        // Validate user input
        if (table_size > TABLE_MAX || table_size < 1)
            printf("\n%d is out of bounds! Choose a number between 1 and %d!", table_size, TABLE_MAX);
        else
            printf("\nInput is ok. Calculating...");
        
        return table_size;
}

void printTable(int table_size)
{
    for (int row = 0; row <= table_size; ++row)
    {
        printf("\n"); // Begin new row

        // Print columns
        for (int col = 0; col <= table_size; ++col)
            printRow(row, col); // Print row
        
        if (row == 0)
            printLine(table_size);

    }
};

void printRow(int row, int col)
{
    if (row == 0)                       // Detect if first row
    {
        if (col == 0)                   // Detect if first column
            printf("    ");             // Print blank space
        else
            printf("|%4d", col);        // Print column header
    }
    else                                // Not first row
    {
        if (col == 0)                   // Detect if first column
            printf("%4d", row);         // Print row label
        else
            printf("|%4d", row*col);    // Print table entry
    }
};

void printLine(int table_size)
{
    printf("\n");
    for (int col = 0; col < table_size + 1; ++col)
        printf("-----");
};