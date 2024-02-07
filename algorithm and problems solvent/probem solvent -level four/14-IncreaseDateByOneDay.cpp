#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

myDate::sDate IncreaseDateByOneDay(myDate::sDate Date)
{
    if (myDate::IsLastDayInMonth(Date))
    {

        if (myDate::IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Year++;
            Date.Month = 1;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int main()
{

    myDate::sDate Date = myDate::ReadFullDate();

    Date = IncreaseDateByOneDay(Date);

    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}