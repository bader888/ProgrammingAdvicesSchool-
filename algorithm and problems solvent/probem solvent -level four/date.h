#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "mStringLib.h"
using namespace std;

namespace myDate
{
    // this function is all solution in this Course and my solution is an another file
    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    struct sDate
    {
        short Year;
        short Month;
        short Day;
    };

    struct stPeriod
    {
        myDate::sDate StartDate;
        myDate::sDate EndDate;
    };

    short ReadYear()
    {
        short Year;
        cout << "Please enter a year to check? ";
        cin >> Year;
        return Year;
    }

    short ReadDaysToAdd()
    {
        short Days;
        cin >> Days;
        return Days;
    }

    short ReadMonth()
    {
        short Month;
        cout << "Please enter a Month to check? ";
        cin >> Month;
        return Month;
    }

    short ReadDay()
    {
        short Day;
        cout << "Please enter a Day to check? ";
        cin >> Day;
        return Day;
    };

    sDate ReadFullDate()
    {
        sDate Date;
        Date.Day = ReadDay();
        Date.Month = ReadMonth();
        Date.Year = ReadYear();

        return Date;
    };

    string ReadStringDate(string Message)
    {
        string DateString;
        cout << Message;
        getline(cin >> ws, DateString);
        return DateString;
    }

    string MonthShortName(short MonthOrder)
    {
        string MonthName[] = {"Jan",
                              "Feb",
                              "Mar",
                              "Apr",
                              "May",
                              "Jun",
                              "Jul",
                              "Aug",
                              "Sep",
                              "Oct",
                              "Nov",
                              "Dec"};
        return MonthName[MonthOrder - 1];
    }

