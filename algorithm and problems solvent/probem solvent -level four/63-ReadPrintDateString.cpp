#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <cstdio>
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/date.h"
#include "../lib/mStringLib.h"

using namespace std;

string ReadDateString()
{
    string stringDate = " ";
    cout << "enter date dd/mm/yyyy ? ";
    getline(cin, stringDate);

    return stringDate;
}

myDate::sDate ConvertStringToDate(string DateStr)
{
    vector<string> vDateStr = mString::SplitString(DateStr, "/");

    myDate::sDate stDate;
    stDate.Day = stoi(vDateStr[0]);
    stDate.Month = stoi(vDateStr[1]);
    stDate.Year = stoi(vDateStr[2]);

    return stDate;
}

string ConvertDateToString(myDate::sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{

    string DateStr = ReadDateString();

    cout << "\nDate as struct\n";
    myDate::PrintDate(ConvertStringToDate(DateStr));

    cout << endl;

    cout << ConvertDateToString(ConvertStringToDate(DateStr));

    return 0;
};