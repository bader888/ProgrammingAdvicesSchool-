#include <iostream>
using namespace std;
void FillArray(int arr[100], int &arrLength)
{
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

bool IsPalindromArray2(int array[100], int arrLength)
{
    int head, tail;
    for (int i = 0; i < arrLength; i++)
    {
        head = array[i];

        tail = array[arrLength - i - 1];

        if (head != tail)
        {
            return false;
        }
    }

    return true;
}

// ANOTHER SOLUTION////////
bool IsPalindromArray(int array[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (array[i] != array[arrLength - i - 1])
        {
            return false;
        }
    }
    return true;
};

int main()
{
    int array[100], arrLength = 0;

    FillArray(array, arrLength);

    cout << "\nArray elements:\n";

    PrintArray(array, arrLength);

    if (IsPalindromArray(array, arrLength))
    {
        cout << "\nyes is palindrom: \n";
    }
    else
    {
        cout << "\nno is not palindrom: \n";
    }

    return 0;
}
