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

short CountVowalsLetter(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {

        if (mString::IsVowel(S1[i]))
        {
            Counter++;
        }
    };
    return Counter;
};

int main()
{

    string s1 = mString::ReadString();

    cout << CountVowalsLetter(s1);

    return 0;
};