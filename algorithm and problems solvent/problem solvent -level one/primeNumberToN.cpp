#include <iostream>
#include <string>
#include <cmath> // to use the round function
using namespace std;
enum enPrimNotPrime
{
    Prime = 1,
    NotPrime = 2
};
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}

int readPostieNumber(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

void PrintPrimNumbre(int number)
{

    cout << "the prime number from 1 to " << number << " are:";
    cout << endl;

    for (int i = 1; i <= number; i++)
    {
        if (CheckPrime(i) == enPrimNotPrime::Prime)
        {
            cout << i << endl;
        }
    }
}
int main()
{

    PrintPrimNumbre(readPostieNumber("Enter The Number: "));

    return 0;
};