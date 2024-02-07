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

void PrintLetterPettern(int number)
{
    for (int i = 1; i <= number; i++)
    {
        cout << endl;
        for (int j = 0; j < i; j++)
        {
            cout << static_cast<char>(i + 64);
        }
    }
};

/////////////ANOTHER SOLUTION

int main()
{

    PrintLetterPettern(ReadPostiveNumber("Enter A Number: "));

    return 0;
};