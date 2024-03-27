#include <stdio.h>
int main()
{
    typedef struct 
    {
        char roll[20];
        char name[20];
        char add[40];
        int age;
        int avg_mks;
    }
    student;

    student stud[6];

    for(int i=0; i<6; i++)
    {
        printf("Enter details of student%d\n", i+1);
        printf("Enter roll number: ");
        gets(stud[i].roll);
        printf("Enter name: ");
        gets(stud[i].name);
        printf("Enter address: ");
        gets(stud[i].add);
        printf("Enter average marks: "); 
        scanf("%d", &stud[i].avg_mks);
        printf("Enter age: ");
        scanf("%d", &stud[i].age);
    } 
    return 0;

    for(int i=0; i<6; i++)
    printf("%s %s %s %d %d\n", stud[i].roll, stud[i].name, stud[i].add, stud[i].age, stud[i].avg_mks);
}

