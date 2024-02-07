#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

myDate::sDate DateAddDays(short Days, myDate::sDate Date)
{
    short RemainingDays = Days + myDate::NumberOfDaysFromTheBeginingOfTheYear(Date);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = myDate::NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main()
{

    myDate::sDate Date = myDate::ReadFullDate();
    short Days = myDate::ReadDaysToAdd();

    Date = DateAddDays(Days, Date);

    cout << "\nDate after adding [" << Days << "] days is: ";

    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    return 0;
}