#pragma once
#include <iostream>
#include <string>
#include "mArrayLib.h"
#include "myReadLib.h"
using namespace std;

namespace mCheckLib
{
    bool CheckNumberInArray(int number, int arr[100], int arrLength)
    {
        if (mArrayLib::FindPostionNumberInArray(number, arr, arrLength) != -1)
        {
            return true;
        }

        return false;
    };

    int CheckReapeateNumberInArray(int arr[100], int arrLength, int NumberCheck)
    {
        int count = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == NumberCheck)
            {
                count++;
            };
        };

        return count;
    };

    bool CheckValidNumberInRage(int age, int from, int to)
    {
        return (age >= from && age <= to);
    }

    int CheckUntailValidAge(int from, int to)
    {
        int age = 0;

        do
        {

            age = mReadLib::ReadAge();

        } while (!CheckValidNumberInRage(age, from, to));

        return age;
    };

    bool CheckLetterInText(string Text, char letter)
    {

        bool check = false;

        for (char c : Text)
        {
            if (c == letter)
                check = true;
        }

        return check;
    }
}
