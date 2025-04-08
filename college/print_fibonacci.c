#include <stdio.h>

// We already have separate files for Fibonacci series (both recursive and iterative)
// This is another version of the iterative implementation
void printFibonacciSeries(int n) {
    int a = 0, b = 1, c, i;
    
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }
    
    if (n == 1) {
        printf("Fibonacci series up to 1 term: %d\n", a);
        return;
    }
    
    printf("Fibonacci series up to %d terms: ", n);
    printf("%d, %d", a, b);
    
    for (i = 3; i <= n; i++) {
        c = a + b;
        printf(", %d", c);
        a = b;
        b = c;
    }
    
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printFibonacciSeries(n);
    
    return 0;
} 