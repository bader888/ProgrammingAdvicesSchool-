
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

void FillMatrixWithOrderNumbers(int TwoDimentionArr[3][3], int rows, int cols)
{
    int Counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            TwoDimentionArr[i][j] = ++Counter;
        }
    }
};

void TrasPoseMatrix(int arr[3][3], int cols, int rows)
{
    int count = 0, temp = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = count; j < cols; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                temp = arr[i][j];

                arr[i][j] = arr[j][i];

                arr[j][i] = temp;
            }
        }
        count++;
    };
}

// another solution:
void TM(int matrix[3][3], int TrasPoseMatrix[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            TrasPoseMatrix[i][j] = matrix[j][i];
        };
    }
};

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithOrderNumbers(arr, 3, 3);

    printf("the following is order matrix: \n");
    mArrayLib::PrintMatrix(arr, 3, 3);

    TrasPoseMatrix(arr, 3, 3);

    printf("the following is traspose matrix: \n");
    mArrayLib::PrintMatrix(arr, 3, 3);

    return 0;
};