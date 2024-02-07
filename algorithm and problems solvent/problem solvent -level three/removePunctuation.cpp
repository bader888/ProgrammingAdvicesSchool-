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

string RemovePuncuationWord(string inputString)
{
    string CleanString;

    for (int i = 0; i < inputString.length(); i++)
    {

        if (mString::IsCharacter(inputString[i]))
        {
            CleanString += inputString[i];
        }
    }

    return CleanString;
};

string RemovePuncuationString(string OriginalString)
{

    vector<string> vString = mString::SplitString(OriginalString, " ");

    string clearString;

    for (string &word : vString)
    {
        word = RemovePuncuationWord(word);
    }

    clearString = mString::JoinString(vString, " ");

    return clearString;
}

// another solution:
string RemovePunctuationsFromString(string S1)
{
    string S2 = "";
    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

int main()
{
    cout << "Enter the string: \n";
    string s1 = mString::ReadString();

    cout << RemovePuncuationString(s1);

    return 0;
};