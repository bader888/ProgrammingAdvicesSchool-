#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;
short DaysInMonths(short Month, short Year)
{
    short totalDays = 0;

    for (int i = 0; i < Month; i++)
    {

        totalDays += myDate::NumberOfDaysInMonth(Year, i + 1);
    };

    return totalDays;
}

string DateFromDaysOrder(short totalDays, short year)
{
    short month = (totalDays / 30) + 1;

    short prevMonth = (totalDays / 30);

    short daysInMonth = DaysInMonths(prevMonth, year);

    short day = 0;

    while (totalDays > daysInMonth)
    {
        day++;

        daysInMonth++;
    }

    return to_string(day) + " / " + to_string(month) + " / " + to_string(year);
}

int main()
{

    short day, month, year;
    day = myDate::ReadDay();
    month = myDate::ReadMonth();
    year = myDate::ReadYear();

    short totalDays = myDate::TotalDaysFromTheBegginOfYear(day, month, year);

    cout << "the total days from the beginning of the year is " << totalDays << endl;

    cout << "the date from [ " << totalDays << " ] is: " << DateFromDaysOrder(totalDays, year);

    return 0;
}