#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

void PrintDate(myDate::sDate Date)
{
    cout << "\nToday is " << myDate::DayShortName(myDate::DayOfWeekOrder(Date)) << " ,  " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
}

bool IsEndOfWeek(myDate::sDate Date)
{
    return (myDate::DayShortName(myDate::DayOfWeekOrder(Date)) == "Sat");
}

bool IsWeekEnd(myDate::sDate Date)
{

    return (myDate::DayShortName(myDate::DayOfWeekOrder(Date)) == "Sat" || myDate::DayShortName(myDate::DayOfWeekOrder(Date)) == "Fri");
}

bool IsBusinessDay(myDate::sDate Date)
{
    return !IsWeekEnd(Date);
}

short DaysUntilEndOfWeek(myDate::sDate Date)
{
    short Days = 0;

    while (!IsEndOfWeek(Date))
    {

        Date.Day++;
        Days++;
    }

    return Days;
}

short DaysUntilEndOfMonth(myDate::sDate Date)
{
    short Days = 0;
    while (!myDate::IsLastDayInMonth(Date))
    {
        Date.Day++;
        Days++;
    }

    return Days;
};

short DaysUntilEndOfYear(myDate::sDate Date)
{

    short Days = 0;
    while (!myDate::IsLastMonthInYear(Date.Month))
    {

        Date = myDate::IncreaseDateByOneDay(Date);
        Days++;
    }

    return Days + 31;
};

int main()
{

    myDate::sDate Date = myDate::ReadFullDate();

    PrintDate(Date);

    if (IsEndOfWeek(Date))
        cout << "Is End Of Week\n";
    else
        cout << "Is Not End Of Week\n";
    if (IsWeekEnd(Date))
        cout << "Is WeekEnd\n";
    else
        cout << "Is Not WeekEnd\n";
    if (IsBusinessDay(Date))
        cout << "Is Business Day \n";
    else
        cout << "Is Not Business Day \n";
    cout << endl;

    cout << "Days Until End Of Week is : " << DaysUntilEndOfWeek(Date) << endl;
    cout << "Days Until End Of Month is : " << DaysUntilEndOfMonth(Date) << endl;
    cout << "Days Until End Of Year is : " << DaysUntilEndOfYear(Date) << endl;
    return 0;
}