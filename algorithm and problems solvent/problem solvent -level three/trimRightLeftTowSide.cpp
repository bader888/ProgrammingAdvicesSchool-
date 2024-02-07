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

string TrimLeft(string s1)
{

    short postion = 0;

    while (s1[postion] == ' ')
    {
        postion++;
    }
    return s1.erase(0, postion);
};

string TrimRight(string s1)
{

    short postion = s1.length() - 1;

    while (s1[postion] == ' ')
    {
        postion--;
    }

    return s1.erase(postion, s1.length() + 1);
}

string Trim(string s1)
{

    return TrimLeft(TrimRight(s1));
}

// ANOTHER SOLUTION:
string TrimRight2(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

string TrimLeft2(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}
int main()
{

    // cout << TrimRight(mString::ReadString());
    cout << Trim(mString::ReadString());

    return 0;
};