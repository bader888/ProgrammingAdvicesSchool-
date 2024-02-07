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
};

int ReversrNumber(int number)
{
    string revers;
    int remainder = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        revers = revers + to_string(remainder);

        number = number / 10; // take the reast char
    }
    return stoi(revers);
}
/////////////////////////ANOTHER SOLUTIONS/////////////////////////////////////////

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
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    int revers = ReversrNumber(ReadPostiveNumber("Enter Postive Number: "));
    cout << "\n revers number = " << revers;

    return 0;
};