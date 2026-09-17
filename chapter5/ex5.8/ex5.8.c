#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *day);

int main()
{
    int month, day;

    printf("Testing day_of_year:\n");

    printf("2024, 2, 29 -> %d\n", day_of_year(2024, 2, 29));
    printf("2023, 2, 28 -> %d\n", day_of_year(2023, 2, 28));
    printf("2024, 13, 1 -> %d\n", day_of_year(2024, 13, 1));
    printf("2024, 2, 30 -> %d\n", day_of_year(2024, 2, 30));

    printf("\nTesting month_day:\n");

    month_day(2024, 60, &month, &day);
    printf("2024, day 60 -> %d/%d\n", month, day);

    month_day(2023, 365, &month, &day);
    printf("2023, day 365 -> %d/%d\n", month, day);

    month_day(2024, 366, &month, &day);
    printf("2024, day 366 -> %d/%d\n", month, day);

    month_day(2024, 367, &month, &day);
    printf("2024, day 367 -> %d/%d\n", month, day);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    // validate input
    if (year < 0 || year > 9999)
    {
	printf("Year cannot be before 0 or after 9999\n");
	return -1;
    }

    if (month < 1 || month > 12)
    {
	printf("Month cannot exceed 12 or be below 1\n");
	return -1;
    }
    
    // find if leap year
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0;
    for (i = 1; i <= month; i++)
    day += daytab[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 0 || year > 9999)
    {
	printf("Year cannot be before 0 or after 9999\n");
	*pmonth = -1;
	*pday = -1;
	return;
    }

    if (yearday < 0 || yearday > 365)
    {
	printf("Yearday cannot be below 0 or above 365\n");
	*pday = -1;
	*pmonth = -1;
	return;
    }
    
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}


    
    
