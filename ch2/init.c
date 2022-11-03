// init.c
// Daniele Grech Pereira, 02 November 2022

// Demonstration of variables before and after initialization.

#include <stdio.h>
#define LENGTH(a) sizeof(a) / sizeof(a[0])

void display(char* string, int array[], int size);

int main(int argc, char* argv[])
{
    int num[10] = {1,2,3,4,5,6,7,8,9,10}; // Simultaneously declare and initialize a variable.
    int num2[10]= {1,2,3};                // First three are specified, the rest set to 0.
    int num3[10]= {0};                    // Easy way to initialize all array values with 0.
    int arr[10];                          // Declare an array of ints without initializing.

    // Printing the uninitialized array int arr[] will display garbage and generate warnings
    // from valgrind.
    display("Printing int num[] which has been initialized with data:", num, LENGTH(num));
    display("Printing int num2[] which has been initialized with data:", num2, LENGTH(num2));
    display("Printing int num3[] which has been initialized with data:", num3, LENGTH(num3));
    display("Printing int arr[] which has not been initialized with data:", arr, LENGTH(arr));
    
    // Initialize int arr[]
    for (int i=0; i<LENGTH(arr);++i)
        arr[i] = LENGTH(arr) - i;
    
    display("Printing int arr[] after initialization:", arr, LENGTH(arr));

    return 0;
}

void display(char* string, int array[], int size)
{
    printf("%s\n\t", string);

    for (int i = 0; i < size; ++i)
    {
        printf("%d", array[i]);
        i == size-1 ? printf(".\n") : printf(", ");
    }

    printf("\n");
}
