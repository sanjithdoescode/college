#include <stdio.h>

// Recursive function to calculate factorial
// Using unsigned long long to handle potentially large factorial values
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive step: n! = n * (n-1)!
    else {
        // Check for negative input inside the function as well
        if (n < 0) {
           return 0; // Factorial is not defined for negative numbers
        }
        return (unsigned long long)n * factorial(n - 1);
    }
}

int main() {
    int num;
    unsigned long long fact;

    // Get input from the user
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if the number is negative
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        fact = factorial(num);
        // Check if factorial returned 0 due to negative input in recursion (shouldn't happen with initial check)
        // or potentially due to overflow wrapping around, though ULLONG_MAX is very large.
        if (fact == 0 && num > 1) {
             printf("Could not compute factorial (maybe input was negative or overflow occurred).\n");
        } else {
             printf("Factorial of %d = %llu\n", num, fact);
        }
    }

    return 0;
} 