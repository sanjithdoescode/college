#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num == 0)
        printf("Number is zero.\n");
    else if (num % 2 == 0)
        printf("Even number.\n");
    else
        printf("Odd number.\n");
    return 0;
}
