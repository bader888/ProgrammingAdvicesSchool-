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

void PrintFirstLetterOfEachWord(string Word)
{
    for (int i = 0; i < Word.length(); i++)
    {
        if (i == 0)
        {
            cout << Word[i] << endl;
        }
        else if (Word[i] == ' ')
        {
            cout << Word[i + 1] << endl;
        }
    }
}

// ANOTHER SOLUTION
void PrintFirstLetterOfEachWord2(string s)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] != ' ' && IsFirstLetter)
        {
            cout << s[i] << endl;
        }

        IsFirstLetter = (s[i] == ' ' ? true : false);
    }
}

// ANOTHER SOLUTION
string PrintFirstLetterOfEachWord22(string s)
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
    PrintFirstLetterOfEachWord2(mString::ReadString());

    return 0;
};