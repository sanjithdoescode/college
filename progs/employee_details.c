#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    char rank[20];
    float salary;
};

int main() {
    struct Employee emp[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf(" %49[^\n]", emp[i].name);
        printf("Rank: ");
        scanf(" %19s", emp[i].rank);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Name: %s, Rank: %s, Salary: %.2f\n", 
               emp[i].id, emp[i].name, emp[i].rank, emp[i].salary);
    }
    return 0;
}
