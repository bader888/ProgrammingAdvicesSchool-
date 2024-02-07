#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/date.h"
#include "../lib/mCheckLib.h"
using namespace std;

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

int main()
{

    short year = myDate::ReadYear();
    short Month = myDate::ReadMonth();
    short Day = myDate::ReadDay();

    short d = DayOfWeekOrder(Day, Month, year);

    printf("data %d/%d/%d \n", Day, Month, year);

    printf("the day order %d \n", d);

    printf("you born in %s", DayShortName(DayOfWeekOrder(Day, Month, year)).c_str());

    return 0;
}