#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // printf("lessgo\n");
    char timeformat[15];
    // printf("we can do this");
    //  struct stat fileStat;
    char *month_names[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *month_name;

    if (argc < 2)
    {
        printf("Incorrect format");
        exit(1);
    }

    else if (argc == 2)
    {

        struct stat fileStat;
        if (stat(argv[1], &fileStat) == -1)
        {
            printf("Error file doesnt exist");
            return 1;
        }
        time_t modifiedtime = fileStat.st_mtime;

        // Extract year, month, day, hour, minute, and second
        struct tm *tm_info = localtime(&modifiedtime);
        int year = tm_info->tm_year + 1900;
        int month = tm_info->tm_mon + 1;
        int day = tm_info->tm_mday;
        int hour = tm_info->tm_hour;
        int minute = tm_info->tm_min;
        int second = tm_info->tm_sec;

        // Format the day of the week
        char day_str[20];
        switch (tm_info->tm_wday)
        {
        case 0:
            strcpy(day_str, "Sun");
            break;
        case 1:
            strcpy(day_str, "Mon");
            break;
        case 2:
            strcpy(day_str, "Tues");
            break;
        case 3:
            strcpy(day_str, "Wed");
            break;
        case 4:
            strcpy(day_str, "Thurs");
            break;
        case 5:
            strcpy(day_str, "Fri");
            break;
        case 6:
            strcpy(day_str, "Sat");
            break;
        default:
            strcpy(day_str, "Unknown");
            break;
        }

        if (hour >= 12)
        {
            strcpy(timeformat, "PM");
            if (hour > 12)
            {
                hour -= 12;
            }
        }
        else
        {
            strcpy(timeformat, "AM");
            if (hour == 0)
            {
                hour = 12;
                // strcpy(timeformat,"AM");
            }
        }

        month_name = month_names[month - 1];
        printf(" %s, %02d %s %02d:%02d:%02d %s IST 2023\n",
               day_str, day, month_name, hour, minute, second, timeformat);
    }

    else if (strcmp(argv[1], "-d") == 0 && argc == 4)
    {

        struct stat fileStat;

        if (stat(argv[3], &fileStat) == -1)
        {
            printf("Error file doesnt exist");
            return 1;
        }
        time_t modifiedtime = fileStat.st_mtime;

        // Extract year, month, day, hour, minute, and second
        struct tm *tm_info = localtime(&modifiedtime);
        int year = tm_info->tm_year + 1900;
        int month = tm_info->tm_mon + 1;
        int day = tm_info->tm_mday;
        int hour = tm_info->tm_hour;
        int minute = tm_info->tm_min;
        int second = tm_info->tm_sec;

        // Format the day of the week
        char day_str[20];
        switch (tm_info->tm_wday)
        {
        case 0:
            strcpy(day_str, "Sun");
            break;
        case 1:
            strcpy(day_str, "Mon");
            break;
        case 2:
            strcpy(day_str, "Tues");
            break;
        case 3:
            strcpy(day_str, "Wed");
            break;
        case 4:
            strcpy(day_str, "Thurs");
            break;
        case 5:
            strcpy(day_str, "Fri");
            break;
        case 6:
            strcpy(day_str, "Sat");
            break;
        default:
            strcpy(day_str, "Unknown");
            break;
        }
        month_name = month_names[month - 1];
        char tmt[10];
        if (strcmp(argv[2], "yesterday") == 0)
        {
            day -= 1;

            if (hour > 12)
            {
                strcpy(tmt, "PM");
                hour -= 12;
            }
            else
            {
                strcpy(tmt, "AM");
            }

            printf(" %s, %02d %s %04d %02d:%02d:%02d %s %s IST 2023\n",
                   day_str, day, month_name, year, hour, minute, second, timeformat, tmt);
        }

        else if (strcmp(argv[2], "tomorrow") == 0)
        {
            day += 1;
            printf(" %s, %02d %s %04d %02d:%02d:%02d %s IST 2023\n",
                   day_str, day, month_name, year, hour, minute, second, timeformat);
        }
    }

    else if (strcmp(argv[1], "-R") == 0 && argc == 3)
    {

        struct stat fileStat;

        if (stat(argv[2], &fileStat) == -1)
        {
            printf("Error file doesnt exist");
            return 1;
        }
        time_t modifiedtime = fileStat.st_mtime;

        // Extract year, month, day, hour, minute, and second
        struct tm *tm_info = localtime(&modifiedtime);
        int year = tm_info->tm_year + 1900;
        int month = tm_info->tm_mon + 1;
        int day = tm_info->tm_mday;
        int hour = tm_info->tm_hour;
        int minute = tm_info->tm_min;
        int second = tm_info->tm_sec;

        // Format the day of the week
        char day_str[20];
        switch (tm_info->tm_wday)
        {
        case 0:
            strcpy(day_str, "Sun");
            break;
        case 1:
            strcpy(day_str, "Mon");
            break;
        case 2:
            strcpy(day_str, "Tues");
            break;
        case 3:
            strcpy(day_str, "Wed");
            break;
        case 4:
            strcpy(day_str, "Thurs");
            break;
        case 5:
            strcpy(day_str, "Fri");
            break;
        case 6:
            strcpy(day_str, "Sat");
            break;
        default:
            strcpy(day_str, "Unknown");
            break;
        }
        month_name = month_names[month - 1];

        printf(" %s, %02d %s %04d %02d:%02d:%02d +0530\n",
               day_str, day, month_name, year, hour, minute, second);
        // Format and print the output
    }
    else
    {
        printf("Error : The command is incorrect");
    }

    return 0;
}
