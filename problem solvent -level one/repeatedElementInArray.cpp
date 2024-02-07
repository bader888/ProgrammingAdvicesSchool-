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
}

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i];
    };
    cout << endl;
}

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

int main()
{
    int array[100], arrayLength, numberCheck;

    ReadArrary(array, arrayLength);

    numberCheck = ReadPostiveNumber("Enter number to repeated check: ");

    cout << "\nOriginal Array Is: ";
    PrintArray(array, arrayLength);

    cout << "number " << numberCheck << " ";
    cout << "is repeated " << CheckReapeateNumber(array, arrayLength, numberCheck) << "time";

    return 0;
};