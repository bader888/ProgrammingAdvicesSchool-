#include <iostream>
#include <string>
using namespace std;

void PrintLetterFromAAAtoZZZ()
{
    for (int i = 1; i <= 27; i++)
    {
        for (int j = 1; j <= 27; j++)
        {
            for (int k = 1; k <= 27; k++)
            {
                cout << static_cast<char>(i + 64);
                cout << static_cast<char>(j + 64);
                cout << static_cast<char>(k + 64) << endl;
            }
        }
    }
};
///////////ANOTHER SOLUTION
void PrintLetterFromAAAtoZZZ()
{

    string word = "";
    for (int i = 1; i <= 27; i++)
    {
        for (int j = 1; j <= 27; j++)
        {
            for (int k = 1; k <= 27; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << word;
                word = "";
            }
        }
    }
};

int main()
{
    PrintLetterFromAAAtoZZZ();
    return 0;
};