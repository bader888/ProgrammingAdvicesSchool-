#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

string MonthShortName(short MonthOrder)
{
    string MonthName[] = {"Jan",
                          "Feb",
                          "Mar",
                          "Apr",
                          "May",
                          "Jun",
                          "Jul",
                          "Aug",
                          "Sep",
                          "Oct",
                          "Nov",
                          "Dec"};
    return MonthName[MonthOrder - 1];
}

void PrintDaysShortName()
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    for (int i = 0; i < 7; i++)
    {

        printf("%-3s  ", arrDayNames[i].c_str());
    }
    cout << "\n";
}

void PrintMonthCalender(short MonthNumber, short Year)
{
    short DaysNumber = myDate::NumberOfDaysInMonth(Year, MonthNumber);
    short iter = 0;
    short Day = 1;
    short DayOrder = myDate::DayOfWeekOrder(Day, MonthNumber, Year) + 1;
    string blank = " ";

    cout << "_______________" << MonthShortName(MonthNumber) << "________________\n\n";

    PrintDaysShortName();

    while (DaysNumber >= Day)
    {
        if (iter == 7)
        {
            cout << endl;
            iter = 0;
        }

        if (DayOrder >= Day)
        {
            printf("%3s  ", blank.c_str());
            DayOrder--;
            iter++;
        }
        else
        {

            printf("%3d  ", Day);
            iter++;
            Day++;
        }
    }

    cout << endl;
    cout << string(34, '_') << endl;
};

int main()
{

    short year = myDate::ReadYear();
    short Month = myDate::ReadMonth();

    PrintMonthCalender(Month, year);

    return 0;
}