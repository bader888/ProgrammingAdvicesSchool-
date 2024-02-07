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

string ReplaceWord2(string originalString, string searchWord, string replaceWord, bool MatchCase = true)
{
    vector<string> vString = mString::SplitString(originalString, " ");

    string s2;

    for (string &s : vString)
    {

        if (MatchCase)
        {

            if (s == searchWord)
            {
                s = replaceWord;
            }
        }
        else
        {
            if (mString::WordsToLowerCase(s) == mString::WordsToLowerCase(searchWord))
            {
                s = replaceWord;
            }
        }
    }

    s2 = mString::JoinString(vString, " ");

    return s2;
}

// another solution:
// USING BUILD IN FUNCTION (REPLACE)
string ReplaceWordUsingBuildInFunction(string originalString, string searchWord, string replaceWord)
{
    short pos = originalString.find(searchWord);

    while (pos != std::string::npos)
    {
        originalString = originalString.replace(pos, searchWord.length(), replaceWord);

        pos = originalString.find(searchWord);
    };

    return originalString;
}

int main()
{
    cout << "enter the string: \n";
    string s1 = mString::ReadString();

    cout << "enter word to replace: \n";
    string searchWord = mString::ReadString();

    cout << "enter the new word: \n";
    string ReplaceWord = mString::ReadString();

    cout << "string after replace the word: " << searchWord << " to " << ReplaceWord << endl;

    cout << ReplaceWord2(s1, searchWord, ReplaceWord);
    return 0;
};