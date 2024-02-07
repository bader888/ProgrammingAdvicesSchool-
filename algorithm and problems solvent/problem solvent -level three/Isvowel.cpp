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

bool IsVowel(char Character)
{
    return ((tolower(Character) == 'a') ||
            (tolower(Character) == 'o') ||
            (tolower(Character) == 'u') ||
            (tolower(Character) == 'i') ||
            (tolower(Character) == 'e'));
};

int main()
{

    char letter = mString::ReadCharacter();

    cout << IsVowel(letter);

    return 0;
};