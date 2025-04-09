#include <stdio.h>

int main() {
    int num, first, last, sum;
    
    // Get input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // Check if the number is positive
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Get the last digit
    last = num % 10;
    
    // Get the first digit by repeatedly dividing by 10
    first = num;
    while (first >= 10) {
        first /= 10;
    }
    
    // Calculate the sum
    sum = first + last;
    
    printf("The first digit: %d\n", first);
    printf("The last digit: %d\n", last);
    printf("Sum of first and last digit: %d\n", sum);
    
    return 0;
} 