#include <stdio.h>

    typedef struct 
    {
        int day;
        int month;
        int year;
    }
    date;


    int compare(date dates[])
    {
        if(dates[0].year > dates[1].year)
        {
            return 1;
        }
        else if (dates[0].year < dates[1].year)
        {
            return -1;
        }
        else
        {
            if(dates[0].month > dates[1].month)
            {
                return 1;
            }
            else if (dates[0].month < dates[1].month)
            {
                return -1;
            }
            else
            {
                if(dates[0].day > dates[1].day)
                {
                    return 1;
                }
                else if (dates[0].day < dates[1].day)
                {
                    return -1;
                }
                else
                {
                    return 0;
                }

            }
        }
    }

int main()
{
    date dates[2];

    for(int i=0; i<2; i++)
    {
        printf("Enter details for date%i\n", i+1);
        printf("Enter day, month and year: ");
        scanf("%d %d %d", &dates[i].day, &dates[i].month, &dates[i].year);
    }
    int check = compare(dates);
    printf("%d", check);
    return 0;
}