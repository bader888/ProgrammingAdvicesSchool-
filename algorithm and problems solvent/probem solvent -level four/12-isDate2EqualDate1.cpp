#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

int main()
{
    cout << "Enter the date 1 info. \n";
    myDate::sDate Date1 = myDate::ReadFullDate();

    cout << "\nEnter the date 2 info. \n";
    myDate::sDate Date2 = myDate::ReadFullDate();

    if (myDate::IsDate1EqualDate2(Date1, Date2))
        cout << "yes";
    else
        cout << "no";

    return 0;
}