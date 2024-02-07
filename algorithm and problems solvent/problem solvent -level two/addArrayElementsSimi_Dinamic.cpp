#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int ReadNumber()
{
    int number = 0;

    cout << "Enter A Number: " << endl;
    cin >> number;

    return number;
};

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    };
    cout << endl;
};

void AddNumberToArray(int number, int array[100], int index)
{

    array[index] = number;
}

void AskUserToAddNumber(int &number, int &index, int array[100])
{
    int UserChoise = 0;

    do
    {
        cout << "\nplease enter a number: ";
        cin >> number;

        AddNumberToArray(number, array, index);

        cout << "\ndo you want to add more number: [0]:no , [1]: yes: ";
        cin >> UserChoise;

        index++;

    } while (UserChoise != 0);
}

// ANOTHER SOLUTION///////////
void AddArrayElement(int number, int array[100], int &arrLength)
{
    arrLength++;

    array[arrLength - 1] = number;
};

void InputUserNumberInArray(int array[100], int &arrLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), array, arrLength);

        cout << "\ndo you want to add more number: [0]:no , [1]: yes: ";
        cin >> AddMore;

    } while (AddMore);
}

int main()
{
    // int number, index, array[100];

    // AskUserToAddNumber(number, index, array);

    // PrintArray(array, index);

    // cout << "\nArray Length: " << index;

    // ANOTHER SOLUTION////////////
    int arrLength = 0;
    int array[100];

    InputUserNumberInArray(array, arrLength);

    cout << "array length: " << arrLength;

    cout << "\nArray Elementes: ";

    PrintArray(array, arrLength);

    return 0;
};