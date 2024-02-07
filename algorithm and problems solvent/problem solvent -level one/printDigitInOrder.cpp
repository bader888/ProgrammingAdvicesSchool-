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

////////////////////////////////MY SOLUTION//////////////////////////////////////////////////
int ReversrNumber(int number)
{
    int remainder = 0, number2 = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        number = number / 10; // take the reast char

        number2 = number2 * 10 + remainder;
    }
    return number2;
}

void printDigitInOrder(int number)
{
    int reversNumber = ReversrNumber(number);
    int remainder = 0;

    while (reversNumber > 0)
    {
        remainder = reversNumber % 10; // take the last digit

        reversNumber = reversNumber / 10; // remove the last digit

        cout << remainder << endl;
    }
}

////////////////////////////////ANOTHER SOLUTION//////////////////////////////////////////////////
void PrintDigits(int number)
{
    int remainder = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        number = number / 10; // take the reast char

        cout << remainder << endl; // print the last char
    }
}
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    // int number = ReadPostiveNumber("Enter Postive Number: ");
    // printDigitInOrder(number);
    PrintDigits(ReversrNumber(ReadPostiveNumber("Enter Postive Number: ")));
    return 0;
};