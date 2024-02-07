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

/////////////////////////MY SOLUTIONS//////////////////////////////////////////////
int FrequencyNumber(int totalNumber, int number)
{
    int remainder = 0, frequency = 0;

    while (totalNumber > 0)
    {
        remainder = totalNumber % 10; // take the last char

        totalNumber = totalNumber / 10; // remove the last char

        if (number == remainder)
        {
            frequency += 1;
        }
        else
        {
            continue;
        }
    }

    return frequency;
};

/////////////////////////ANOTHER SOLUTIONS/////////////////////////////////////////
// short it's smollest space in memory to save data ;
int CountDigitFrequency(short digitToCheck, int number)
{
    int remainder = 0, countFreq = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        number = number / 10; // remove the last char

        if (number == remainder)
        {
            countFreq++;
        }
    }

    return countFreq;
};

//////////////////////////////////////////////////////////////////////////////////
int main()
{

    cout << FrequencyNumber(ReadPostiveNumber("enter the total number: "), ReadPostiveNumber("enter the number you want to know the frequency: "));

    // ///////////////////////////////
    // int number = ReadPostiveNumber("enter the total number: ");
    // short digitCheck = ReadPostiveNumber("enter the number you want to know the frequency: ");
    // CountDigitFrequency(digitCheck, number);

    return 0;
};