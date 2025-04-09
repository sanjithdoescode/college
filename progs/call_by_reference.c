#include <stdio.h>

// Function to calculate the sum of squares
void calculateSum(int num, int *result) {
    // Pass by reference: modify the value at the memory location pointed by result
    *result = 0;
    for (int i = 1; i <= num; i++) {
        *result += i * i;
    }
}

int main() {
    int num, sum = 0;
    
    // Get input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // Check if the input is valid
    if (num < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Call the function with a reference to sum
    calculateSum(num, &sum);
    
    printf("Sum of squares from 1 to %d = %d\n", num, sum);
    
    return 0;
} 