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

int ElementPostion(int ele, int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (ele == arr[i])
        {
            return i;
        }
    };
}

int ElementOrder(int ele, int arr[100], int arrLength)
{

    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        count++;
        if (ele == arr[i])
        {
            return count;
        }
    };
}

// ANOTHER SOLUTION/////////////
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
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100], arrayLength;

    FillArrayWithRandomNumber(array, arrayLength);

    cout << "array elements: ";
    PrintArray(array, arrayLength);

    // int Find = ReadPostiveNumber("\nPlease Enter Number To Search For: ");

    // cout << "\nNumber You Looking For Is: " << Find;

    // if (ElementPostion(Find, array, arrayLength) == arrayLength)
    // {
    //     cout << "Elment Not Found :/";
    // }
    // else
    // {
    //     cout << "\nThe Nubmer Found In Postion: " << ElementPostion(Find, array, arrayLength);
    //     cout << "\nThe Nubmer Found its order: " << ElementOrder(Find, array, arrayLength);
    // }

    // Another solution/////
    int Number = ReadPostiveNumber("\nPlease Enter Number To Search For: ");

    short NumberPostion = FindPostionNumberInArray(Number, array, arrayLength);

    if (NumberPostion == -1)
    {
        cout << "Elment Not Found :-(\n";
    }
    else
    {
        cout << "\nThe Nubmer Found In Postion: " << NumberPostion;
        cout << "\nThe Nubmer Found its order: " << NumberPostion + 1;
    }

    return 0;
};