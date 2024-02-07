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

float MyRound(float Number)
{
    int result = 0;

    if (Number > 0)
    {

        result = Number + 0.5;
    }
    else
    {
        result = Number - 0.5;
    }

    return result;
};
// ANOTHER SOLUTION//////

float GetFraction(float Number)
{
    // 10. 7 - 10 = .7
    return Number - int(Number);
}

float myRound2(float Number)
{
    // Number = 10.7
    int IntPart; // 10
    IntPart = int(Number);

    float FractionPart = GetFraction(Number); // .7

    if (abs(FractionPart) >= 0.5) //.
    {
        if (Number > 0)       // 10 , -10
            return ++IntPart; // 11
        else
            return --IntPart; //-11
    }
    else
    {
        return IntPart;
    }
}
int main()
{

    float num = ReadNumber();

    cout << "\nmy round result : " << myRound2(num);

    cout << "\nc++ round result: " << round(num);

    return 0;
}
