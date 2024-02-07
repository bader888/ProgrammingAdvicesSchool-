#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

bool ValidateDate(myDate::sDate Date)
{
    if (Date.Month > 12)
        return false;

    if (Date.Day > myDate::NumberOfDaysInAMonth(Date.Month, Date.Year) || Date.Day < 1)
        return false;
};

int main()
{
    myDate::sDate Date = myDate::ReadFullDate();

    cout << endl;

    if (ValidateDate(Date))
        cout << "Yes Validate date ";
    else
        cout << "No Validate date";
};