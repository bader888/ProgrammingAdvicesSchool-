#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

short VacationDays(myDate::sDate Vfrom, myDate::sDate Vto)
{
    short ActucalDays = 0;
    while (myDate::IsDate1BeforeDate2(Vfrom, Vto))
    {
        if (myDate::IsBusinessDay(Vfrom))
            ActucalDays++;

        Vfrom = myDate::IncreaseDateByOneDay(Vfrom);
    }

    return ActucalDays;
}

int main()
{

    cout << "vacation start\n";
    myDate::sDate vacationfromDate = myDate::ReadFullDate();
    cout << endl;

    cout << "vacation end\n";
    myDate::sDate vacationToDate = myDate::ReadFullDate();
    cout << endl;

    cout << "vacation from ";
    myDate::PrintDate(vacationfromDate);
    cout << "vacation to ";
    myDate::PrintDate(vacationToDate);

    cout << "\n the actucal vacation is " << VacationDays(vacationfromDate, vacationToDate);
}