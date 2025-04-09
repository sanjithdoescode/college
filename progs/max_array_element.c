#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;
    int max;
    
    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Check if size is valid
    if (size <= 0) {
        printf("Please enter a positive size.\n");
        return 1;
    }
    
    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));
    
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Get array elements from the user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Find the maximum element
    max = arr[0];  // Assume first element is maximum
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Display the maximum element
    printf("The maximum element in the array is: %d\n", max);
    
    // Free the allocated memory
    free(arr);
    
    return 0;
} 