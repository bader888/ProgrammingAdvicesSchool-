#include <string>
#include <iostream>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"
#include <vector>
using namespace std;

int NumberOfDaysInMonth(int Year, int month)
{
    if (month <= 0 || month > 12)
    {
        return 0;
    }

    if (month == 2)
    {
        return (mCheckLib::IsLeapYear(Year) ? 29 : 28);
    }

    int arrOfMonth[7] = {1, 3, 5, 7, 8, 10, 12};

    for (int i = 1; i < 7; i++)
    {
        if (arrOfMonth[i - 0] == month)
        {
            return 31;
        }
    }

    return 30;
}

int NumberOfDaysInMonthOneLine(int Year, int month)
{
    if (month <= 0 || month > 12)
    {
        return 0;
    };
    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2)
               ? (mCheckLib::IsLeapYear(Year) ? 29 : 28)
               : daysInMonths[month - 1];
}

int NumberOfHoursInMonth(int Year, int month)
{
    return NumberOfDaysInMonth(Year, month) * 24;
}

int NumberOfMinutsInMonth(int Year, int month)
{
    return NumberOfHoursInMonth(Year, month) * 60;
}

int NumberOfSecondsInMonth(int Year, int month)
{
    return NumberOfMinutsInMonth(Year, month) * 60;
}

int main()
{
    int year = myDate::ReadYear();
    int Month = myDate::ReadMonth();

    cout << "the days in Month [ " << Month << " ] " << NumberOfDaysInMonth(year, Month) << endl;
    cout << "the hour in Month [ " << Month << " ] " << NumberOfHoursInMonth(year, Month) << endl;
    cout << "the minuts in Month [ " << Month << " ] " << NumberOfMinutsInMonth(year, Month) << endl;
    cout << "the second in Month [ " << Month << " ] " << NumberOfSecondsInMonth(year, Month) << endl;

    return 0;
}