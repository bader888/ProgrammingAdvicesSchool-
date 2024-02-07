#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int ReadPostiveNumber(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
};

int RandomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;

    return random;
};

void FillArrayWithRandomNumber(int arr[100], int &arrLength)
{
    cout << "enter array length: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    };
    cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    };
    cout << endl;
}

void CopyArray(int arr[100], int arrLength)
{
    int CopyArray[100];
    for (int i = 0; i < arrLength; i++)
    {
        CopyArray[i] = arr[i];
    };

    PrintArray(CopyArray, arrLength);
}

////////ANOTHER SOLUTION////////

void CopyArray2(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[i];
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100], arrayLength;

    FillArrayWithRandomNumber(array, arrayLength);

    int array2[100];

    CopyArray2(array, array2, arrayLength);

    cout << "\nMain Array: ";
    PrintArray(array, arrayLength);

    cout << "\ncopy array : ";
    PrintArray(array2, arrayLength);

    return 0;
};