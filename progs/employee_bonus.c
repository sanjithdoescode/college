#include <stdio.h>

int main() {
    float salary, bonus;
    int years;
    printf("Enter your current salary: ");
    scanf("%f", &salary);
    printf("Enter years of service: ");
    scanf("%d", &years);
    // Bonus calculation: 10% if years are 5 or more, else 5%
    bonus = (years >= 5) ? salary * 0.10 : salary * 0.05;
    printf("Your bonus is: %.2f\n", bonus);
    return 0;
}
