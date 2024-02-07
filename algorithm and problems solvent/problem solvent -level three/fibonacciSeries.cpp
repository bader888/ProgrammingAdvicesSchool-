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

int FibonacciSeries(int number)
{
    if (number == 1 || number == 2)
    {
        return 1;
    }

    return FibonacciSeries(number - 1) + FibonacciSeries(number - 2);
};

// ANOTHER SOLUTION
void PrintFibonacciSeries2(int number)
{
    int prev1 = 0, prev2 = 0, result = 0;
    for (int i = 1; i <= number; i++)
    {
        if (i == 1 || i == 2)
        {
            prev1 = 1;
            prev2 = 1;
            cout << prev1 << " ";
        }
        else
        {
            result = prev1 + prev2;
            prev1 = result;
            prev2 = result - prev2;
            cout << result << " ";
        };
    };
};

// ANOTHER SOLUTION:
void PrintFibonacciUsingLoop(short Number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "1   ";
    for (short i = 2; i <= Number; ++i)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "    ";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    };
};

// ANOTHER SOLUTION:
void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
{
    int FebNumber = 0;
    if (Number > 0)
    {
        FebNumber = Prev2 + Prev1;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << "    ";
        PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    PrintFibonacciSeries2(10);

    return 0;
};