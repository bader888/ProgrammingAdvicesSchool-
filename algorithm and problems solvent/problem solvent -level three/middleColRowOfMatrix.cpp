
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
void MidRowAndCol(int arr[3][3], int cols, int rows)
{
    for (int i = 1; i > 0; i--)
    {
        printf("middle row of matrix is: \n");
        for (int j = 0; j < cols; j++)
        {

            cout << arr[i][j] << "   ";
            ; // print the mid row
        };

        cout << endl;

        printf("middle col of matrix is: \n");

        for (int k = 0; k < rows; k++)
        {

            cout << arr[k][i] << "   "; // print the mid col
        };
        cout << endl;
    };
};

// ANOTHER SOLUTION
void PrintMidRowOfMatrix(int arr[3][3], int cols, int rows)
{
    short MidRow = rows / 2;
    for (int i = 1; i > 0; i--)
    {
        printf("middle row of matrix is: \n");
        for (int j = 0; j < cols; j++)
        {

            cout << arr[MidRow][j] << "   ";
        };
    };
};
void PrintMidColOfMatrix(int arr[3][3], int cols, int rows)
{
    short MidCol = cols / 2;
    for (int i = 1; i > 0; i--)
    {
        printf("middle row of matrix is: \n");
        for (int j = 0; j < rows; j++)
        {

            cout << arr[j][MidCol] << "   ";
        };
    };
};
int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(arr1, 3, 3, 1, 10);

    printf("the matrix : \n");

    mArrayLib::PrintMatrix(arr1, 3, 3);

    MidRowAndCol(arr1, 3, 3);

    return 0;
};