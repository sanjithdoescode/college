#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information [1-3]
struct Student {
    char name[4];
    int rollNo;
    int m1, m2, m3;
    int total;
    float average;
};

int main() {
    struct Student students[5];
    FILE *fptr;
    int i;

    // Open a file in write mode [6]
    fptr = fopen("student_details.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1; // Indicate an error
    }

    // Read student information for 10 students using a for loop [7, 8]
    printf("Enter information for 10 students:\n");
    for (i = 0; i < 10; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter Name: ");
        // Clear input buffer [part of standard C practice, not explicitly in sources]
        while (getchar() != '\n');
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove trailing newline

        printf("Enter Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter marks for subject 1: ");
        scanf("%d", &students[i].m1);

        printf("Enter marks for subject 2: ");
        scanf("%d", &students[i].m2);

        printf("Enter marks for subject 3: ");
        scanf("%d", &students[i].m3);

        // Calculate total and average [based on user request]
        students[i].total = students[i].m1 + students[i].m2 + students[i].m3;
        students[i].average = (float)students[i].total / 3.0;

        // Write student details to the file using fprintf() [9, 10]
        fprintf(fptr, "Name: %s\n", students[i].name);
        fprintf(fptr, "Roll No: %d\n", students[i].rollNo);
        fprintf(fptr, "Marks (m1, m2, m3): %d, %d, %d\n", students[i].m1, students[i].m2, students[i].m3);
        fprintf(fptr, "Total Marks: %d\n", students[i].total);
        fprintf(fptr, "Average Marks: %.2f\n", students[i].average);
        fprintf(fptr, "\n"); // Add a separator for readability in the file
    }

    // Close the file using fclose() [9]
    fclose(fptr);

    printf("\nStudent details have been successfully written to 'student_details.txt'\n");

    return 0; // Indicate successful execution
}

/*
Explanation:
1.
Structure Definition:
◦
A struct Student is defined to group the information for each student together. It includes members for name (a character array), rollNo (integer), marks for three subjects (m1, m2, m3 as integers), total marks (integer), and average marks (float).
2.
File Handling:
◦
A file pointer fptr of type FILE* is declared. This pointer will be used to interact with the file.
◦
The fopen() function is used to open a file named "student_details.txt" in write mode ("w").
▪
If the file does not exist, it will be created.
▪
If the file exists, its contents will be overwritten.
▪
If fopen() fails to open the file (e.g., due to permission issues), it returns NULL. The program checks for this and exits with an error message if necessary.
◦
The fclose() function is used at the end of the program to close the file. It's important to close the file to ensure that all data is written to the disk and to release the resources associated with the file.
3.
Reading Student Information:
◦
A for loop iterates 10 times to collect the details for each student.
◦
Inside the loop, the program prompts the user to enter the name, roll number, and marks for three subjects using printf() and reads the input using fgets() for the name (to handle spaces) and scanf() for the integer inputs.
◦
Input Buffer Handling: while (getchar() != '\n'); is used to clear the input buffer before reading the name using fgets(). This is a common practice in C to avoid issues where leftover newline characters from previous scanf() calls can interfere with subsequent fgets() reads [not explicitly mentioned in the sources, but a standard C programming technique].
◦
students[i].name[strcspn(students[i].name, "\n")] = 0; removes the trailing newline character that fgets() might include in the string [part of standard C string handling, not explicitly in sources].
4.
Calculating Total and Average:
◦
For each student, the total marks are calculated by summing m1, m2, and m3.
◦
The average is calculated by dividing the total by 3.0 (using a float literal 3.0 to ensure floating-point division).
5.
Writing to File:
◦
The fprintf() function is used to write the student's details into the opened file.
◦
fprintf() works similarly to printf(), but it takes an additional first argument, which is the file pointer (fptr), indicating the file where the output should be written.
◦
The format specifiers (%s, %d, %.2f) are used to write the data in a readable format to the file.
6.
Output to Console:
◦
The program also uses printf() to display messages to the user, indicating the progress and completion of the task.
This program effectively demonstrates file handling concepts in C to read, process, and store structured student data into a file.

*/
