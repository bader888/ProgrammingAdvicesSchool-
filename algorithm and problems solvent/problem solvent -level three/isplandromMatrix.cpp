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
// int matrixOne[3][3], int cols, int rows

int IsPalindromeMatrix2(int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3] = {
        {1, 10, 1},
        {1, 10, 1},
        {1, 10, 1},
    };

    // mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 0, 100);

    printf("matrix one: \n");

    mArrayLib::PrintMatrix(arr1, 3, 3);

    if (IsPalindromeMatrix2(arr1, 3, 3))
    {
        printf("YES, is plandrom matrix");
    }
    else
    {
        printf("NO, is Not plandrom matrix");
    }
    return 0;
};