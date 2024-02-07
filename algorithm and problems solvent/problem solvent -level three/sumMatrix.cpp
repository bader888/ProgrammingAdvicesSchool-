
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
int PrintSumOfMatrix(int TwoDimentionArr[3][3], int rows, int cols)
{
    int sumOfMatrix = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sumOfMatrix += TwoDimentionArr[i][j];
        };
    }
    return sumOfMatrix;
};
int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 1, 10);

    printf("the matrix : \n");

    mArrayLib::PrintMatrix(arr1, 3, 3);

    printf("the sum of matrix is : %d", PrintSumOfMatrix(arr1, 3, 3));

    return 0;
};