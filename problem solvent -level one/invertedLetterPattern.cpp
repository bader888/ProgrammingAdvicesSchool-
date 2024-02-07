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
void PrintInvertedNumberPettern(int number)
{
    for (int i = number; i >= 1; i--)
    {

        cout << "\n";

        for (int j = 1; j <= i; j++)
        {
            cout << static_cast<char>(i + 64); // convert number to letter in ASCII code system;
        }

        cout << "\n";
    };
};

/////////////ANOTHER SOLUTION
void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";
    // number = 5;
    //  i = 5+64-1= 68 , 68 > 65
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 1; j <= Number - (65 + Number - 1 - i); j++) // 4  - (65+5-1-68 = 1) = 3 ; (1 < 3)
        {
            cout << char(i); // convert number to letter in ASCII code system
        }
        cout << "\n";
    }
}

int main()
{

    PrintInvertedNumberPettern(ReadPostiveNumber("Enter Postive Number: "));

    return 0;
};