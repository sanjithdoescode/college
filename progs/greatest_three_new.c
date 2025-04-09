#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int largest = a;
    if (b > largest)
        largest = b;
    if (c > largest)
        largest = c;
    printf("The greatest number is: %d\n", largest);
    return 0;
}
