#include <stdio.h>

typedef struct 
{
    char street[100];
    char city[100];
    char zipCode[20];
} 
Address;

typedef struct 
{
    char name[100];
    Address address;
} 
Person;

int main() 
{
    Person person;
    printf("Enter person's name: ");
    scanf("%s", person.name);
    printf("Enter street: ");
    scanf("%s", person.address.street);
    printf("Enter city: ");
    scanf("%s", person.address.city);
    printf("Enter zip code: ");
    scanf("%s", person.address.zipCode);

    printf("Name: %s\n", person.name);
    printf("Address: %s, %s, %s\n", person.address.street, person.address.city, person.address.zipCode);

    return 0;
}
