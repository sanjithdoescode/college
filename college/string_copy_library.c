#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    
    // Get input from the user
    printf("Enter a string: ");
    scanf("%99s", str1);  // Limiting input to avoid buffer overflow
    
    // Copy str1 to str2 using strcpy
    strcpy(str2, str1);
    
    printf("Original string (str1): %s\n", str1);
    printf("Copied string (str2): %s\n", str2);
    
    return 0;
} 