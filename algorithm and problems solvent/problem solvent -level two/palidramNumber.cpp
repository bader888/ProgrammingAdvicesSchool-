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
    int remainder = 0, number2 = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        number = number / 10; // take the reast char

        number2 = number2 * 10 + remainder;
    }
    return number2;
}
bool palindromNumber(int number)
{
    int numberRevers = ReversrNumber(number);

    if (numberRevers == number)
    {
        return true;
    }
};

/////////////////////////ANOTHER SOLUTIONS/////////////////////////////////////////
bool isPalindromNumber(int number)
{
    return number == ReversrNumber(number);
};

int main()
{
    if (palindromNumber(ReadPostiveNumber("Enter palindrom number: ")))
    {

        cout << "palindrom Number ";
    }
    else
    {
        cout << "NOT PalindromNumber ";
    };
    return 0;
};