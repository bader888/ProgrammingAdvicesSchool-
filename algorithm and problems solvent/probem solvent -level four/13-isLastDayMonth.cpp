#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

bool IsLastDayInMonth(myDate::sDate Date)
{
    return Date.Day == myDate::NumberOfDaysInAMonth(Date.Month, Date.Year);
};

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
};

int main()
{
    cout << "Enter the date 1 info. \n";
    myDate::sDate Date1 = myDate::ReadFullDate();

    if (IsLastDayInMonth(Date1))
        cout << "yes day\n";
    else
        cout << "no day\n";

    if (IsLastMonthInYear(Date1.Month))
        cout << "yes month\n";
    else
        cout << "no month\n";

    return 0;
}