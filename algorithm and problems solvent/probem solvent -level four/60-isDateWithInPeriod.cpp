#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;
bool IsDateWithinPeriod(myDate::stPeriod Period, myDate::sDate Date)
{
    if (myDate::CompareDates(Date, Period.EndDate) == myDate::enDateCompare::Before && myDate::CompareDates(Date, Period.StartDate) == myDate::enDateCompare::After)
        return true;
    else
        return false;
}

;

int main()
{

    myDate::stPeriod PeriodOne = myDate::ReadPeriod();

    cout << endl;
    cout << "Enter date to check\n";

    myDate::sDate Date = myDate::ReadFullDate();

    if (IsDateWithinPeriod(PeriodOne, Date))
        cout << "Yes is within";
    else
        cout << "no is not within";
}