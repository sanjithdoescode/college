#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    // Check if num is less than or equal to 1
    if (num <= 1) {
        return false;
    }
    
    // Check if num is 2 or 3
    if (num == 2 || num == 3) {
        return true;
    }
    
    // Check if num is divisible by 2 or 3
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    // Check for divisibility using the 6k ± 1 rule for numbers > 3
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
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
    
    // Check if the number is prime
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    
    return 0;
} 