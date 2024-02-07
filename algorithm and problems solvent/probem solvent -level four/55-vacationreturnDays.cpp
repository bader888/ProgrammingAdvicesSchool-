#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

myDate::sDate ReturndVacationDate(myDate::sDate Date, short Days)
{

    myDate::sDate ReturnDate = Date;
    while (Days > 0)
    {
        if (myDate::IsBusinessDay(ReturnDate))
        {
            ReturnDate = myDate::IncreaseDateByOneDay(ReturnDate);
            Days--;
        }
        else
        {
            ReturnDate = myDate::IncreaseDateByOneDay(ReturnDate);
        }
    }
    return ReturnDate;
}
int main()
{

    cout << "vacation start\n";
    myDate::sDate Date = myDate::ReadFullDate();
    cout << endl;

    short vacationDays = myDate::ReadDay();

    cout << "\n the  returnd date is ";
    myDate::PrintDate(ReturndVacationDate(Date, vacationDays));
}