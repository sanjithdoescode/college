#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is perfect
bool isPerfectNumber(int num) {
    int sum = 0;
    
    // Check if the number is positive
    if (num <= 0) {
        return false;
    }
    
    // Find the sum of all proper divisors
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    // Check if the sum equals the original number
    return (sum == num);
}

int main() {
    int num;
    
    // Get input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // Check if the number is perfect
    if (isPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }
    
    return 0;
} 