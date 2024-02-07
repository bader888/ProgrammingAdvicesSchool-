#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;

    return random;
};

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    return 0;
};