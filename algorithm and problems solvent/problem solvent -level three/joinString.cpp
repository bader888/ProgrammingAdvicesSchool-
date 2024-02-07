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

string myJoinString(vector<string> vWords, string delim)
{
    string word;
    short vectorSize = vWords.size();
    short i = 1;
    for (string &s : vWords)
    {
        if (vectorSize != i)
        {

            word = word + s + delim;

            i++;
        }
        else
        {
            word = word + s;
        }
    };

    return word;
}

// ANOTHER SOLUTION
string JoinString(vector<string> vWords, string delim)
{
    string word;

    for (string &s : vWords)
    {
        word = word + s + delim;
    };

    return word.substr(0, word.length() - delim.length());
}

int main()
{
    vector<string> vWords = {"bader", "haider", "omer", "ali"};

    cout << "vector after join: \n";

    cout << JoinString(vWords, ":") << endl;

    cout << "array after join: \n";

    return 0;
};