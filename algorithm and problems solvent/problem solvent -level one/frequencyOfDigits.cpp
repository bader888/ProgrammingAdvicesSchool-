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

int RemoveNumber(int number, short delNumber)
{
    int remainder = 0, newNumber = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        if (remainder != delNumber) // check the numbers are equal
        {
            newNumber = newNumber * 10 + remainder;
        }

        number = number / 10; // remove the last char
    }

    return newNumber;
}

int CountDigitFrequency(short digitToCheck, int number)
{
    int remainder = 0, countFreq = 0;

    while (number > 0)
    {
        remainder = number % 10; // take the last char

        number = number / 10; // remove the last char

        if (digitToCheck == remainder)
        {
            countFreq++;
        }
    }
    return countFreq;
};
////////////////////////////////MY SOLUTION//////////////////////////////////////////////////
void FrequencyOFallDigit(int number)
{
    short remainder = 0;
    int countFreq = 0;
    int check = 0;
    while (number > 0)
    {

        remainder = number % 10; // take the last char

        if (check != remainder)
        {

            countFreq = CountDigitFrequency(remainder, number);

            number = RemoveNumber(number, remainder); // remove the number we count from the main number

            cout << "digit " << remainder << " frequency is " << countFreq << endl;
        }

        check = remainder;
    }
}
////////////////////////////////ANOTHER SOLUTION//////////////////////////////////////////////////
void printAllDigitFrequency(int number)
{
    short digitFreq = 0;

    for (int i = 0; i < 10; i++)
    {
        digitFreq = CountDigitFrequency(i, number);

        if (digitFreq > 0)
        {
            cout << "dight frequency of" << i << "is " << digitFreq << endl;
        };
    }
}

//////////////////////////////////////////////////////////////////////////////////
int main()
{
    // FrequencyOFallDigit(ReadPostiveNumber("enter the postive number : "));

    int number = ReadPostiveNumber("enter postive number: ");
    printAllDigitFrequency(number);

    return 0;
};