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

string WordsToUpperCase(string s)
{

    for (int i = 0; i < s.length(); i++)
    {
        // [s] = [s] - 32;
        // upper = lowerCase - 32 ;
        s[i] = toupper(s[i]);
        ;
    }

    return s;
}

string WordsToLowerCase(string s)
{

    for (int i = 0; i < s.length(); i++)
    {
        // [s] = [s] + 32;
        // lowerCase = upper + 32 ;
        s[i] = tolower(s[i]);
    }

    return s;
}

int main()
{
    string s1 = mString::ReadString();

    cout << "the words in upper case: \n";
    cout << WordsToUpperCase(s1);
    printf("\n\n");
    cout << "the words in lower case: \n";
    cout << WordsToLowerCase(s1);
    return 0;
};