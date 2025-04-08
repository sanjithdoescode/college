#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
    int i, j;
    
    // Get input for matrix A
    printf("Enter elements of first matrix (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    // Get input for matrix B
    printf("\nEnter elements of second matrix (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    // Subtract matrices A and B (A - B)
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
    // Display matrix A
    printf("\nMatrix A:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    
    // Display matrix B
    printf("\nMatrix B:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    
    // Display the result matrix C
    printf("\nResultant Matrix C (A - B):\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
} 