#include <stdio.h>

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    // Base cases
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Recursive call to calculate Fibonacci number
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    
    // Get input from the user
    printf("Enter the term number to find in Fibonacci series: ");
    scanf("%d", &n);
    
    // Check if the input is valid
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        // Calculate and display the Fibonacci number
        printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
        
        // Optionally, print the series up to n terms
        printf("Fibonacci series up to term %d:\n", n);
        for (int i = 0; i <= n; i++) {
            printf("%d", fibonacci(i));
            if (i < n) {
                printf(", ");
            }
        }
        printf("\n");
        
        // Note: this recursive implementation is inefficient for large values of n
        // due to repeated calculations in the recursive calls
    }
    
    return 0;
} 