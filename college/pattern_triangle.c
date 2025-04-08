#include <stdio.h>

int main() {
    int rows;

    // Get the number of rows for the pattern
    printf("Enter the number of rows for the triangle pattern: ");
    scanf("%d", &rows);

    // Check if the number of rows is positive
    if (rows <= 0) {
        printf("Please enter a positive number of rows.\n");
        return 1; // Indicate error
    }

    printf("Triangle Pattern:\n");

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop for printing stars in each row
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Move to the next line after each row
        printf("\n");
    }

    return 0;
} 