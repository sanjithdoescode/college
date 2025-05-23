#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num))
        printf("%d is prime.\n", num);
    else
        printf("%d is not prime.\n", num);
    return 0;
}
