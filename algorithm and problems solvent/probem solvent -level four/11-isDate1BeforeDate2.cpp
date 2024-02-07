#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

void DateOneLessOrBiggerThanDate2(myDate::sDate Date1, myDate::sDate Date2)
{
    short TotalDate1 = Date1.Day + Date1.Month + Date1.Year;
    short TotalDate2 = Date2.Day + Date2.Month + Date2.Year;
    if (TotalDate1 == TotalDate2)
    {
        cout << "thy are the same";
    }
    else if (TotalDate1 < TotalDate2)
    {
        cout << "YES, Date 1 less than Date 2 ";
    }
    else
    {
        cout << "NO, Date 1 not less than Date 2 ";
    }
}

int main()
{
    cout << "Enter the date 1 info. \n";
    myDate::sDate Date1 = myDate::ReadFullDate();

    cout << "Enter the date 2 info. \n";
    myDate::sDate Date2 = myDate::ReadFullDate();

    DateOneLessOrBiggerThanDate2(Date1, Date2);
    return 0;
}