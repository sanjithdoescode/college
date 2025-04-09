#include <stdio.h>
#include <string.h>

// Define a structure for company details
struct Company {
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    int employees;
    float revenue;
};

int main() {
    // Declare a variable of type Company structure
    struct Company myCompany;
    
    // Get input from the user
    printf("Enter company details:\n");
    
    printf("Company Name: ");
    scanf("%49s", myCompany.name);  // Limiting input to avoid buffer overflow
    
    printf("Address: ");
    getchar();  // Clear input buffer
    scanf("%99[^\n]", myCompany.address);  // Read until newline
    
    printf("Phone Number: ");
    getchar();  // Clear input buffer
    scanf("%14s", myCompany.phone);
    
    printf("Email: ");
    scanf("%49s", myCompany.email);
    
    printf("Number of Employees: ");
    scanf("%d", &myCompany.employees);
    
    printf("Annual Revenue (in millions): ");
    scanf("%f", &myCompany.revenue);
    
    // Display the company details
    printf("\nCompany Details:\n");
    printf("Name: %s\n", myCompany.name);
    printf("Address: %s\n", myCompany.address);
    printf("Phone: %s\n", myCompany.phone);
    printf("Email: %s\n", myCompany.email);
    printf("Employees: %d\n", myCompany.employees);
    printf("Revenue: %.2f million\n", myCompany.revenue);
    
    return 0;
} 