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

// this have problem
short CountEachWordInString(string s1)
{
    string delim = " ";
    short postion = 0, Counter = 0;

    while ((postion = s1.find(delim)) != std::string::npos)
    {
        Counter++;

        s1.erase(0, postion + delim.length());
    }

    return Counter + 1;
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

    cout << CountEachWordInString2(mString::ReadString());

    return 0;
};