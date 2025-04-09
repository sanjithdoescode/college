#include <stdio.h>

// Function to search for an element in an array
// Returns the index if found, -1 otherwise
int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;  // Element not found
}

int main() {
    int size, i, element, result;
    
    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Check if the size is valid
    if (size <= 0) {
        printf("Please enter a positive size.\n");
        return 1;
    }
    
    int arr[size];  // Declare an array of the given size
    
    // Get array elements from the user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Get the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &element);
    
    // Search for the element
    result = linearSearch(arr, size, element);
    
    // Display the result
    if (result == -1) {
        printf("Element %d not found in the array.\n", element);
    } else {
        printf("Element %d found at index %d (position %d).\n", element, result, result+1);
    }
    
    return 0;
} 