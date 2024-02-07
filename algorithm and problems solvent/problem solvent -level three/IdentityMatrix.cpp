
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

bool CheckIdentityMatrix(int arr[3][3], int cols, int rows)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = count; j < cols; j++)
        {
            if (i == j)
            {
                if (arr[i][j] == 1)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                else
                {
                    return false;
                };
            }
        }
        count++;
    };

    return true;
}
// ANOTHER SOLUTION
bool IsIdentityMarix(int Matrix1[3][3], short Rows, short Cols)
{
    // check Diagonal elements are 1 and rest elements are 0
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // check for diagonals element
            if (i == j && Matrix1[i][j] != 1)
            {
                return false;
            }
            // check for rest elements
            else if (i != j && Matrix1[i][j] != 0)
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

    int arr1[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 0, 1);

    printf("the matrix one: \n");

    mArrayLib::PrintMatrix(arr1, 3, 3);

    if (CheckIdentityMatrix(arr1, 3, 3))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

    return 0;
};