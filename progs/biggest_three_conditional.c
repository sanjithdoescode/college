#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    int biggest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("The biggest number is: %d\n", biggest);
    return 0;
}
