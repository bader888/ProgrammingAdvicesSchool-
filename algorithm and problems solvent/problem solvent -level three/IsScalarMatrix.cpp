
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
bool IsScalarMarix(int Matrix1[3][3], short Rows, short Cols)
{
    int FirstDigitElement = Matrix1[0][0];
    // check Diagonal elements are 1 and rest elements are 0
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // check for diagonals element
            if (i == j && Matrix1[i][j] != FirstDigitElement)
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

    mArrayLib::PrintMatrix(arr1, 3, 3);

    cout << IsScalarMarix(arr1, 3, 3);

    return 0;
};