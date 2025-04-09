#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double a, b, result;
    printf("Scientific Calculator\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a + b;
            printf("Result = %.2lf\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a - b;
            printf("Result = %.2lf\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a * b;
            printf("Result = %.2lf\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            if (b == 0)
                printf("Division by zero error.\n");
            else {
                result = a / b;
                printf("Result = %.2lf\n", result);
            }
            break;
        case 5:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &a, &b);
            result = pow(a, b);
            printf("Result = %.2lf\n", result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &a);
            if (a < 0)
                printf("Invalid input for square root.\n");
            else {
                result = sqrt(a);
                printf("Result = %.2lf\n", result);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
