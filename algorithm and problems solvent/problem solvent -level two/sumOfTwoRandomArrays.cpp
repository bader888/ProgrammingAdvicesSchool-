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
void SumOf2Arrays(int arr1[100], int arr2[100], int arrLength, int SumArr[100])
{
    for (int i = 0; i < arrLength; i++)
    {
        SumArr[i] = arr1[i] + arr2[i];
    };
}
/// ANOTHER SOLUTION//////////////
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100], array2[100], sumArr[100];
    int arrayLength = ReadPostiveNumber("How Many Elemente You Want: ");

    FillArrayWithRandomNumber(array, arrayLength);
    FillArrayWithRandomNumber(array2, arrayLength);
    SumOf2Arrays(array, array2, arrayLength, sumArr);

    cout << "\nArray2 : ";
    PrintArray(array, arrayLength);

    cout << "\narray1 : ";
    PrintArray(array2, arrayLength);

    cout << "\nSum Of Two Arrays: ";
    PrintArray(sumArr, arrayLength);

    return 0;
};