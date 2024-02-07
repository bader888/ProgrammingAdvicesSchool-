#include <iostream> //to use cout, cin ...std
#include <math.h>   // to use pow , floor, ceil ...ets
#include <vector>   //to use vector
#include <cstdio>   // to use %s , %f , %d
#include <iomanip>  //to use the setw mainpulator
#include <string>   //to use string methods
#include <cctype>   //to use the char functions
#include <fstream>  // to deal with file
// my libs
#include "mArrayLib.h"
#include "mCheckLib.h"
#include "mStringLib.h"
#include "myReadLib.h"
using namespace std;

short CountLetter(string S1, char Character)
{
    short Counter = 0;

    if (islower(Character))
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (Character == S1[i] || Character == S1[i] + 32)
            {
                Counter++;
            }
        }
    };

    if (isupper(Character))
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (Character == S1[i] || Character == S1[i] - 32)
            {
                Counter++;
            }
        }
    };

    return Counter;
};

// ANOTHER SOLUTION

short CountLetter2(string S1, char Character, bool MatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {

        if (MatchCase)
        {
            if (Character == S1[i])
                Counter++;
        }
        else
        {
            if (tolower(Character) == tolower(S1[i]))
                Counter++;
        }
    }

    return Counter;
}

int main()
{
    string S1 = mString::ReadString();

    char letter = mString::ReadCharacter();

    // using the short hand if:
    char ConvertLetter = ((int)letter > 65 && (int)letter < 90) ? letter + 32 : letter - 32;

    // another way using invertMethod:
    // char ConvertLetter2 = mString::InvertCharcter(letter);

    printf("the letter %c count = %d", letter, CountLetter2(S1, letter));

    printf("the letter %c or %c count = %d", letter, ConvertLetter, CountLetter2(S1, letter, false));

    return 0;
};