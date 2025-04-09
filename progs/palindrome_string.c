#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a string is palindrome
bool isPalindrome(char str[]) {
    int length = strlen(str);
    int i, j;
    
    // Convert to lowercase for case-insensitive comparison
    for (i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
    
    // Compare characters from beginning and end
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char str[100];
    
    // Get input from the user
    printf("Enter a string: ");
    scanf("%99s", str);  // Limiting input to avoid buffer overflow
    
    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    
    return 0;
} 