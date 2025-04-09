#include <stdio.h>

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Print Pascal's Triangle
    for (int i = 0; i < rows; i++) {
        int number = 1;  // first number is always 1
        // Print leading spaces for alignment
        for (int s = 0; s < rows - i - 1; s++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%4d", number);
            number = number * (i - j) / (j + 1);
        }
        printf("\n");
    }
    return 0;
}
