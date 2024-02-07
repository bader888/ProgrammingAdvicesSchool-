#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

short DiffInDays(myDate::sDate date1, myDate::sDate date2, bool IncludingLastDay = false)
{
    short DiffInDays = 0;
    if (IncludingLastDay)
    {
        date2 = myDate::IncreaseDateByOneDay(date2);
    }

    if (!myDate::IsDate1BeforeDate2(date1, date2))
    {
        cout << "\ndate1 befor Date2\n";
    }

    else
    {
        while (true)
        {
            if (myDate::IsDate1EqualDate2(date1, date2))
            {
                break;
            }
            else
            {
                date1 = myDate::IncreaseDateByOneDay(date1);
                DiffInDays++;
            }
        }
    }

    return DiffInDays;
};

int main()
{
    cout << "Enter The Date One info. \n";
    myDate::sDate Date1 = myDate::ReadFullDate();

    cout << "\nEnter The Date two info. \n";
    myDate::sDate Date2 = myDate::ReadFullDate();

    cout << "the diff between Dates is " << DiffInDays(Date1, Date2) << endl;

    cout << "the diff [include last Day] between Dates is " << DiffInDays(Date1, Date2, true) << endl;

    return 0;
}