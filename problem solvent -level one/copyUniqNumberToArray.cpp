#include <iostream>
using namespace std;

void FillArray(int arr[100], int &arrLength)
{
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // its a new element so we need to add the length by 1arrLength++;
    arrLength++;
    arr[arrLength - 1] = Number;
}

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

bool IsNumberInArray(int number, int arr[100], int arrLength)
{

    return FindPostionNumberInArray(number, arr, arrLength) != -1;
}

void CopyUniqNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {

        if (!IsNumberInArray(arrSource[i], arrDestination, arrDestinationLength))
        {

            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

int main()
{
    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;

    FillArray(arrSource, SourceLength);

    cout << "\nArray 1 elements:\n";

    PrintArray(arrSource, SourceLength);

    CopyUniqNumbers(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\nArray 2 distinct elements:\n";

    PrintArray(arrDestination, DestinationLength);

    return 0;
}
