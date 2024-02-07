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

int main()
{
    srand((unsigned)time(NULL));

    int matrix3x2[3][3];

    mArrayLib::FillMatrixWithRandomNumbers(matrix3x2, 3, 3);

    printf("the following 3x3 random matrix: \n");

    mArrayLib::PrintMatrix(matrix3x2, 3, 3);

    return 0;
};