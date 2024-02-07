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

string LowecaseFirstLetterOfEachWord(string s)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] != ' ' && IsFirstLetter)
        {
            s[i] = tolower(s[i]);
        }

        IsFirstLetter = (s[i] == ' ' ? true : false);
    }

    return s;
}
int main()
{

    LowecaseFirstLetterOfEachWord(mString::ReadString());

    return 0;
};