/* Dynamic memory allocation is the process of allocating memory during the execution of a program, or at runtime. This is in contrast to static memory allocation, where the memory for variables is determined at compile time.
Need for Dynamic Memory Allocation Static memory allocation can lead to inefficiencies:
•
If the number of values to be stored is less than the allocated memory size, it results in memory wastage.
•
If more memory is needed during program execution than initially allocated, the program might fail.
Dynamic memory allocation provides flexibility by allowing you to allocate memory only when it's needed and to adjust the amount of memory during the program's run.
Dynamic Memory Allocation Functions C provides several standard library functions for dynamic memory allocation:
•
malloc(): Allocates a block of memory of the specified size in bytes. It returns a void pointer to the beginning of the allocated memory block.
•
calloc(): Allocates memory for an array of elements of a specified size and initializes all bytes in the allocated memory to zero.
•
realloc(): Changes the size of a previously allocated memory block.
•
free(): Deallocates the dynamically allocated memory, making it available for future use.
Demonstration with malloc() Example Let's consider an example where we want to dynamically allocate memory to store a user-defined number of integers and then calculate their average.
*/

#include <stdio.h>
#include <stdlib.h> // For malloc, free, exit

int main() {
    int n, i, *arr, sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' integers using malloc()
    arr = (int*) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1); // Indicate an abnormal termination
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / n;
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    // Release the dynamically allocated memory using free()
    free(arr);
    arr = NULL; // Good practice to set the pointer to NULL after freeing

    return 0; // Indicate successful execution
}
/*
  
Explanation:
1.
We include the stdlib.h header file, which contains the declarations for dynamic memory allocation functions like malloc() and free().
2.
We prompt the user to enter the number of elements they want to store and read this value into the variable n.
3.
We use malloc(n * sizeof(int)) to allocate enough memory to store n integer values. sizeof(int) gives the size of an integer in bytes, and we multiply it by n to get the total number of bytes needed. The (int*) is a type cast that converts the void pointer returned by malloc() to an integer pointer (int*).
4.
We check if malloc() returned NULL. If it did, it means that memory allocation failed (possibly due to insufficient memory), and we print an error message and exit the program.
5.
If memory allocation is successful, we proceed to read the n elements from the user and store them in the dynamically allocated array pointed to by arr. We also calculate the sum of these elements.
6.
We calculate the average.
7.
Crucially, after we are finished using the dynamically allocated memory, we call free(arr) to release the memory back to the system. This prevents memory leaks, which can occur if dynamically allocated memory is not freed.
8.
Setting arr = NULL after freeing is a good practice to prevent accidental access to the freed memory.
This example demonstrates how malloc() is used to allocate memory at runtime based on user input, allowing for more flexible and efficient memory management compared to static allocation. Remember to always free() the dynamically allocated memory when it is no longer needed to avoid memory leaks

*/
