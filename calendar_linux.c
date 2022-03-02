#include <stdio.h>
#include "conio.h"

#define TRUE 1

//defining month days
int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//defining month names
char *months[] = {"January", "Febrauary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//defining all the other required variables
int year, startingDay, daysinMonth, weekDay, month, gmonth, day, input;

//gets first day of the week
int get_firstWeekday(int year, int gmonth)
{
    int d;
    //algorithm to find the first week day of the year
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    // then finding the first week day of the months
    if ((year % 4 == 0 && year % 100 != 0) && year % 400 != 0)
    {
        if (gmonth == 1)
        {
            d = d;
        }
        if (gmonth == 2)
        {
            d = (d + 31) % 7;
        }
        if (gmonth == 3)
        {
            d = (d + 60) % 7;
        }
        if (gmonth == 4)
        {
            d = (d + 91) % 7;
        }
        if (gmonth == 5)
        {
            d = (d + 121) % 7;
        }
        if (gmonth == 6)
        {
            d = (d + 152) % 7;
        }
        if (gmonth == 7)
        {
            d = (d + 182) % 7;
        }
        if (gmonth == 8)
        {
            d = (d + 213) % 7;
        }
        if (gmonth == 9)
        {
            d = (d + 244) % 7;
        }
        if (gmonth == 10)
        {
            d = (d + 274) % 7;
        }
        if (gmonth == 11)
        {
            d = (d + 305) % 7;
        }
        if (gmonth == 12)
        {
            d = (d + 335) % 7;
        }
    }
    else
    {
        if (gmonth == 1)
        {
            d = d;
        }
        if (gmonth == 2)
        {
            d = (d + 31) % 7;
        }
        if (gmonth == 3)
        {
            d = (d + 59) % 7;
        }
        if (gmonth == 4)
        {
            d = (d + 90) % 7;
        }
        if (gmonth == 5)
        {
            d = (d + 120) % 7;
        }
        if (gmonth == 6)
        {
            d = (d + 151) % 7;
        }
        if (gmonth == 7)
        {
            d = (d + 181) % 7;
        }
        if (gmonth == 8)
        {
            d = (d + 212) % 7;
        }
        if (gmonth == 9)
        {
            d = (d + 243) % 7;
        }
        if (gmonth == 10)
        {
            d = (d + 273) % 7;
        }
        if (gmonth == 11)
        {
            d = (d + 304) % 7;
        }
        if (gmonth == 12)
        {
            d = (d + 334) % 7;
        }
    }
    return d;
}

// check it the given year is leap year or not
void check_leap()
{
    if ((year % 4 == 0 && year % 100 != 0) && year % 400 != 0)
            {
               monthDays[1] = 29;
            }
}

//print the calendar
void print_cal()
{
     for (month = 0; month < 12; month++)
            {
                daysinMonth = monthDays[month];
                if (month == gmonth - 1)
                {
                    printf("\n\n---------------%s %d-------------------\n", months[month], year);
                    printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");
                    //print white space for the week days that are skipped in the start of the month
                    for (weekDay = 0; weekDay < startingDay; weekDay++)
                        printf("     ");
                    //start printing days
                    for (day = 1; day <= daysinMonth; day++)
                    {
                        printf("%5d", day);
                        //continue printing on the new line after a week is over
                        if (++weekDay > 6)
                        {
                            printf("\n");
                            weekDay = 0;
                        }
                    }
                    startingDay = weekDay;
                }
            }
}

int main()
{

    while (TRUE)
    {
        //ask for the input of month and year from user
        printf("\nEnter month and year (mm/yy): ");
        scanf("%d/%d", &gmonth, &year);
        //check if the input is valid or not
        if (year < 0)
        {
            printf("\nInvalid year....");
            continue;
        }
        if (year < 100)
        {
            year = 1800 + year;
        }
        if (gmonth < 1 || gmonth > 12)
        {
            printf("\nInvalid month.....");
            continue;
        }
        break;
    }

    //print the calendar for specified month and year
    check_leap();
    startingDay = get_firstWeekday(year, gmonth);
    print_cal();
    printf("\n\n\tpress h for help\n");
    //start while loop to keep running the program
    while (TRUE)
    {
        printf("\n");
        // ask for response and display the calendar of previous or next month/year or x to exit program
        input = getch();
        if (input == 'w' || input == 'W')
        {
            gmonth = gmonth - 1;
            if (gmonth < 1)
            {
                gmonth += 12;
                year -= 1;
            }
            check_leap();
            startingDay = get_firstWeekday(year, gmonth);
            month = 0;
            printf("\n\nPast Month");
            print_cal();
        }
        if (input == 's' || input == 'S')
        {
            gmonth = gmonth + 1;
            if (gmonth > 12)
            {
                gmonth -= 12;
                year += 1;
            }
            check_leap();
            startingDay = get_firstWeekday(year, gmonth);
            month = 0;
            printf("\n\nNext Month");
            print_cal();
        }
        if (input == 'a' || input == 'A')
        {
            year = year - 1;
            check_leap();
            startingDay = get_firstWeekday(year, gmonth);
            month = 0;
            printf("\n\nPast Year");
            print_cal();
        }
        if (input == 'd' || input == 'D')
        {
            year = year + 1;
            check_leap();
            startingDay = get_firstWeekday(year, gmonth);
            month = 0;
            printf("\n\nNext Year");
            print_cal();
           
        }
        if (input == 'h' || input == 'H')
        {
            printf("\na - to view calendar for previous year and same month");
            printf("\nd - to view calendar for next year and same month");
            printf("\nw - to view calendar for previous month and same year");
            printf("\ns - to view calendar for next month and same year");
            printf("\nx - to exit program");
        }
        if (input == 'x' || input == 'X')
        {
            printf("\n\n-------------Good Bye!-----------------\n");
            break;
        }
    }
}
