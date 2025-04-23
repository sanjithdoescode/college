#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a union to store different types of academic information
union AcademicInfo {
    int marks[1]; // To store marks for 3 subjects
    char grade;    // To store a single grade
};

// Define the structure for Student details
struct Student {
    char name[2];
    int id;
    union AcademicInfo academic;
    int infoType; // To indicate whether academic info is marks (0) or grade (1)
};

int main() {
    int numStudents, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Declare an array of Student structures
    struct Student students[numStudents];

    // Input details for each student
    printf("\nEnter student details:\n");
    for (i = 0; i < numStudents; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter Name: ");
        // Clear the input buffer
        while (getchar() != '\n');
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove trailing newline

        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        printf("Enter type of academic info (0 for marks, 1 for grade): ");
        scanf("%d", &students[i].infoType);

        if (students[i].infoType == 0) {
            printf("Enter marks for 3 subjects: ");
            for (j = 0; j < 3; j++) {
                scanf("%d", &students[i].academic.marks[j]);
            }
        } else if (students[i].infoType == 1) {
            printf("Enter grade: ");
            scanf(" %c", &students[i].academic.grade); // Note the space before %c to consume newline
        } else {
            printf("Invalid academic info type.\n");
            // You might want to handle this error more robustly in a real application
        }
    }

    // Display the entered student details
    printf("\n--- Student Database ---\n");
    for (i = 0; i < numStudents; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        if (students[i].infoType == 0) {
            printf("Marks: %d, %d, %d\n", students[i].academic.marks, students[i].academic.marks[3], students[i].academic.marks[4]);
        } else if (students[i].infoType == 1) {
            printf("Grade: %c\n", students[i].academic.grade);
        } else {
            printf("Academic Info: Not Available\n");
        }
    }

    return 0;
}
