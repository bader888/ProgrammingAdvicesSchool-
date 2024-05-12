#pragma once
#include <iostream> //to use cout, cin ...std
#include <string>   //to use string methods
using namespace std;
namespace mGlobal
{

    void ClearTheScreen()
    {
        system("cls");
    };

    void showMessage(const string &message)
    {
        const int totalLength = 40;
        const int messageLength = message.length();
        const int paddingLength = (totalLength - messageLength) / 2;

        string line(totalLength, '=');

        cout << line << endl;
        cout << string(paddingLength, ' ') << message << endl;
        cout << line << endl;
    }

    void PrintInValidMsg(string Msg)
    {
        cout << Msg << endl;
    }

} // namespace mGlobal
