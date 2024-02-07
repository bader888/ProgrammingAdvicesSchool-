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

void GenerateKeys(int keysNumber)
{
    for (int i = 1; i <= keysNumber; i++)
    {
        cout << "key"
             << "[" << i << "]: "
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << "-"
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << "-"
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << "-"
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter)
             << GetRandomCharcter(enCharactar::cabitlLetter);
        cout << endl;
    }
}

///////////////ANOTHER SOLUTION///////////////////
string GenerateWord(enCharactar wordType, short WordLength)
{
    string word = "";

    for (int i = 1; i <= WordLength; i++)
    {

        word = word + GetRandomCharcter(wordType);
    }

    return word;
};

string GenertateKey()
{
    string key = "";

    key = GenerateWord(enCharactar::cabitlLetter, 4) + "-";
    key = key + GenerateWord(enCharactar::cabitlLetter, 4) + "-";
    key = key + GenerateWord(enCharactar::cabitlLetter, 4) + "-";
    key = key + GenerateWord(enCharactar::cabitlLetter, 4);

    return key;
}

void GenerateKeys2(short NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {

        cout << "key"
             << "[" << i << "] : ";
        cout << GenertateKey() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    // GenerateKeys(ReadPostiveNumber("Enter number of keys to genertate: "));
    // cout << GenerateWord(enCharactar::cabitlLetter, 4);
    // cout << GenertateKey();
    GenerateKeys2(ReadPostiveNumber("Enter How Many keys you want: "));

    return 0;
};