    bool isLeapYear(short Year) { return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0); }

    short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder(sDate Date)
    {
        short a, y, m;
        a = (14 - Date.Month) / 12;
        y = Date.Year - a;
        m = Date.Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
        return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short NumberOfDaysFromTheBeginingOfTheYear(sDate Date)
    {
        short TotalDays = 0;
        for (int i = 1; i <= Date.Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Date.Year);
        }
        TotalDays += Date.Day;
        return TotalDays;
    }

    bool IsDate1BeforeDate2(myDate::sDate Date1, myDate::sDate Date2)
    {
        return (Date1.Year < Date2.Year)
                   ? true
                   : ((Date1.Year == Date2.Year)
                          ? (Date1.Month < Date2.Month
                                 ? true
                                 : (Date1.Month == Date2.Month
                                        ? Date1.Day < Date2.Day // this not coundtion cuze it will return true or false anyway
                                        : false))
                          : false);
    }

    bool IsLastDayInMonth(sDate Date) { return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year)); }

    bool IsLastMonthInYear(short Month) { return (Month == 12); }

    myDate::sDate IncreaseDateByOneDay(myDate::sDate Date)
    {
        if (myDate::IsLastDayInMonth(Date))
        {
            if (myDate::IsLastMonthInYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }

        return Date;
    }

    void SwapDates(myDate::sDate &date1, myDate::sDate &date2)
    {
        myDate::sDate TempDate;
        TempDate.Year = date1.Year;
        TempDate.Month = date1.Month;
        TempDate.Day = date1.Day;

        date1.Year = date2.Year;
        date1.Month = date2.Month;
        date1.Day = date2.Day;

        date2.Year = TempDate.Year;
        date2.Month = TempDate.Month;
        date2.Day = TempDate.Day;
    };

    int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)

    {
        int Days = 0;
        short SawpFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            // Swap Dates
            SwapDates(Date1, Date2);
            SawpFlagValue = -1;
        }
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
    }

    void PrintDaysShortName()
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        for (int i = 0; i < 7; i++)
        {

            printf("%-3s  ", arrDayNames[i].c_str());
        }
        cout << "\n";
    }

    void PrintMonthCalender(short Month, short Year)
    {
        int NumberOfDays; // Index of the day from 0 to 6

        int current = DayOfWeekOrder(1, Month, Year);

        NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        // Print the current month name

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        // Print the columns

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        // Print appropriate spaces

        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  _________________________________\n");
    };

    void PrintYearCalender(short Year)
    {

        for (int i = 0; i < 12; i++)
        {
            PrintMonthCalender(i + 1, 2022);
        }
    };

    bool IsDate1EqualDate2(myDate::sDate Date1, myDate::sDate Date2)
    {
        return (Date1.Year == Date2.Year)
                   ? (Date1.Month == Date2.Month)
                         ? (Date1.Day == Date2.Day)
                         : false
                   : false;
    };

    bool IsDate1AfterDate2(myDate::sDate Date1, myDate::sDate Date2)
    {
        return !myDate::IsDate1BeforeDate2(Date1, Date2) && !myDate::IsDate1EqualDate2(Date1, Date2);
    }

    sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        sDate Date;

        short RemainingDays = DateOrderInYear;

        short MonthDays = 0;

        Date.Year = Year;

        Date.Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Year, Date.Month);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = RemainingDays;
                break;
            };
        };
    };

    myDate::sDate DateAddDays(short Days, myDate::sDate Date)
    {
        short RemainingDays = Days + myDate::NumberOfDaysFromTheBeginingOfTheYear(Date);

        short MonthDays = 0;

        Date.Month = 1;

        while (true)
        {
            MonthDays = myDate::NumberOfDaysInAMonth(Date.Month, Date.Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;

                Date.Month++;

                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else
            {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return arrDayNames[DayOfWeekOrder];
    }

    myDate::sDate GetSystemDate()
    {
        myDate::sDate Date;

        time_t t = time(0);
        tm *now = localtime(&t);
        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;
        return Date;
    }

    // increase Part
    sDate IncreaseDateByOneWeek(sDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    sDate IncreaseDateByXWeeks(short Weeks, sDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    sDate IncreaseDateByOneMonth(sDate Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        } // last check day in date should not exceed max days in the current month
          // example if date is 31/1/2022 increasing one month should not be 31/2/2022,
          // it should // be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    sDate IncreaseDateByXDays(short Days, sDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    sDate IncreaseDateByXMonths(short Months, sDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    sDate IncreaseDateByOneYear(sDate Date)
    {
        Date.Year++;
        return Date;
    }

    sDate IncreaseDateByXYears(short Years, sDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
    {
        Date.Year += Years;
        return Date;
    }

    sDate IncreaseDateByOneDecade(sDate Date)
    { // Period of 10
        Date.Year += 10;
        return Date;
    }

    sDate IncreaseDateByXDecades(short Decade, sDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date)
    {
        Date.Year += Decade * 10;
        return Date;
    }

    sDate IncreaseDateByOneCentury(sDate Date)
    {
        // Period of 100
        Date.Year += 100;
        return Date;
    }

    sDate IncreaseDateByOneMillennium(sDate Date)
    {
        // Period of 1000 years
        Date.Year += 1000;
        return Date;
    }

    // decrease Part
    sDate DecreaseDateByOneDay(sDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Month = 12;
                Date.Day = 31;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
            }
        }
        else
        {
            Date.Day--;
        }
        return Date;
    }

    sDate DecreaseDateByOneWeek(sDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    sDate DecreaseDateByOneMonth(sDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
            Date.Month--; // last check day in date should not exceed max days in the current month//
                          // example if date is 31 / 3 / 2022 decreasing one month should not be 31 / 2 / 2022,
        // it should // be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    sDate DecreaseDateByXDays(short Days, sDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    sDate DecreaseDateByXMonths(short Months, sDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    sDate DecreaseDateByOneYear(sDate Date)
    {
        Date.Year--;
        return Date;
    }

    sDate DecreaseDateByXYears(short Years, sDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
    {
        Date.Year -= Years;
        return Date;
    }

    sDate DecreaseDateByOneDecade(sDate Date)
    { // Period of 10 year
        Date.Year -= 10;
        return Date;
    }

    sDate DecreaseDateByXDecades(short Decade, sDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date)
    {
        Date.Year -= Decade * 10;
        return Date;
    }

    sDate DecreaseDateByOneCentury(sDate Date)
    {
        // Period of 100 years
        Date.Year -= 100;
        return Date;
    }

    sDate DecreaseDateByOneMillennium(sDate Date)
    {
        // Period of 1000 years
        Date.Year -= 1000;
        return Date;
    }

    void PrintDate(myDate::sDate Date)
    {
        cout << myDate::DayShortName(myDate::DayOfWeekOrder(Date)) << " ,  " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
    }

    bool IsEndOfWeek(myDate::sDate Date)
    {
        return myDate::DayOfWeekOrder(Date) == 6;
    }

    bool IsWeekEnd(myDate::sDate Date)
    {
        return (myDate::DayOfWeekOrder(Date) == 6 || myDate::DayOfWeekOrder(Date) == 5);
    }

    bool IsBusinessDay(myDate::sDate Date)
    {
        return !IsWeekEnd(Date);
    }

    short DaysUntilEndOfWeek(myDate::sDate Date)
    {

        return 6 - myDate::DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfMonth(myDate::sDate Date1)
    {
        myDate::sDate EndOfMontDate;
        EndOfMontDate.Day = myDate::NumberOfDaysInAMonth(Date1.Month, Date1.Year);
        EndOfMontDate.Month = Date1.Month;
        EndOfMontDate.Year = Date1.Year;
        return GetDifferenceInDays(Date1, EndOfMontDate, true);
    }

    short DaysUntilTheEndOfYear(myDate::sDate Date1)
    {
        myDate::sDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date1.Year;
        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short VacationDays(myDate::sDate Vfrom, myDate::sDate Vto)
    {
        short ActucalDays = 0;
        while (myDate::IsDate1BeforeDate2(Vfrom, Vto))
        {
            if (myDate::IsBusinessDay(Vfrom))
                ActucalDays++;

            Vfrom = myDate::IncreaseDateByOneDay(Vfrom);
        }

        return ActucalDays;
    }

    sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;

        // in case the data  is weekend keep adding one day util you reach business day
        // we get rid of all weekends before the first business day
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        // here we increase the vacation dates to add all weekends to it.

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        // in case the return date is week end keep adding one day util you reach business day
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DateFrom;
    }

    enDateCompare CompareDates(sDate Date1, sDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        /* if (IsDate1AfterDate2(Date1,Date2))
             return enDateCompare::After;*/
        // this is faster

        return enDateCompare::After;
    }

    stPeriod ReadPeriod()
    {
        stPeriod Period;
        cout << "Enter Period start \n";
        Period.StartDate = myDate::ReadFullDate();
        cout << endl;
        cout << "Enter Period End \n";
        Period.EndDate = myDate::ReadFullDate();

        return Period;
    }

    bool IsPeriodsOverLap(stPeriod perOne, stPeriod perTwo)
    {

        if (myDate::CompareDates(perTwo.EndDate, perOne.StartDate) == myDate::enDateCompare::Before || myDate::CompareDates(perTwo.StartDate, perOne.EndDate) == myDate::enDateCompare::After)

            return false;
        else
            return true;
    }

    int PeriodLengthInDays(myDate::stPeriod Period, bool IncludeLastDay = false)
    {
        return myDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeLastDay);
    };

    bool isDateInPeriod(sDate Date, stPeriod Period)
    {

        return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before || CompareDates(Date, Period.EndDate) == enDateCompare::After);
    };

    int CountOverlapDays(stPeriod Period1, stPeriod Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;

        if (!IsPeriodsOverLap(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {
            while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (isDateInPeriod(Period1.StartDate, Period2))
                    OverlapDays++;
                Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
            }
        }
        else
        {
            while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (isDateInPeriod(Period2.StartDate, Period1))
                    OverlapDays++;
                Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
            }
        }
        return OverlapDays;
    }

    bool IsValidDate(sDate Date)
    {
        if (Date.Day < 1 || Date.Day > 31)
            return false;

        if (Date.Month < 1 || Date.Month > 12)
            return false;

        if (Date.Month == 2)
        {
            if (isLeapYear(Date.Year))
            {
                if (Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }
        short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        if (Date.Day > DaysInMonth)

            return false;

        return true;
    }

    myDate::sDate StringToDate(string DateStr)
    {
        vector<string> vDateStr = mString::SplitString(DateStr, "/");

        myDate::sDate stDate;
        stDate.Day = stoi(vDateStr[0]);
        stDate.Month = stoi(vDateStr[1]);
        stDate.Year = stoi(vDateStr[2]);

        return stDate;
    };

    string DateToString(myDate::sDate Date, string delim)
    {
        return to_string(Date.Day) + delim + to_string(Date.Month) + delim + to_string(Date.Year);
    };

    string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = "";

        FormattedDateString = mString::ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));

        FormattedDateString = mString::ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));

        FormattedDateString = mString::ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

        return FormattedDateString;
    }
};