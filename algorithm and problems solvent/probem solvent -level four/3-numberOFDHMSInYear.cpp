#include <string>
#include <iostream>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"

using namespace std;

short NumberOfDaysInYear(short Year)
{
    return (mCheckLib::IsLeapYear(Year) ? 366 : 356);
}

short NumberOfHoursInYear(short Year)
{
    return NumberOfDaysInYear(Year) * 24;
}

short NumberOfMinutsInYear(short Year)
{

    return NumberOfHoursInYear(Year) * 60;
}

short NumberOfSecondsInYear(short Year)
{
    return NumberOfMinutsInYear(Year) * 60;
}

int main()
{
    short year = mReadLib::ReadYear();

    cout << "the days in year [ " << year << " ] " << NumberOfDaysInYear(year) << endl;
    cout << "the hour in year [ " << year << " ] " << NumberOfHoursInYear(year) << endl;
    cout << "the minuts in year [ " << year << " ] " << NumberOfMinutsInYear(year) << endl;
    cout << "the second in year [ " << year << " ] " << NumberOfSecondsInYear(year) << endl;

    return 0;
}