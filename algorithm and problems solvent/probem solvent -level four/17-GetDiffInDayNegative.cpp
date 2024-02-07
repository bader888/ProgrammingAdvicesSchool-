#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

int myGetDifferentInDays(myDate::sDate Date1, myDate::sDate Date2, bool IncludeEndDay = false)
{

    int Days = 0;

    if (IsDate1BeforeDate2(Date1, Date2))
    {

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
    }
    else
    {
        while (!IsDate1BeforeDate2(Date1, Date2))
        {
            Days--;
            Date2 = IncreaseDateByOneDay(Date2);
        }
    }
    return (IncludeEndDay) ? Days : ++Days;
}

int main()
{
    myDate::sDate Date1 = myDate::ReadFullDate();
    cout << endl;
    myDate::sDate Date2 = myDate::ReadFullDate();
    cout << "\nDiffrence is: " << myGetDifferentInDays(Date1, Date2) << " Day(s).";
    cout << "\nDiffrence (Including End Day) is: " << myGetDifferentInDays(Date1, Date2, true) << " Day(s).";

    return 0;
}