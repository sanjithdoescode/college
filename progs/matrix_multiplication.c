#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS] = {0};
    printf("Enter elements for matrix A (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements for matrix B (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &B[i][j]);

    // Matrix Multiplication: C = A * B
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            for (int k = 0; k < COLS; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
