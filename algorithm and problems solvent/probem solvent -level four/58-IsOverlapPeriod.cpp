// #pragma warning(disable : 4996)
// #include <string>
// #include <iostream>
// #include <cstdio>
// #include "../lib/myReadLib.h"
// #include "../lib/mCheckLib.h"
// #include "../lib/date.h"

// using namespace std;

// struct stPeriod
// {
//     myDate::sDate startDate;
//     myDate::sDate EndDate;
// };

// stPeriod ReadPeriod()
// {
//     stPeriod Period;
//     cout << "Enter Period start \n";
//     Period.startDate = myDate::ReadFullDate();
//     cout << endl;
//     cout << "Enter Period End \n";
//     Period.EndDate = myDate::ReadFullDate();

//     return Period;
// }
// bool IsPeriodsOverLap(stPeriod perOne, stPeriod perTwo)
// {

//     if (myDate::CompareDates(perTwo.EndDate, perOne.startDate) == myDate::enDateCompare::Before || myDate::CompareDates(perTwo.startDate, perOne.EndDate) == myDate::enDateCompare::After)

//         return false;
//     else
//         return true;
// }

// int main()
// {

//     stPeriod PeriodOne = ReadPeriod();

//     cout << endl;

//     stPeriod PeriodTow = ReadPeriod();

//     cout << endl;
//     cout << IsPeriodsOverLap(PeriodOne, PeriodTow);
// }