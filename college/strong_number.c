#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to check if a number is strong
bool isStrong(int num) {
    int originalNum = num;
    int sum = 0;
    
    // Calculate sum of factorials of digits
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    
    // Check if sum equals the original number
    return sum == originalNum;
}

int main() {
    int num;
    
    // Get input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // Check if the number is positive
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Check if the number is strong
    if (isStrong(num)) {
        printf("%d is a strong number.\n", num);
    } else {
        printf("%d is not a strong number.\n", num);
    }
    
    // Optional: Explain what a strong number is
    printf("\nNote: A strong number is a number where the sum of the\n"
           "factorials of its digits equals the original number.\n"
           "For example, 145 is strong because 1! + 4! + 5! = 1 + 24 + 120 = 145.\n");
    
    return 0;
} 