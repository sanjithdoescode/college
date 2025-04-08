#include <stdio.h>

int main() {
    int a, b, c;
    int smallest;
    
    // Get input from the user
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // Method 1: Using if-else statements
    if (a <= b && a <= c) {
        smallest = a;
    } else if (b <= a && b <= c) {
        smallest = b;
    } else {
        smallest = c;
    }
    
    printf("The smallest number is: %d\n", smallest);
    
    // Method 2 (alternative): Using conditional operator
    // smallest = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
    // printf("Using ternary: The smallest number is: %d\n", smallest);
    
    return 0;
} 