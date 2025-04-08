#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to calculate the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to check if a number is Armstrong
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int n = countDigits(num);
    
    // Calculate sum of nth power of its digits
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, n);
        num /= 10;
    }
    
    // Check if the sum equals the original number
    return (sum == originalNum);
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
    
    // Check if the number is Armstrong
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    
    // Optional: Explain what an Armstrong number is
    printf("\nNote: An Armstrong number (or narcissistic number) is a number\n"
           "that is equal to the sum of the nth powers of its digits,\n"
           "where n is the number of digits.\n"
           "For example, 153 is an Armstrong number because 1^3 + 5^3 + 3^3 = 153.\n");
    
    return 0;
} 