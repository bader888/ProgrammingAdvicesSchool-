#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
// random cabital , small , spicail and digit in one function
enum enCharactar
{
    cabitlLetter = 1,
    smallLetter = 2,
    specialChar = 3,
    digit = 4,
};

int RandomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;

    return random;
};
//////MY SOLUTION
void Random(int number)
{
    int random = 0;

    if (number == enCharactar::cabitlLetter)
    {
        random = RandomNumber(65, 90);
        cout << char(random);
    }
    if (number == enCharactar::smallLetter)
    {
        random = RandomNumber(97, 122);
        cout << char(random);
    }
    if (number == enCharactar::specialChar)
    {
        random = RandomNumber(150, 255);
        cout << char(random);
    }
    if (number == enCharactar::digit)
    {
        random = RandomNumber(1, 10);
        cout << random;
    }
}
////////////////////////ANOTHER SOLUTION/////////////////////////////////
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

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    // Random(1);
    // Random(2);
    // Random(3);
    // Random(4);

    cout << GetRandomCharcter(enCharactar::smallLetter) << endl;
    cout << GetRandomCharcter(enCharactar::cabitlLetter) << endl;
    cout << GetRandomCharcter(enCharactar::specialChar) << endl;
    cout << GetRandomCharcter(enCharactar::digit) << endl;
    return 0;
};