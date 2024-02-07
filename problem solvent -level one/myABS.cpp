#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float number = 0;

    cout << "Enter A Number: " << endl;
    cin >> number;

    return number;
}

float MyAbs(float Number)
{
    if (Number < 0)
    {
        Number * -1;
    }
    else
    {
        return Number;
    };
}

int main()
{

    float num = ReadNumber();
    cout << "\nmy abs: " << MyAbs(num);
    cout << "\nmath abs: " << abs(num);

    return 0;
}
