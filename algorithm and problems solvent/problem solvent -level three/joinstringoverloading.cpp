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

string JoinString(vector<string> vWords, string delim)
{
    string word;

    for (string &s : vWords)
    {
        word = word + s + delim;
    };

    return word.substr(0, word.length() - delim.length());
}

string JoinString(string arrWords[], short arrLength, string delim)
{
    string word;

    for (int i = 0; i < arrLength - 1; i++)
    {
        word = word + arrWords[i] + delim;
    };

    return word.substr(0, word.length() - delim.length());
}

int main()
{
    vector<string> vWords = {"bader", "haider", "omer", "ali"};

    cout << "vector after join: \n";

    cout << JoinString(vWords, ":") << endl;

    string arrWords[] = {"bader", "haider", "omer", "ali"};

    cout << "\n";

    cout << "array after join: \n";

    cout << JoinString(arrWords, 4, ":");

    return 0;
};