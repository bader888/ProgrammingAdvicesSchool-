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

vector<string> SplitString(string s1, string delim = " ")
{

    string word = " ";
    short postion = 0;

    vector<string> Words = {};

    while ((postion = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, postion);

        if (word != " ")
        {
            Words.push_back(word);
        }

        s1.erase(0, postion + delim.length());
    }

    if (s1 != " ")
    {
        Words.push_back(s1);
    };

    return Words;
}

string JoinString(string arrWords[], short arrLength, string delim)
{
    string word;

    for (int i = arrLength - 1; i >= 0; i--)
    {
        word = word + arrWords[i] + delim;
    };

    return word.substr(0, word.length() - delim.length());
}

void MoveTheElemsFromVectorToArray(vector<string> vWords, string arrWords[])
{

    std::copy(vWords.begin(), vWords.end(), arrWords);
}

// another solution:
string ReverseString(string s1)
{
    // bader haider
    // bader haider
    vector<string> vString = SplitString(s1);
    string s2;
    std::vector<string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {

        iter--;
        s2 += *iter + " ";
    }
    s2 = s2.substr(0, s2.length() - 1);
    return s2;
}

int main()
{
    string arrWords[100] = {};

    string s1 = mString::ReadString();

    vector<string> vWords = SplitString(s1);

    MoveTheElemsFromVectorToArray(vWords, arrWords);

    cout << "the string after revers: \n";

    cout << JoinString(arrWords, vWords.size(), " ");

    return 0;
};