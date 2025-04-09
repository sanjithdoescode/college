#include <stdio.h>

int main() {
    int n, pass = 0, fail = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    int marks[n];
    for (int i = 0; i < n; i++) {
        printf("Enter marks for student %d: ", i+1);
        scanf("%d", &marks[i]);
        if (marks[i] >= 40)
            pass++;
        else
            fail++;
    }
    printf("Number of students passed: %d\n", pass);
    printf("Number of students failed: %d\n", fail);
    return 0;
}
