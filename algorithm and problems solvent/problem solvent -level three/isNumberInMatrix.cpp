
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
// solw
bool FindNumberInMatrix(int Matrix[3][3], int rows, int cols, int number)
{

    return (mArrayLib::CountNumberInMatrix(Matrix, rows, cols, number) > 0);
};

// ANOTHER SOLUTION
// faster
bool IsNumberInMatrix(int Matrix[3][3], int rows, int cols, int number)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Matrix[i][j] == number)
            {
                return true;
            }
        };
    }

    return false;
};

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 0, 2);

    mArrayLib::PrintMatrix(arr1, 3, 3);

    int number = 0;
    printf("enter the number to find: \n");
    cin >> number;

    if (FindNumberInMatrix(arr1, 3, 3, number))
    {
        printf("YES, the number is there");
    }
    else
    {
        printf("NO,  the number is not there");
    }

    return 0;
};