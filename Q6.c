#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 100

typedef struct
{
    char name[50];
    int rollNumber;
    float percentage;
} 
StudentRecord;

StudentRecord database[MAX_RECORDS];
int num_rec = 0;

void insert(char name[], int rollNumber, float percentage) 
{
    if (num_rec < MAX_RECORDS) 
    {
        int i;
        for (i = num_rec-1; i >= 0 && database[i].rollNumber > rollNumber; i--) 
        {
            database[i + 1] = database[i]; 
        }
        strcpy(database[i + 1].name, name);
        database[i + 1].rollNumber = rollNumber;
        database[i + 1].percentage = percentage;
        num_rec++; 
    } 
    else 
    {
        printf("Cannot insert.\n");
    }
}

void sortName() 
{
    StudentRecord temp;
    for (int i = 0; i < num_rec - 1; i++) 
    {
        for (int j = 0; j < num_rec - i - 1; j++) {
            if (strcmp(database[j].name, database[j + 1].name) > 0) 
            {
                temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
}

char* findOne(char inp[]) 
{
    int len = strlen(inp);
    for (int i = 0; i < num_rec; i++) 
    {
        if (strncmp(database[i].name, inp, len) == 0) 
        {
            return database[i].name;
        }
    }
    return "Not found";
}


float* specs() 
{
    static float stats[5];
    float sum = 0, mean, var = 0;
    float highest = database[0].percentage;
    float lowest = database[0].percentage;


    for (int i = 0; i < num_rec; i++) 
    {
        sum += database[i].percentage;
        if (database[i].percentage > highest) 
        {
            highest = database[i].percentage;
        }
        if (database[i].percentage < lowest) 
        {
            lowest = database[i].percentage;
        }
    }

    mean = sum / num_rec;

    for (int i = 0; i < num_rec; i++) {
        var += pow(database[i].percentage - mean, 2);
    }
    var /= num_rec;

    float std_dev = sqrt(var);

    stats[0] = num_rec;
    stats[1] = highest;
    stats[2] = lowest;
    stats[3] = mean;
    stats[4] = std_dev;

    return stats;
}


void delete(int rollNumber) 
{
    int i, found = 0;
    for (i = 0; i < num_rec; i++) 
    {
        if (database[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }
    if (found) 
    {
        for (; i < num_rec - 1; i++) 
        {
            database[i] = database[i + 1];
        }
        num_rec--;
    } 
    else 
    {
        printf("roll number not found.\n");
    }
}

int main() 
{
    insert("A", 2, 85.5);
    insert("C", 1, 75.8);
    insert("B", 3, 96.2);

    printf("Initial Database:\n");
    for (int i = 0; i < num_rec; i++) 
    {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].rollNumber, database[i].percentage);
    }

    sortName();
    printf("\nDatabase sorted by name:\n");
    for (int i = 0; i < num_rec; i++) 
    {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].rollNumber, database[i].percentage);
    }

    printf("\nRecord starting with 'A': %s\n", findOne("A"));

    float* stats = specs();
    printf("\nDatabase stats:\n");
    printf("Number of records: %.0f\n", stats[0]);
    printf("Highest percentage: %.2f\n", stats[1]);
    printf("Lowest percentage: %.2f\n", stats[2]);
    printf("Mean: %.2f\n", stats[3]);
    printf("Standard deviation: %.2f\n", stats[4]);

    delete(2);

    printf("\nAfter deleting roll number 2:\n");
    for (int i = 0; i < num_rec; i++) 
    {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].rollNumber, database[i].percentage);
    }

    return 0;
}
