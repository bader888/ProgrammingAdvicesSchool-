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

float MyFloor(float Number)
{
    int Result = 0;
    if (Number > 0)
        return Result = Number;
    else
        return Result = Number - 1;
};

// ANOTHER SOLUTION//////

int MyFloor2(float Number)
{
    if (Number > 0)
        return Number;
    else
        return Number - 1;
};
int main()
{

    float num = ReadNumber();

    cout << "\nmy Foolr result : " << MyFloor(num);

    cout << "\nc++ Floor result: " << floor(num);

    return 0;
}
