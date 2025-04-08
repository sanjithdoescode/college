#include <stdio.h>

int main() {
    int num1, num2, num3;
    int largest;

    // Get input from the user
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Method 1: Using if-else statements
    if (num1 >= num2 && num1 >= num3) {
        largest = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        largest = num2;
    } else {
        largest = num3;
    }
    
    printf("The largest number is: %d\n", largest);

    // Method 2 (alternative): Using conditional operator
    // largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
    // printf("Using ternary: The largest number is: %d\n", largest);

    return 0;
} 