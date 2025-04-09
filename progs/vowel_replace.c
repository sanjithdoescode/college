#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[200];
    int seen[26] = {0};  // to record first occurrence of vowels
    printf("Enter a text: ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (tolower(ch) == 'a' || tolower(ch) == 'e' ||
            tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
            if (seen[tolower(ch) - 'a'] == 0)
                seen[tolower(ch) - 'a'] = 1;
            else
                str[i] = '$';
        }
    }
    printf("Modified text: %s\n", str);
    return 0;
}
