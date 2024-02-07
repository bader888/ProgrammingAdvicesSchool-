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
        arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int CountEvenNumberInArray(int arrSource[100], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {

        if (arrSource[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], arrLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements:\n";

    PrintArray(arr, arrLength);

    cout << "\nEven Numbers In Array is: " << CountEvenNumberInArray(arr, arrLength);

    return 0;
}
