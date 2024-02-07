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

int minNumber(int arr[100], int arrLength)
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
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100], arrayLength;

    FillArrayWithRandomNumber(array, arrayLength);

    cout << "array elements: ";
    PrintArray(array, arrayLength);

    cout << "\n Max Number in Array is: " << minNumber(array, arrayLength);

    return 0;
};