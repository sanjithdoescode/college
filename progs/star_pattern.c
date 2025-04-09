#include <stdio.h>

int main() {
    int rows;

    // Get input from the user
    printf("Enter the number of rows for the star pattern: ");
    scanf("%d", &rows);

    // Check if the number of rows is positive
    if (rows <= 0) {
        printf("Please enter a positive number of rows.\n");
        return 1; // Indicate error
    }

    printf("Star Pattern:\n");

    // Upper half of the pattern (increasing stars)
    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the pattern (decreasing stars)
    for (int i = rows - 1; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
} 