#include <stdio.h>

int main() {
    int marks[5], sum = 0;
    printf("Enter marks for 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    float average = sum / 5.0;
    printf("Total marks = %d, Average = %.2f\n", sum, average);
    return 0;
}
