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

void PrintEachWordInString(string S1)
{
    string Word = " ";
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == ' ')
        {
            cout << Word;

            cout << endl;

            Word = " ";
        }
        else
        {
            Word += S1[i];
        }
    };
}

// ANOTHER SOLUTION:
void PrintEachWordInString2(string s1)
{
    string delim = " ";
    string word = " ";
    short postion = 0;

    while ((postion = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, postion);

        if (word != " ")
        {
            cout << word << endl;
        }

        s1.erase(0, postion + delim.length());
    }

    if (s1 != " ")
    {
        cout << s1;
    }
}

int main()
{

    PrintEachWordInString2(mString::ReadString());

    return 0;
};