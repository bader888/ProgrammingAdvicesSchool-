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

int MaxNumberInMatrix(int matrixOne[3][3], int cols, int rows)
{

    int maxNumberInMatrix = matrixOne[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (matrixOne[i][j] > maxNumberInMatrix)
            {
                maxNumberInMatrix = matrixOne[i][j];
            };
        };
    };
    return maxNumberInMatrix;
};

int MinNumberInMatrix(int matrixOne[3][3], int cols, int rows)
{

    int minNumberInMatrix = matrixOne[0][0];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (matrixOne[i][j] < minNumberInMatrix)
            {
                minNumberInMatrix = matrixOne[i][j];
            };
        };
    };
    return minNumberInMatrix;
};

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 0, 100);

    printf("matrix one: \n");

    mArrayLib::PrintMatrix(arr1, 3, 3);

    cout << MinNumberInMatrix(arr1, 3, 3) << ": is the min number in matrix\n\n";

    cout << MaxNumberInMatrix(arr1, 3, 3) << ": is the max number in matrix\n";
    return 0;
};