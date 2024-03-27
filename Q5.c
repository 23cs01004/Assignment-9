#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
    char firstName[50];
    char lastName[50];
    int rollNumber;
    char department[50];
    char courseCode[20];
    int testMarks[3];
} 
CourseRecord;

float average(CourseRecord record)
{
    float totalMarks = 0;
    for (int i = 0; i < 3; i++) {
        totalMarks += record.testMarks[i];
    }
    return totalMarks / 3;
}

bool hasPassed(CourseRecord record) 
{
    return (average(record) >= 35);
}

int main() 
{
    CourseRecord student;
    printf("Enter student's first name: ");
    scanf("%s", student.firstName);
    printf("Enter student's last name: ");
    scanf("%s", student.lastName);
    printf("Enter student's roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter student's department: ");
    scanf("%s", student.department);
    printf("Enter course code: ");
    scanf("%s", student.courseCode);
    printf("Enter test marks for three tests: ");
    for (int i = 0; i < 3; i++) 
    {
        scanf("%d", &student.testMarks[i]);
    }
    printf("Average test marks: %.2f\n", average(student));

    if (hasPassed(student)) 
    {
        printf("Student has passed.\n");
    } 
    else 
    {
        printf("Student has failed.\n");
    }
    return 0;
}
