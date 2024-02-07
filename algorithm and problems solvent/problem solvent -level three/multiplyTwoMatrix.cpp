
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

void MultiplyTwoMatrixes(int arr1[3][3], int arr2[3][3], int MultplyMatrix[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            MultplyMatrix[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3];
    int arr2[3][3];
    int multplayTwoMx[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 1, 10);

    mArrayLib::FillMatrixWithRandomNumbers(arr2, 3, 3, 1, 10);

    printf("the matrix one: \n");
    mArrayLib::PrintMatrix(arr1, 3, 3);
    printf("the matrix two: \n");
    mArrayLib::PrintMatrix(arr2, 3, 3);
    printf("\nthe multply the two matrixes is : \n");

    MultiplyTwoMatrixes(arr1, arr2, multplayTwoMx, 3, 3);

    mArrayLib::PrintMatrix(multplayTwoMx, 3, 3);
    return 0;
};