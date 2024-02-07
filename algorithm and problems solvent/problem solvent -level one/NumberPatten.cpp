#include <iostream>
#include <string>
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

void PrintNumberPettern(int number)
{
    for (int i = 1; i <= number; i++)
    {
        cout << endl;
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
    }
};

int main()
{
    PrintNumberPettern(ReadPostiveNumber("Enter Postive Number: "));

    return 0;
};