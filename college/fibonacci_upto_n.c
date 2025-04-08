#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;

    // Get input from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check if the number of terms is valid
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; // Indicate error
    }

    printf("Fibonacci Series up to %d terms:\n", n);

    // Print the first two terms if needed
    if (n >= 1) {
        printf("%d, ", t1);
    }
    if (n >= 2) {
        printf("%d, ", t2);
    }

    // Use loop to generate and print the next terms
    for (int i = 3; i <= n; i++) {
        nextTerm = t1 + t2;
        printf("%d", nextTerm);
        
        // Print comma except for the last term
        if (i < n) {
            printf(", ");
        }
        
        // Update values for next iteration
        t1 = t2;
        t2 = nextTerm;
    }
    
    printf("\n");
    return 0;
} 