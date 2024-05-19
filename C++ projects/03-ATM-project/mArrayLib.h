#pragma once
#include <iostream>
#include <string>

#include "myReadLib.h"

using namespace std;

namespace mArrayLib
{
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

    bool IsNumberInMatrix(int Matrix[3][3], int rows, int cols, int number)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (Matrix[i][j] == number)
                {
                    return true;
                }
            };
        }
        return false;
    };

    int CountDigitGreaterThanZeroInMatrix(int Matrix[3][3], int rows, int cols)
    {
        int count = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (Matrix[i][j] != 0)
                {
                    count++;
                }
            };
        }
        return count;
    };

    int CountZeroInMatrix(int Matrix[3][3], int rows, int cols)
    {
        int count = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (Matrix[i][j] == 0)
                {
                    count++;
                }
            };
        }
        return count;
    };

    int CountNumberInMatrix(int Matrix[3][3], int rows, int cols, int number)
    {
        int count = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (Matrix[i][j] == number)
                {
                    count++;
                }
            };
        }
        return count;
    };

    int SumOfMatrix(int TwoDimentionArr[3][3], int rows, int cols)
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

    int SumColOfMatrix(int arr[3][3], int ColNumber, int Rows)
    {
        int Sum = 0;
        for (short i = 0; i < Rows; i++)
        {
            Sum += arr[i][ColNumber];
        }
        return Sum;
    };

    int SumRowOfMatrix(int arr[3][3], int RowNumber, int cols)
    {
        int Sum = 0;
        for (short i = 0; i < cols; i++)
        {
            Sum = +arr[RowNumber][i];
        }
        return Sum;
    }

    void FillMatrixWithRandomNumbers(int TwoDimentionArr[3][3], int rows, int cols, int from, int to)
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                TwoDimentionArr[i][j] = mReadLib::RandomNumber(from, to);
            }
        }
    };

    void PrintMatrix(int Matrix[3][3], int rows, int cols)
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%-5.*d", 2, Matrix[i][j]);
            };
            printf("\n");
        }
    };

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

    void FillArrayWithRandomNumber(int arr[100], int &arrLength, int from, int to)
    {
        cout << "enter array length: ";
        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = mReadLib::RandomNumber(from, to);
        };
        cout << endl;
    };

    void PrintArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            cout << arr[i] << " ";
        };

        cout << endl;
    };

    int sumOfArrayNumber(int arr[100], int arrLength)
    {
        int sum = 0;

        for (int i = 0; i < arrLength; i++)
        {
            sum += arr[i];
        }
        return sum;
    };

    int AvargeNumbersOfArray(int array[100], int arrayLength)
    {
        return (int)sumOfArrayNumber(array, arrayLength) / arrayLength;
    };

    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    };

    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int max = 0;
        max = arr[0];

        for (int i = 0; i < arrLength; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        return max;
    };

    int MinNumberInArray(int arr[100], int arrLength)
    {
        int min = 0;
        min = arr[0];

        for (int i = 0; i < arrLength; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        return min;
    };

    void ReadArrary(int arr[100], int &arrLength)
    {
        cout << "enter array length: ";
        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
        {
            cout << "element "
                 << "[" << i + 1 << "] : ";
            cin >> arr[i];
        };
        cout << endl;
    };

    int CheckReapeateNumber(int arr[100], int arrLength, int NumberCheck)
    {
        int count = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == NumberCheck)
            {
                count++;
            };
        };

        return count;
    };

    void SumOf2Arrays(int arr1[100], int arr2[100], int arrLength, int SumArr[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            SumArr[i] = arr1[i] + arr2[i];
        };
    };

    void AddArrayElement(int number, int array[100], int &arrLength)
    {
        arrLength++;

        array[arrLength - 1] = number;
    };

    void InputUserNumberInArray(int array[100], int &arrLength)
    {
        bool AddMore = true;

        do
        {
            AddArrayElement(mReadLib::ReadNumber(), array, arrLength);

            cout << "\ndo you want to add more number: [0]:no , [1]: yes: ";
            cin >> AddMore;

        } while (AddMore);
    };

    int FindPostionNumberInArray(int number, int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {

            if (number == arr[i])
            {
                return i;
            }
        };

        return -1;
    };

    bool IsNumberInArray(int number, int arr[100], int arrLength)
    {

        return FindPostionNumberInArray(number, arr, arrLength) != -1;
    };

    void CopyArrayInRversOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[(arrLength - i) - 1];
        }
    };

    void Swap(int &A, int &B) // 5 , 10
    {
        int timp = A;
        A = B;
        B = timp;
    }

    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[mReadLib::RandomNumber(1, arrLength - 1)], arr[mReadLib::RandomNumber(1, arrLength - 1)]);
        }
    }
}
