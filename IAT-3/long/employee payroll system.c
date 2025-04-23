
/*
An array of structures is a data structure where each element of an array is a structure. It allows you to store a collection of related data items (as defined by the structure) under a single array name. This is particularly useful when you need to manage a list of records, where each record has multiple fields of potentially different data types. According to the sources, when a database of any element is used in a huge amount, we often prefer an array of structures. Each element of the array is of the structure type.
For example, if you want to maintain a database of 200 students, you can use an array of structures where each element in the array is a student structure containing members like name, branch, and roll number. The elements of the structure are stored in contiguous memory locations.
Here's a C program that demonstrates the concept of an array of structures and can serve as a starting point for an Employee Payroll System:
*/

#include <stdio.h>
#include <string.h>

// Define the structure for Employee information
struct Employee {
    char name;
    int employeeId;
    float basicSalary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float taxRate;      // Tax deduction rate
    float grossSalary;
    float netSalary;
};

int main() {
    int numEmployees, i;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    // Declare an array of Employee structures
    struct Employee employees[numEmployees];

    // Input employee details
    printf("\nEnter employee details:\n");
    for (i = 0; i < numEmployees; i++) {
        printf("\n--- Employee %d ---\n", i + 1);

        printf("Enter Name: ");
        while (getchar() != '\n'); // Clear input buffer
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;

        printf("Enter Employee ID: ");
        scanf("%d", &employees[i].employeeId);

        printf("Enter Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);

        printf("Enter HRA: ");
        scanf("%f", &employees[i].hra);

        printf("Enter DA: ");
        scanf("%f", &employees[i].da);

        printf("Enter Tax Rate (as a decimal, e.g., 0.10 for 10%): ");
        scanf("%f", &employees[i].taxRate);

        // Calculate Gross Salary
        employees[i].grossSalary = employees[i].basicSalary + employees[i].hra + employees[i].da;

        // Calculate Net Salary
        float taxAmount = employees[i].grossSalary * employees[i].taxRate;
        employees[i].netSalary = employees[i].grossSalary - taxAmount;
    }

    // Display Employee Payroll Information
    printf("\n--- Employee Payroll System ---\n");
    for (i = 0; i < numEmployees; i++) {
        printf("\n--- Employee %d ---\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].employeeId);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("HRA: %.2f\n", employees[i].hra);
        printf("DA: %.2f\n", employees[i].da);
        printf("Gross Salary: %.2f\n", employees[i].grossSalary);
        printf("Tax Rate: %.2f\n", employees[i].taxRate);
        printf("Net Salary: %.2f\n", employees[i].netSalary);
    }

    return 0;
}

/*
Explanation of the Payroll System Program:
1.
Structure Definition (struct Employee): A structure named Employee is defined to hold information for each employee. It includes members for name, employeeId, basicSalary, hra (House Rent Allowance), da (Dearness Allowance), taxRate, grossSalary, and netSalary.
2.
Array of Structures (struct Employee employees[numEmployees]): An array named employees is declared, where each element is of type struct Employee. The size of the array is determined by the user-input numEmployees, allowing you to store payroll information for multiple employees. This is an example of an array of structures.
3.
Inputting Employee Details: The program prompts the user to enter the number of employees and then iterates through each employee to collect their personal and salary-related details.
4.
Calculating Gross and Net Salary:
◦
The grossSalary is calculated by adding the basicSalary, hra, and da.
◦
The taxAmount is calculated based on the grossSalary and the taxRate.
◦
The netSalary is then calculated by subtracting the taxAmount from the grossSalary.
5.
Displaying Payroll Information: The program iterates through the employees array and displays the entered details along with the calculated grossSalary and netSalary for each employee.
This program provides a basic framework for an Employee Payroll System using an array of structures. You can further enhance this system by adding more features like reading and writing data to files, including more detailed deduction categories, and implementing more complex payroll rules.
*/
