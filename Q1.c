#include <stdio.h>
int main()
{
    typedef struct 
    {
        char name[20];
        char add[40];
        long long int phone;
        int num_employ;

    }
    company;

    company comp1;
    printf("Enter name of company: ");
    gets(comp1.name);
    printf("Enter address of company: ");
    gets(comp1.add);
    printf("Enter phone of company: ");
    scanf("%lld", &comp1.phone);
    printf("Enter no. of employees: ");
    scanf("%d", &comp1.num_employ);

    printf("%s %s %lld %d", comp1.name, comp1.add, comp1.phone, comp1.num_employ);



    
    return 0;
}


