#include <stdio.h>

int main() {
    int a, b;

    // Get input from the user
    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swapping logic without a temporary variable using arithmetic operators
    // Be cautious about potential integer overflow if a + b is very large
    a = a + b;
    b = a - b; // b becomes the original value of a
    a = a - b; // a becomes the original value of b

    /* Alternative using bitwise XOR (often preferred as it avoids overflow issues):
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    */

    printf("After swapping:  a = %d, b = %d\n", a, b);

    return 0;
} 