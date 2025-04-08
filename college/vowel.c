#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a character is a vowel
bool isVowel(char ch) {
    // Convert to lowercase for case-insensitive comparison
    ch = tolower(ch);
    
    // Check if the character is a vowel
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char ch;
    
    // Get input from the user
    printf("Enter a character: ");
    scanf(" %c", &ch);  // Note the space before %c to skip any whitespace
    
    // Check if the character is a vowel
    if (isVowel(ch)) {
        printf("'%c' is a vowel.\n", ch);
    } else if (isalpha(ch)) {
        printf("'%c' is a consonant.\n", ch);
    } else {
        printf("'%c' is not an alphabet character.\n", ch);
    }
    
    return 0;
} 