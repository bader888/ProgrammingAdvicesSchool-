#include <iostream>
#include <string>
using namespace std;
/////////////////////////MY SOLUTIONS//////////////////////////////////////////////
int ReadPostiveNumber(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

void reversDigitNumber(int number)
{
    string num_stg = to_string(number);

    for (int i = num_stg.length(); i >= 0; i--)
    {
        cout << num_stg[i];
    }
}
/////////////////////////ANOTHER SOLUTIONS/////////////////////////////////////////
void PrintDigit(int number)
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
    // reversDigitNumber(ReadPostiveNumber2("enter postive number: "));
    PrintDigit(ReadPostiveNumber("enter postive number: "));
};