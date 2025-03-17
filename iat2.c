/**
 * Sorting Algorithms: Bubble Sort and Insertion Sort
 */

#include <stdio.h>

// Bubble Sort Implementation
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion Sort Implementation
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Sorting demonstration
void sortingDemo() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n);
    
    bubbleSort(arr1, n);
    printf("Array sorted using Bubble Sort: ");
    printArray(arr1, n);
    
    insertionSort(arr2, n);
    printf("Array sorted using Insertion Sort: ");
    printArray(arr2, n);
}

/**
 * Pointers: Reference and Dereference Operators
 */

void pointerDemo() {
    int num = 50;      // A variable
    int *ptr;          // Pointer declaration
    
    ptr = &num;        // Store address of num in pointer variable (reference)
    
    printf("\n--- Pointer Demonstration ---\n");
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value of ptr (address stored): %p\n", ptr);
    printf("Value at address ptr (dereferencing): %d\n", *ptr);
    
    // Changing value using dereference operator
    *ptr = 100;
    printf("After changing value using *ptr = 100:\n");
    printf("Value of num: %d\n", num);
    printf("Value at address ptr: %d\n", *ptr);
}

/**
 * Fibonacci Series using Recursion
 */

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void fibonacciDemo() {
    int n = 10;
    int i;
    
    printf("\n--- Fibonacci Series Demonstration ---\n");
    printf("Fibonacci Series up to %d terms: ", n);
    
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

/**
 * Factorial using Recursion
 */

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n-1);
}

void factorialDemo() {
    int n = 10;
    
    printf("\n--- Factorial Demonstration ---\n");
    printf("Factorial of %d = %llu\n", n, factorial(n));
}

/**
 * Main function to run all demonstrations
 */

int main() {
    printf("--- Sorting Algorithms ---\n");
    sortingDemo();
    
    pointerDemo();
    
    fibonacciDemo();
    
    factorialDemo();
    
    return 0;
}

/*--- Sorting Algorithms ---
Original array: 64 34 25 12 22 11 90
Array sorted using Bubble Sort: 11 12 22 25 34 64 90
Array sorted using Insertion Sort: 11 12 22 25 34 64 90

--- Pointer Demonstration ---
Value of num: 50
Address of num: 0x7ffee2d9a8c8
Value of ptr (address stored): 0x7ffee2d9a8c8
Value at address ptr (dereferencing): 50
After changing value using *ptr = 100:
Value of num: 100
Value at address ptr: 100

--- Fibonacci Series Demonstration ---
Fibonacci Series up to 10 terms: 0 1 1 2 3 5 8 13 21 34

--- Factorial Demonstration ---
Factorial of 10 = 3628800*/
