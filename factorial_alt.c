#include <stdio.h>

// Recursive function to calculate factorial
unsigned long factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int num;
    
    // Get input from the user
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    // Check if the input is valid
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
    
    // Calculate and display the factorial
    printf("Factorial of %d = %lu\n", num, factorial(num));
    
    return 0;
} 