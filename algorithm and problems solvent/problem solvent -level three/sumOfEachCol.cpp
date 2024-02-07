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
int SumRow(int arr[3][3], int RowNumber, int cols)
{
    int Sum = 0;
    for (short i = 0; i < cols; i++)
    {
        Sum = +arr[RowNumber][i];
    }
    return Sum;
}

void PrintSumCols(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf("Col %d sum is : %d \n", i + 1, SumRow(arr, i, cols));
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr, 3, 3, 0, 10);
    printf("the following 3x3 random matrix: \n");
    mArrayLib::PrintMatrix(arr, 3, 3);

    printf("the following sum of each col in random matrix: \n");
    PrintSumCols(arr, 3, 3);

    return 0;
};