#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

int ConverAgeToDays(myDate::sDate Date1, myDate::sDate Date2)
{
    int AgeAsDays = 0;

    while (myDate::IsDate1BeforeDate2(Date1, Date2))
    {

        AgeAsDays = myDate::isLeapYear(Date1.Year) ? AgeAsDays + 366 : AgeAsDays + 365;
        Date1.Year++;
    }

    return AgeAsDays;
};

myDate::sDate GetSystemDate()
{
    myDate::sDate Date;

    time_t t = time(0);
    tm *now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

int main()
{

    myDate::sDate Date1 = myDate::ReadFullDate();

    myDate::sDate Date2 = GetSystemDate();

    cout << "your Days Is Life equal :" << ConverAgeToDays(Date1, Date2);

    return 0;
}