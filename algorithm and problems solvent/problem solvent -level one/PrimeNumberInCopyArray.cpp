#include <iostream>
#include <string>
#include <cmath> // to use the round function
using namespace std;

enum enPrimNotPrime
{
    Prime = 1,
    NotPrime = 2
};

int ReadPostieNumber(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}
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

void CopyPrimeNumberOnly(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[count] = arrSource[i];
            count++;
        };
    }
    arr2Length = --count;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100], arrayLength;

    FillArrayWithRandomNumber(array, arrayLength);

    int array2[100], arr2length;

    CopyPrimeNumberOnly(array, array2, arrayLength, arr2length);

    cout << "\nMain Array: ";
    PrintArray(array, arrayLength);

    cout << "\nArray Of Prime Number : ";
    PrintArray(array2, arrayLength);

    return 0;
};