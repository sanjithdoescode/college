#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    // Check if n is less than or equal to 1
    if (num <= 1) {
        return false;
    }
    
    // Check if n is 2 or 3
    if (num == 2 || num == 3) {
        return true;
    }
    
    // Check if n is divisible by 2 or 3
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
    printf("Prime numbers from 1 to 100:\n");
    
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d", i);
            count++;
            
            // Format output with commas and newlines for readability
            if (i < 100) {
                printf(", ");
            }
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }
    
    printf("\n");
    return 0;
} 