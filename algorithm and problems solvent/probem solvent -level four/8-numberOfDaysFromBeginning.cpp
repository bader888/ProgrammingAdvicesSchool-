#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;
short TotalDaysFromTheBegginOfYear(short Day, short Month, short Year)
{
    short totalDays = 0;

    for (int i = 0; i < Month; i++)
    {

        totalDays += myDate::NumberOfDaysInMonth(Year, i + 1);
    };

    totalDays = totalDays - (myDate::NumberOfDaysInMonth(Year, Month) - Day);

    return totalDays;
}

int main()
{

    short day, month, year;
    day = myDate::ReadDay();
    month = myDate::ReadMonth();
    year = myDate::ReadYear();

    short totalDays = TotalDaysFromTheBegginOfYear(day, month, year);

    cout << "the total days from the beginning of the year is " << totalDays;

    return 0;
}