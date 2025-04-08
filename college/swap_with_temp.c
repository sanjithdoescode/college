#include <stdio.h>

int main() {
    int a, b, temp;

    // Get input from the user
    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swapping logic using a temporary variable
    temp = a;
    a = b;
    b = temp;

    printf("After swapping:  a = %d, b = %d\n", a, b);

    return 0;
} 