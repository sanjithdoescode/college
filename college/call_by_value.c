#include <stdio.h>

// Function to demonstrate call by value
int square(int num) {
    // The parameter 'num' is a copy of the original value
    // Changes to 'num' do not affect the original variable
    num = num * num;
    printf("Inside function: num = %d\n", num);
    return num;
}

int main() {
    int x;
    
    // Get input from the user
    printf("Enter a number: ");
    scanf("%d", &x);
    
    printf("Before function call: x = %d\n", x);
    
    // Call the function by value
    // The value of x is passed, not its address
    int result = square(x);
    
    printf("After function call: x = %d\n", x);  // x remains unchanged
    printf("The square is: %d\n", result);
    
    return 0;
} 