#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;
enum enComparDate
{
    Befor = 1,
    Equal = 0,
    After = -1
};

enComparDate ComparDate(myDate::sDate Date1, myDate::sDate Date2)
{

    return (myDate::IsDate1BeforeDate2(Date1, Date2))
               ? enComparDate::Befor
           : myDate::IsDate1EqualDate2(Date1, Date2)
               ? enComparDate::Equal
               : enComparDate::After;
}
int main()
{

    cout << "Enter the date 1 info. \n";
    myDate::sDate Date1 = myDate::ReadFullDate();

    cout << endl;

    cout << "Enter the date 2 info. \n";
    myDate::sDate Date2 = myDate::ReadFullDate();

    cout << "\n Compar Result = " << ComparDate(Date1, Date2);
}