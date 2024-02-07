#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"

using namespace std;

void PrintYearCalender(short Year)
{

    for (int i = 0; i < 12; i++)
    {
        myDate::PrintMonthCalender(i + 1, 2022);
    }
};

int main()
{
    PrintYearCalender(myDate::ReadYear());

    return 0;
}