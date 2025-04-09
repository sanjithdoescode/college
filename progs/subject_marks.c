#include <stdio.h>

int main() {
    int marks[5], sum = 0;
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    printf("Total marks = %d\n", sum);
    return 0;
}
