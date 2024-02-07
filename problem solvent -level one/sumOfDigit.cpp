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

int SumDigit(int number)
{
    int sum = 0, remainder = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        number = number / 10; // take the reast char

        sum += remainder;
    }
    return sum;
}
/////////////////////////ANOTHER SOLUTIONS/////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "sum of the digits = " << SumDigit(ReadPostiveNumber("Enter Postive Number: "));

    return 0;
};