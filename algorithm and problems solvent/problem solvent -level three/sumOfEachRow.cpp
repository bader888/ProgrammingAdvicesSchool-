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
// MY SOLUTION
void SumEachRowInMatrix(int arr[30][3], short rows, short cols)
{
    int SumOfRow = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            SumOfRow += arr[i][j];
        }
        printf("the %d sum is %d \n", i + 1, SumOfRow);
        SumOfRow = 0;
    }
}
// ANOTHER SOLUTION:
int SumRow(int arr[3][3], int RowNumber, int cols)
{
    int Sum = 0;
    for (short i = 0; i < cols; i++)
    {
        Sum = +arr[RowNumber][i];
    }
    return Sum;
}

void PrintSumRows(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf("the %d row sum is : %d \n", i + 1, SumRow(arr, i, cols));
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int matrix3x2[3][3];

    // my solution:
    mArrayLib::FillMatrixWithRandomNumbers(matrix3x2, 3, 3);
    printf("the following 3x3 random matrix: \n");
    mArrayLib::PrintMatrix(matrix3x2, 3, 3);

    // printf("\nthe following are the sum of each row: \n");
    // SumEachRowInMatrix(matrix3x2, 3, 3);

    // another solution:
    printf("\nthe following are the sum of each row: \n");
    PrintSumRows(matrix3x2, 3, 3);

    return 0;
};