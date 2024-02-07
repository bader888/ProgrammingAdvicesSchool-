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

// ANOTHER SOLUTION:
short CountEachWordInString2(string s1)
{
    string delim = " ", word = " ";
    short postion = 0, Counter = 0;

    while ((postion = s1.find(delim)) != std::string::npos)
    {
        word = s1.substr(0, postion);

        if (word != " ")
        {
            Counter++;
        }

        s1.erase(0, postion + delim.length());
    }

    if (s1 != " ")
    {
        Counter++;
    }

    return Counter;
}
int main()
{

    vector<string> Words = SplitString(mString::ReadString());

    cout << "the Tokens: " << Words.size() << endl;

    for (string &word : Words)
    {
        cout << word << endl;
    }

    return 0;
};