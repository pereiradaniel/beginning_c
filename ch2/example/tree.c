// Program 2.17 Calculating the height of a tree
// Page 79

#include <stdio.h> // include stdio.h for scanf and printf.
#define INCHES(a) a=feet*inches_per_foot+inches // Convert feet to inches.
// #define TREE_HEIGHT(a) a=shorty + (shorty_to_lofty + lofty_to_tree)*(lofty-shorty)/(shorty_to_lofty)

int main(int argc, char* argv[])
{
    long shorty = 0L;           // Height of Shorty.
    long lofty = 0L;            // Height of Lofty.
    long feet = 0L;             // Temp. storage for getting input.
    long inches = 0L;           // Temp. storage for getting input.
    long shorty_to_lofty = 0L;  // Distance between two people INCHES.
    long lofty_to_tree = 0L;    // Distance from Lofty to tree INCHES.
    long tree_height = 0L;      // Stores height of the tree.

    const long inches_per_foot = 12L;

    // Get Lofty's height:
    printf("Enter Lofty's height (measured to top of head).\nFeet: ");
    scanf(" %ld", &feet);
    printf("Inches: ");
    scanf(" %ld", &inches);
    
    // Store Lofty's height in inches:
    INCHES(lofty);

    // Get Shorty's height:
    printf("Enter Shorty's height (measured to eyes).\nFeet: ");
    scanf(" %ld", &feet);
    printf("Inches: ");
    scanf(" %ld", &inches);

    // Store Shorty's height in inches:
    INCHES(shorty);

    // Get the distance from Shorty to Lofty:
    printf("Enter the distance from Shorty to Lofty.\nFeet: ");
    scanf(" %ld", &feet);
    printf("Inches: ");
    scanf(" %ld", &inches);

    // Store distance from Shorty to Lofty in inches:
    INCHES(shorty_to_lofty);

    // Get the distance from Lofty to the tree:
    printf("Enter the distance from Lofty to the tree to the nearest foot: ");
    scanf(" %ld", &feet);
    inches = 0; // Set inches to 0

    // Store distance from Lofty to tree in inches:
    INCHES(lofty_to_tree);

    // Calculate the height of the tree in inches:
    // TREE_HEIGHT(tree_height);
    tree_height = shorty + (shorty_to_lofty + lofty_to_tree)*(lofty-shorty)/(shorty_to_lofty);

    // DISPLAY THE RESULT!
    printf("The height of the tree is %ld feet and %ld inches.\n", tree_height/inches_per_foot, tree_height% inches_per_foot);
    
    return 0;
}