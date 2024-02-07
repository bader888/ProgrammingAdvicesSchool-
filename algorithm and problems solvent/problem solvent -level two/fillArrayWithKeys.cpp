#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
// my solution
enum enCharactar
{
    cabitlLetter = 1,
    smallLetter = 2,
    specialChar = 3,
    digit = 4,
};

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

int RandomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;

    return random;
};

char GetRandomCharcter(enCharactar charType)
{
    switch (charType)
    {
    case enCharactar::smallLetter:
        return char(RandomNumber(97, 122));
        break;
    case enCharactar::cabitlLetter:
        return char(RandomNumber(65, 90));
        break;
    case enCharactar::specialChar:
        return char(RandomNumber(33, 47));
        break;
    case enCharactar::digit:
        return char(RandomNumber(48, 57));
        break;

    default:
        break;
    };
};

string GenerateWord(enCharactar wordType, short WordLength)
{
    string word = "";

    for (int i = 1; i <= WordLength; i++)
    {

        word = word + GetRandomCharcter(wordType);
    }

    return word;
};

string GenertKey()
{
    string key = "";

    key = GenerateWord(enCharactar::cabitlLetter, 4) + "-";
    key = key + GenerateWord(enCharactar::cabitlLetter, 4) + "-";
    key = key + GenerateWord(enCharactar::cabitlLetter, 4) + "-";
    key = key + GenerateWord(enCharactar::cabitlLetter, 4);

    return key;
}

void FillArrayWithKeys(string arr[100], int &arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = GenertKey();
    };
    cout << endl;
}

void PrintArray(string arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        cout << "\nArray"
             << "[" << i << "]: ";
        cout << arr[i] << " ";
    };
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arrLength = ReadPostiveNumber("Enter Array Length: ");
    string arr[100];

    FillArrayWithKeys(arr, arrLength);

    PrintArray(arr, arrLength);
    return 0;
};