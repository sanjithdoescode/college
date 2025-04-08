#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
    char department[50];
};

int main() {
    // Declare an array of 5 student structures
    struct Student students[5];
    
    printf("Enter details of 5 students:\n");
    
    // Get input for each student
    for (int i = 0; i < 5; i++) {
        printf("\nEnter details for Student %d:\n", i+1);
        
        // Get student ID
        printf("ID: ");
        scanf("%d", &students[i].id);
        
        // Get student name
        printf("Name: ");
        scanf(" %49[^\n]", students[i].name);
        
        // Get student age
        printf("Age: ");
        scanf("%d", &students[i].age);
        
        // Get student GPA
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
        
        // Get student department
        printf("Department: ");
        scanf(" %49[^\n]", students[i].department);
    }
    
    // Display all student details
    printf("\nStudent Details:\n");
    printf("-------------------------------------\n");
    printf("ID\tName\t\tAge\tGPA\tDepartment\n");
    printf("-------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%d\t%s\t\t%d\t%.2f\t%s\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].gpa, 
               students[i].department);
    }
    
    return 0;
} 