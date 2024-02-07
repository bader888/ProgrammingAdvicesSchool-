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

void SumMatrixRowInArry(int arr[3][3], int ArrSum[3], int rows, int cols)
{
    for (short i = 0; i < rows; i++)
    {
        ArrSum[i] = mArrayLib::SumRow(arr, i, cols);
    };
};
void PrintRowSumArray(int arrSumEachRow[3], int Rows)
{
    printf("the following is the sum each Col in array: \n");

    for (int i = 0; i < Rows; i++)
    {
        printf("Col %d sum is : %d \n", i + 1, arrSumEachRow[i]);
    };
};
int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    mArrayLib::FillMatrixWithRandomNumbers(arr, 3, 3);
    printf("the following 3x3 random matrix: \n");
    mArrayLib::PrintMatrix(arr, 3, 3);

    SumMatrixRowInArry(arr, arrSum, 3, 3);

    PrintRowSumArray(arrSum, 3);

    return 0;
};