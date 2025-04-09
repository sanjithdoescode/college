#include <stdio.h>

struct MarkSheet {
    char studentName[50];
    char course[50];
    int marks;
    char grade;
};

int main() {
    struct MarkSheet ms;
    printf("Enter student name: ");
    scanf(" %49[^\n]", ms.studentName);
    printf("Enter course: ");
    scanf(" %49[^\n]", ms.course);
    printf("Enter marks: ");
    scanf("%d", &ms.marks);

    if (ms.marks >= 90)
        ms.grade = 'A';
    else if (ms.marks >= 80)
        ms.grade = 'B';
    else if (ms.marks >= 70)
        ms.grade = 'C';
    else if (ms.marks >= 60)
        ms.grade = 'D';
    else
        ms.grade = 'F';

    printf("\nMarksheet:\n");
    printf("Student: %s\nCourse: %s\nMarks: %d\nGrade: %c\n", 
           ms.studentName, ms.course, ms.marks, ms.grade);
    return 0;
}
