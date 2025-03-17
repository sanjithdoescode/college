#include <stdio.h>

int main() {
    // Declare a regular integer variable
    int number = 42;
    
    // Declare a pointer and use the reference operator (&) 
    // to store the address of 'number'
    int* ptr = &number;
    
    // Print the value of 'number'
    printf("Value of number: %d\n", number);
    
    // Print the address of 'number' using the reference operator
    printf("Address of number: %p\n", &number);
    
    // Print what's stored in the pointer (the address)
    printf("Value stored in ptr: %p\n", ptr);
    
    // Use the dereference operator (*) to access the value at that address
    printf("Value pointed to by ptr: %d\n", *ptr);
    
    // Modify the value through the pointer using dereference
    *ptr = 99;
    
    // The original variable is changed
    printf("New value of number: %d\n", number);
    
    return 0;
}
