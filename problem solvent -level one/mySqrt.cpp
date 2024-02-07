#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float number = 0;

    cout << "Enter A Number: " << endl;
    cin >> number;

    return number;
};

float MySqrt(float Number)
{
    return pow(Number, 0.5);
};

int main()
{

    float num = ReadNumber();

    cout << "\nmy Sqrt result : " << MySqrt(num);

    cout << "\nc++ Sqrt result: " << sqrt(num);

    return 0;
}
