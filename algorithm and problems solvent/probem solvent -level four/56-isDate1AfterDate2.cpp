#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

bool IsDate1AfterDate2(myDate::sDate Date1, myDate::sDate Date2)
{
    return !myDate::IsDate1BeforeDate2(Date1, Date2) && !myDate::IsDate1EqualDate2(Date1, Date2);
}
int main()
{

    cout << "Enter the date 1 info. \n";
    myDate::sDate Date1 = myDate::ReadFullDate();

    cout << endl;

    cout << "Enter the date 2 info. \n";
    myDate::sDate Date2 = myDate::ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2))
        cout << "yes Date 1 after Date2";
    else
        cout << "No Date1 Not after Date2";
}