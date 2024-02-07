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

void InvertedNumberPettern(int number)
{
    for (int i = number; i > 0; i--)
    {
        cout << endl;

        for (int j = i; j > 0; j--)
        {
            cout << i;
        }
    }
}
// ANOTHER SOLUTION
void PrintInvertedNumberPettern(int number)
{
    for (int i = number; i >= 1; i--)
    {

        cout << "\n";

        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << "\n";
    };
};

int main()
{
    PrintInvertedNumberPettern(ReadPostiveNumber("Enter Postive Number: "));

    return 0;
};