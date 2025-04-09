#include <stdio.h>

void swapByRef(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swapByRef(&x, &y);
    printf("After swapping by reference: x = %d, y = %d\n", x, y);
    // Demonstrate call by value does not swap (no effect)
    int a = x, b = y;
    printf("Call by value does not swap: a = %d, b = %d\n", a, b);
    return 0;
}
