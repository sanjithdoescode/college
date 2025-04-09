#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    
    // Get input from the user
    printf("Enter a string: ");
    // Using fgets to safely read a string with spaces
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from fgets if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    
    printf("Original string: %s\n", str);
    
    // Convert string to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    
    printf("Uppercase string: %s\n", str);
    
    return 0;
} 