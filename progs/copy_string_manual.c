#include <stdio.h>
#include <string.h>

int main() {
    char source[100], dest[100];
    
    // Get input from the user
    printf("Enter a string: ");
    scanf("%99[^\n]", source);  // Read until newline
    
    // Copy string character by character
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';  // Add null terminator
    
    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", dest);
    
    return 0;
} 