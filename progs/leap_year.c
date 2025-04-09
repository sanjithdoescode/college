#include <stdio.h>

int main() {
    int year;

    // Get input from the user
    printf("Enter a year: ");
    scanf("%d", &year);

    // A leap year is divisible by 4
    // However, if it's divisible by 100, it's not a leap year
    // Unless it's also divisible by 400, then it is a leap year

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
} 