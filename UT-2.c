/* 1. String operations without using built-in functions */

#include <stdio.h>

// Function to find string length
int stringLength(char str[]) {
    int length = 0;
    
    // Count until we reach null character
    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}

// Function to copy one string to another
void stringCopy(char source[], char destination[]) {
    int i = 0;
    
    // Copy each character until null character
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    
    // Add null terminator
    destination[i] = '\0';
}

// Function to concatenate two strings
void stringConcatenate(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;
    
    // Copy first string to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    
    // Append second string to result
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    
    // Add null terminator
    result[i] = '\0';
}

// Function to compare two strings
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    
    // Compare characters one by one
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    
    // Check if strings are of different lengths
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;  // Strings are equal
    } else if (str1[i] == '\0') {
        return -1; // str1 is shorter
    } else {
        return 1;  // str1 is longer
    }
}

void stringOperationsDemo() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char copy[50];
    char concat[100];
    
    printf("String Operations Without Built-in Functions:\n");
    printf("---------------------------------------------\n");
    
    // Length
    printf("Length of \"%s\": %d\n", str1, stringLength(str1));
    
    // Copy
    stringCopy(str1, copy);
    printf("Copy of \"%s\": \"%s\"\n", str1, copy);
    
    // Concatenate
    stringConcatenate(str1, str2, concat);
    printf("Concatenation of \"%s\" and \"%s\": \"%s\"\n", str1, str2, concat);
    
    // Compare
    int compareResult = stringCompare(str1, str2);
    printf("Comparison of \"%s\" and \"%s\": %d\n", str1, str2, compareResult);
    printf("---------------------------------------------\n\n");
}

/* 2. Pointers - Call by Value and Call by Reference */

// Call by value example
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // Changes are local to this function only
}

// Call by reference example
void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    // Changes affect original variables
}

void pointerDemo() {
    int x = 10, y = 20;
    
    printf("Pointers: Call by Value vs Call by Reference:\n");
    printf("---------------------------------------------\n");
    
    printf("Initial values: x = %d, y = %d\n", x, y);
    
    // Call by value
    swapByValue(x, y);
    printf("After swapByValue: x = %d, y = %d (No change)\n", x, y);
    
    // Call by reference
    swapByReference(&x, &y);
    printf("After swapByReference: x = %d, y = %d (Swapped)\n", x, y);
    printf("---------------------------------------------\n\n");
}

/* 3. Binary Search using Recursive Function */

int binarySearchRecursive(int arr[], int left, int right, int key) {
    // Base case: element not found
    if (left > right) {
        return -1;
    }
    
    // Find middle index
    int mid = left + (right - left) / 2;
    
    // Check if key is at middle
    if (arr[mid] == key) {
        return mid;
    }
    
    // If key is smaller than middle element, search left half
    if (arr[mid] > key) {
        return binarySearchRecursive(arr, left, mid - 1, key);
    }
    
    // If key is larger than middle element, search right half
    return binarySearchRecursive(arr, mid + 1, right, key);
}

void binarySearchRecursiveDemo() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = 10;
    int key = 23;
    
    printf("Binary Search using Recursion:\n");
    printf("---------------------------------------------\n");
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int result = binarySearchRecursive(arr, 0, size - 1, key);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    printf("---------------------------------------------\n\n");
}

/* 4. Linear and Binary Search (Iterative versions) */

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return index if element found
        }
    }
    return -1;  // Return -1 if element not found
}

int binarySearchIterative(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        // Find middle index
        int mid = left + (right - left) / 2;
        
        // Check if key is at middle
        if (arr[mid] == key) {
            return mid;
        }
        
        // If key is smaller than middle element, search left half
        if (arr[mid] > key) {
            right = mid - 1;
        }
        // If key is larger than middle element, search right half
        else {
            left = mid + 1;
        }
    }
    
    return -1;  // Return -1 if element not found
}

void searchComparisonDemo() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = 10;
    int key = 23;
    
    printf("Linear and Binary Search Comparison:\n");
    printf("---------------------------------------------\n");
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Linear search
    int linearResult = linearSearch(arr, size, key);
    if (linearResult != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, linearResult);
    } else {
        printf("Linear Search: Element %d not found in the array\n", key);
    }
    
    // Binary search (iterative)
    int binaryResult = binarySearchIterative(arr, size, key);
    if (binaryResult != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, binaryResult);
    } else {
        printf("Binary Search: Element %d not found in the array\n", key);
    }
    printf("---------------------------------------------\n\n");
}

/* 5. Linear Search using Recursion */

int linearSearchRecursive(int arr[], int size, int key, int index) {
    // Base case: element not found
    if (index >= size) {
        return -1;
    }
    
    // Check if current element is the key
    if (arr[index] == key) {
        return index;
    }
    
    // Recursively check the rest of the array
    return linearSearchRecursive(arr, size, key, index + 1);
}

void linearSearchRecursiveDemo() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = 10;
    int key = 23;
    
    printf("Linear Search using Recursion:\n");
    printf("---------------------------------------------\n");
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int result = linearSearchRecursive(arr, size, key, 0);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    printf("---------------------------------------------\n\n");
}

/* Main function to run all demos */

int main() {
    // Run all the demos
    stringOperationsDemo();
    pointerDemo();
    binarySearchRecursiveDemo();
    searchComparisonDemo();
    linearSearchRecursiveDemo();
    
    return 0;
}
/*
Sample Output:

String Operations Without Built-in Functions:
---------------------------------------------
Length of "Hello": 5
Copy of "Hello": "Hello"
Concatenation of "Hello" and "World": "HelloWorld"
Comparison of "Hello" and "World": -15
---------------------------------------------

Pointers: Call by Value vs Call by Reference:
---------------------------------------------
Initial values: x = 10, y = 20
After swapByValue: x = 10, y = 20 (No change)
After swapByReference: x = 20, y = 10 (Swapped)
---------------------------------------------

Binary Search using Recursion:
---------------------------------------------
Array: 2 5 8 12 16 23 38 56 72 91
Element 23 found at index 5
---------------------------------------------

Linear and Binary Search Comparison:
---------------------------------------------
Array: 2 5 8 12 16 23 38 56 72 91
Linear Search: Element 23 found at index 5
Binary Search: Element 23 found at index 5
---------------------------------------------

Linear Search using Recursion:
---------------------------------------------
Array: 2 5 8 12 16 23 38 56 72 91
Element 23 found at index 5
---------------------------------------------
*/