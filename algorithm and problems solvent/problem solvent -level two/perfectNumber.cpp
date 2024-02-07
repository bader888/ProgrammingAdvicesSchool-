#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ///////////////////////MY SOLUTIONS/////////////////////////////////////////
int ReadPostieNumber(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

bool checkSum(int sum, int number)
{
    if (sum == number)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkResult(int i, int number, int sum)
{
    if (i < number && sum >= number)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CheckPerfectNumber(int number)
{
    int sum = 0;

    for (int i = 1; i <= number; i++)
    {
        if (checkResult(i, number, sum) == true)
        {
            break;
        }
        // cout << i;
        if (number % i == 0)
        {
            if (i == number)
            {
                continue;
            }
            else
            {
                sum += i;
            }
        }
    }

    return checkSum(sum, number);
}

void PrintResult(bool result, int number)
{
    if (result)
    {
        cout << number << " perfect number: ";
    }
    else
    {
        cout << number << " not perfect number: ";
    }
}
// ///////////////////////ANOTHER SOLUTIONS/////////////////////////////////////////
int ReadPostieNumber2(string messages)
{
    int number = 0;

    do
    {
        cout << messages << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

bool isPerfectNumber(int number)
{
    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        if (number % i == 0)
            sum += i;
    }

    return sum == number;
}

void printResult(int number)
{
    if (isPerfectNumber(number))
    {
        cout << number << " is perfect number: ";
    }
    else
    {
        cout << number << " is not perfect number: ";
    }
}
int main()
{
    // int number = ReadPostieNumber("plase Enter Postive Number: ");
    // PrintResult(CheckPerfectNumber(number), number);

    printResult(ReadPostieNumber2("enter postiveNumber: "));

    return 0;
};