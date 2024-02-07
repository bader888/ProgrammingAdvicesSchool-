#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

int PeriodLengthInDays(myDate::stPeriod Period, bool IncludeLastDay = false)
{
    return myDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeLastDay);
};

int main()
{

    myDate::stPeriod PeriodOne = myDate::ReadPeriod();

    cout << endl;
    cout << "period Length = " << PeriodLengthInDays(PeriodOne, true);
};