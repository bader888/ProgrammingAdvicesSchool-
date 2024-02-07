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
};
short FindPostionNumberInArray(int number, int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {

        if (number == arr[i])
        {
            return i;
        }
    };

    return -1;
}

bool CheckNumberInArray(int number, int arr[100], int arrLength)
{
    if (FindPostionNumberInArray(number, arr, arrLength) != -1)
    {
        return true;
    }

    return false;
}
// ANOTHER SOLUTION //////////////
bool IsNumberInArray(int number, int arr[100], int arrLength)
{

    return FindPostionNumberInArray(number, arr, arrLength) != -1;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100], arrayLength;

    FillArrayWithRandomNumber(array, arrayLength);

    cout << "array elements: ";
    PrintArray(array, arrayLength);

    int Number = ReadPostiveNumber("\nPlease Enter Number To Search For: ");

    bool CheckedNumber = IsNumberInArray(Number, array, arrayLength);

    cout << "\nThe Number You Looking For Is: " << Number;

    if (!CheckedNumber)
    {
        cout << "\nThe Nubmer Found :-)\n ";
    }
    else
    {
        cout << "\nNumber Not Found :-(\n";
    }

    return 0;
};