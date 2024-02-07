#include <iostream>
#include <string>
using namespace std;
// ///////////////////////MY SOLUTIONS//////////////////////////////////////////////
int ReadPostiveNumber2(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}
bool isPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}
void PrintPerfectNumbersFrom1ToN(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (isPerfectNumber(i))
        {
            cout << i << endl;
        }
    }
}
int main()
{
    PrintPerfectNumbersFrom1ToN(ReadPostiveNumber2("Enter Postive Number: "));
    return 0;
};