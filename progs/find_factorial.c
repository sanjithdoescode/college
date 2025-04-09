#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    
    // Check if the number is negative
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1;
    }
    
    // Calculate factorial using iteration
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int num;
    
    // Get input from the user
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    // Check if the input is valid
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    
    // Calculate factorial
    int fact = factorial(num);
    
    // Display the result
    if (fact != -1) {  // Check if factorial calculation was successful
        printf("Factorial of %d = %d\n", num, fact);
    }
    
    return 0;
} 