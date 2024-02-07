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

bool IsCharacter(char Character)
{

    if ((int)Character >= 65 && (int)Character <= 122)
        return true;
    else
        return false;
}

char ReadCaracter()
{
    char c = 0;

    cout << "Enter a character: \n";

    cin >> c;

    return c;
}

void InvertCharcter(char &Character)
{

    while (!IsCharacter(Character))
    {
        cout << "Pleas Enter  Valid Character: \n";

        cin >> Character;
    }

    // lower to capital
    if ((int)Character > 90)
    {
        Character = toupper(Character);
    }
    else
    {
        // capial to lower
        Character = tolower(Character);
    }
};

// ANOTHER SOLUTION
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
int main()
{

    char c = ReadCaracter();

    // invert char from lower to capital / from capital to lower
    InvertCharcter(c);

    cout << c;
    return 0;
};