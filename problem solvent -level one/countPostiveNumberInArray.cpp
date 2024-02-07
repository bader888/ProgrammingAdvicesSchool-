#include <iostream>
using namespace std;
int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(-100, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int PositveCount(int arrSource[100], int arrLength)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {

        if (arrSource[i] >= 0)
        {
            counter++;
        }
    }
    return counter;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements:\n";

    PrintArray(arr, arrLength);

    cout << "\nPositive Numbers In Array is: " << PositveCount(arr, arrLength);

    return 0;
}
