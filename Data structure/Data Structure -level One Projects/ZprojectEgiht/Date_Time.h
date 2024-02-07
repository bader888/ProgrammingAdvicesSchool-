#pragma warning(disable : 4996)
#pragma once
#include <iostream>
using namespace std;

class clsDate
{

private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;
    short _Hour;
    short _Min;
    short _sec;

    short GetDay()
    {
        return _Day;
    }

    short
    GetMonth()
    {
        return _Month;
    }

    short GetYear()
    {
        return _Year;
    }

    short GetHour()
    {
        return _Hour;
    }

    short GetMin()
    {
        return _Min;
    }

    short GetSec()
    {
        return _sec;
    }

public:
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
        _Hour = now->tm_hour;
        _Min = now->tm_min;
        _sec = now->tm_sec;
    }

    static string GetSystemDateAndTime()
    {
        clsDate Date;

        return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear()) +
               " - " + to_string(Date.GetHour()) + ":" + to_string(Date.GetMin()) + ":" + to_string(Date.GetSec());
    }
};
