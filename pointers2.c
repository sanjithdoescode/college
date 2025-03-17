#include <stdio.h>

// Call by value function
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue: a = %d, b = %d\n", a, b);
}

// Call by reference function using pointers
void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference: a = %d, b = %d\n", *a, *b);
}

// Function that uses a double pointer
void modifyPointer(int **doublePtr, int *newPtr) {
    *doublePtr = newPtr; // Changes where the original pointer points to
}

int main() {
    printf("------ BASIC POINTER DEMONSTRATION ------\n");
    
    int num = 10;
    int *ptr = &num;        // Pointer to num
    int **doublePtr = &ptr; // Double pointer (pointer to pointer)
    
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr (address of num): %p\n", ptr);
    printf("Value pointed by ptr (*ptr): %d\n", *ptr);
    printf("Address of ptr: %p\n", &ptr);
    printf("Value of doublePtr (address of ptr): %p\n", doublePtr);
    printf("Value pointed by doublePtr (*doublePtr): %p\n", *doublePtr);
    printf("Value pointed by value pointed by doublePtr (**doublePtr): %d\n\n", **doublePtr);
    
    // Changing value using pointer
    *ptr = 20;      
    printf("After *ptr = 20, num = %d\n", num);
              
    // Changing value using double pointer
    **doublePtr = 30;
    printf("After **doublePtr = 30, num = %d\n\n", num);
    
    printf("------ CALL BY VALUE vs CALL BY REFERENCE ------\n");
    
    int x = 5, y = 10;
    printf("Before swapByValue: x = %d, y = %d\n", x, y);
    swapByValue(x, y);
    printf("After swapByValue: x = %d, y = %d (no change)\n\n", x, y);
    
    printf("Before swapByReference: x = %d, y = %d\n", x, y);
    swapByReference(&x, &y);
    printf("After swapByReference: x = %d, y = %d (values swapped)\n\n", x, y);
    
    printf("------ DOUBLE POINTER USAGE ------\n");
    
    int var1 = 100;
    int var2 = 200;
    int *ptrVar = &var1;
    
    printf("Before modifyPointer: *ptrVar = %d (points to var1)\n", *ptrVar);
    modifyPointer(&ptrVar, &var2);
    printf("After modifyPointer: *ptrVar = %d (now points to var2)\n", *ptrVar);
    
    return 0;
}
