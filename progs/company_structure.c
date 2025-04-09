#include <stdio.h>
#include <string.h>

struct Company {
    char name[50];
    char address[100];
    char phone[15];
    int employees;
};

int main() {
    struct Company comp;
    printf("Enter Company Name: ");
    scanf(" %49[^\n]", comp.name);
    printf("Enter Address: ");
    scanf(" %99[^\n]", comp.address);
    printf("Enter Phone Number: ");
    scanf(" %14s", comp.phone);
    printf("Enter Number of Employees: ");
    scanf("%d", &comp.employees);
    printf("\nCompany Details:\n");
    printf("Name: %s\nAddress: %s\nPhone: %s\nEmployees: %d\n",
           comp.name, comp.address, comp.phone, comp.employees);
    return 0;
}
