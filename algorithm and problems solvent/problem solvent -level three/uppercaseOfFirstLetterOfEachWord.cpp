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

// using the toupper function
void UpperFirstLetterOfEachWord(string s)
{
    bool IsFirstLetter = true;
    string UpperString;
    for (short i = 0; i < s.length(); i++)
    {

        if (s[i] != ' ' && IsFirstLetter)
        {

            UpperString += toupper(s[i]);
        }

        if (!IsFirstLetter)
        {

            UpperString += s[i];
        }

        IsFirstLetter = (s[i] == ' ' ? true : false);
    }

    cout << UpperString;
}

// using the ascii code
// capital = lowerCase - 32
void UpperFirstLetterOfEachWord2(string s)
{
    bool IsFirstLetter = true;

    string UpperString;

    for (short i = 0; i < s.length(); i++)
    {

        if (s[i] != ' ' && IsFirstLetter)
        {

            UpperString += s[i] - 32;
        }

        if (!IsFirstLetter)
        {

            UpperString += s[i];
        }

        IsFirstLetter = (s[i] == ' ' ? true : false);
    }

    cout << UpperString;
}

// ANOTHER SOLUTION
string PrintFirstLetterOfEachWord2(string s)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] != ' ' && IsFirstLetter)
        {
            s[i] = toupper(s[i]);
        }

        IsFirstLetter = (s[i] == ' ' ? true : false);
    }

    return s;
}
int main()
{

    UpperFirstLetterOfEachWord2(mString::ReadString());

    return 0;
};