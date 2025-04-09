#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
    printf("Enter elements for matrix A (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements for matrix B (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &B[i][j]);

    // Matrix Addition
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Resultant matrix (A+B):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
