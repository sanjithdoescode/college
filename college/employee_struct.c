#include <stdio.h>
#include <string.h>

// Define structure for employee
struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
    int experience;
};

int main() {
    // Declare an array of 5 employee structures
    struct Employee employees[5];
    
    printf("Enter details of 5 employees:\n");
    
    // Get input for each employee
    for (int i = 0; i < 5; i++) {
        printf("\nEnter details for Employee %d:\n", i+1);
        
        // Get employee ID
        printf("ID: ");
        scanf("%d", &employees[i].id);
        
        // Get employee name (using space to clear input buffer)
        printf("Name: ");
        scanf(" %49[^\n]", employees[i].name);
        
        // Get employee designation
        printf("Designation: ");
        scanf(" %49[^\n]", employees[i].designation);
        
        // Get employee salary
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        
        // Get employee experience in years
        printf("Experience (years): ");
        scanf("%d", &employees[i].experience);
    }
    
    // Display all employee details
    printf("\nEmployee Information:\n");
    printf("-------------------------------------------\n");
    printf("ID\tName\t\tDesignation\tSalary\t\tExperience\n");
    printf("-------------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\t\t%d\n", 
               employees[i].id, 
               employees[i].name, 
               employees[i].designation, 
               employees[i].salary, 
               employees[i].experience);
    }
    
    return 0;
} 