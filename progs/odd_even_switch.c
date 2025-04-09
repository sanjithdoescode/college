#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    switch(num) {
        case 0:
            printf("Number is zero.\n");
            break;
        default:
            switch(num % 2) {
                case 0:
                    printf("Even number.\n");
                    break;
                case 1:
                case -1:
                    printf("Odd number.\n");
                    break;
            }
    }
    return 0;
}
