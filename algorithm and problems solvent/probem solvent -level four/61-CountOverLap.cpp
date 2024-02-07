#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

int CountOverLapDays(myDate::stPeriod PeriodOne, myDate::stPeriod PeriodTwo)
{
    if (myDate::IsPeriodsOverLap(PeriodOne, PeriodTwo))
    {

        myDate::stPeriod MixPeriod;
        MixPeriod.StartDate = PeriodTwo.StartDate;
        MixPeriod.EndDate = PeriodOne.EndDate;

        return myDate::PeriodLengthInDays(MixPeriod);
    }
    else
    {
        return -1;
    }
}

int main()
{

    myDate::stPeriod PeriodOne = myDate::ReadPeriod();
    cout << endl;
    myDate::stPeriod PeriodTwo = myDate::ReadPeriod();

    cout << endl;
    cout << "the overalap Days is = " << CountOverLapDays(PeriodOne, PeriodTwo);
}