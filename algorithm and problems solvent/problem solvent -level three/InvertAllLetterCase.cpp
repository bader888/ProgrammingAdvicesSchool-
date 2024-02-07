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

string InvertAllLetterCase(string S1)
{

    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = mString::InvertLetterCase(S1[i]);
    };

    return S1;
};

int main()
{
    string S1 = InvertAllLetterCase(mString::ReadString());

    cout << "the string after invert \n";

    cout << S1;

    return 0;
};