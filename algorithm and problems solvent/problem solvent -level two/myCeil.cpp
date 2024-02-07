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

float GetFraction(float Number)
{
    // 10. 7 - 10 = .7
    return Number - int(Number);
}

int MyCeil(float Number)
{
    if (abs(GetFraction(Number)) > 0)
    {
        if (Number > 0)
            return Number + 1;
        else
            return Number;
    }
    else
    {
        return Number;
    }
};

int main()
{

    float num = ReadNumber();

    cout << "\nmy ceil result : " << MyCeil(num);

    cout << "\nc++ ceil result: " << ceil(num);

    return 0;
}
