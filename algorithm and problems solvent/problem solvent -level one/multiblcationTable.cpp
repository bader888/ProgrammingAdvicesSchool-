#include <iostream>
#include <string>
using namespace std;

// my solution
void header()
{

    for (int i = 1; i <= 10; i++)
    {
        cout << "       " << i;
    }
    cout << endl;
}
void Line()
{
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
}
void multplication()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << endl;
        cout << i << "   "
             << "|  ";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "       ";
        }
    }
}

////////////////////////ANOTHER SOLUTIONS/////////////////////////////////////
void ptintTableHeader()
{
    cout << "\n\n\t\t\t Multiplications Table From 1 to 10 \n\n";
    cout << "\t";

    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n----------------------------------------------------------------------\n";
}
string columSperator(int i)
{
    if (i < 10)
    {
        return "   |";
    }
    else
    {
        return "  |";
    }
}
void printMultiplicationTable()
{
    ptintTableHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << columSperator(i) << "\t";

        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
    }
}
int main()
{

    // header();
    // Line();
    // multplication();
    printMultiplicationTable();

    return 0;
};