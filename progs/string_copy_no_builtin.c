#include <stdio.h>

int main() {
    char src[100], dest[100];
    int i;
    printf("Enter a string: ");
    scanf(" %99[^\n]", src);
    // Manual string copy without built-in functions
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    printf("Copied string: %s\n", dest);
    return 0;
}
