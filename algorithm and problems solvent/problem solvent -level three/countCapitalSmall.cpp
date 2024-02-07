#include <iostream> //to use cout, cin ...std
#include <math.h>   // to use pow , floor, ceil ...ets
#include <vector>   //to use vector
#include <cstdio>   // to use %s , %f , %d
#include <iomanip>  //to use the setw mainpulator
#include <string>   //to use string methods
#include <cctype>   //to use the char functions
#include <fstream>  // to deal with file
// my libs
#include "mArrayLib.h"
#include "mCheckLib.h"
#include "mStringLib.h"
#include "myReadLib.h"
using namespace std;

int CountCapitalLetter(string S1)
{
    int countCapitalLetterInString = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            countCapitalLetterInString++;
        };
        // count = (isupper(S1[i])) ? count++ : count;
    };

    return countCapitalLetterInString;
};

int CountSmallLetter(string S1)
{
    int CountSmallLetterInString = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (!isupper(S1[i]) && (int)S1[i] > 32)
        {
            CountSmallLetterInString++;
        };
        // count = (isupper(S1[i])) ? count++ : count;
    };

    return CountSmallLetterInString;
};

// ANOTHER SOLUTION:
enum enWhatToCount
{
    smallLetter = 0,
    CapitalLetter = 1,
    All = 3,
};

short CountLetter(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    short Counter = 0;
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    for (int i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetter && isupper(S1[i]))
        {
            Counter++;
        }
        if (WhatToCount == enWhatToCount::CapitalLetter && islower(S1[i]))
        {
            Counter++;
        }
    }

    return Counter;
}

int CountCapitalLetter(string S1)
{
    int Counter = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            Counter++;
        };
        // count = (isupper(S1[i])) ? count++ : count;
    };

    return Counter;
};

int CountSmallLetter(string S1)
{
    int CountSmallLetterInString = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            CountSmallLetterInString++;
        };
        // count = (isupper(S1[i])) ? count++ : count;
    };

    return CountSmallLetterInString;
};

int main()
{

    return 0;
}