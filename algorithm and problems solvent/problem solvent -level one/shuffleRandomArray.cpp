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

void FilArrayWith1toN(int arr[100], int arrLength)
{
    for (int i = 1; i <= arrLength; i++)
    {

        arr[i] = i;
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 1; i <= arrLength; i++)
    {
        cout << arr[i] << " ";
    };
    cout << endl;
}

void ShuffleOrderArray(int arr[100], int arrLength)
{
    int a, b, timp, random;

    for (int i = 0; i < arrLength; i++)
    {
        random = RandomNumber(0, arrLength - 1);

        timp = arr[random]; // 4
        a = arr[i];         // 1

        arr[i] = timp;
        arr[random] = a;
    }
}
/// ANOTHER SOLUTION//////////////
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
        Swap(arr[RandomNumber(1, arrLength - 1)], arr[RandomNumber(1, arrLength - 1)]);
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int array[100];
    int arrayLength = ReadPostiveNumber("How Many Elemente You Want: ");

    FilArrayWith1toN(array, arrayLength);

    cout << "\nArray : ";
    PrintArray(array, arrayLength);

    // ShuffleOrderArray(array, arrayLength);
    ShuffleArray(array, arrayLength);

    cout << "\nArray after shuffle : ";
    PrintArray(array, arrayLength);
    return 0;
};