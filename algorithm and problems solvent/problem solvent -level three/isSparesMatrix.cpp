
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

bool CheckSparseMatrix(int Matrix[3][3], int rows, int cols)
{
    return mArrayLib::CountDigitGreaterThanZeroInMatrix(Matrix, cols, rows) < mArrayLib::CountZeroInMatrix(Matrix, cols, rows);
};

// ANOTHER SOLUTION
bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short MatrixSize = Rows * Cols;
    return (mArrayLib::CountNumberInMatrix(Matrix1, Rows, Cols, 0) >= ceil((float)MatrixSize / 2));
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 0, 2);

    mArrayLib::PrintMatrix(arr1, 3, 3);

    if (CheckSparseMatrix(arr1, 3, 3))
    {
        printf("YES, is sparse matrix");
    }
    else
    {
        printf("NO, is Not sparse matrix");
    }

    return 0;
};