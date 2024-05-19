#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace mReadLib
{
    void ValidateNumber(short Number, short From, short To)
    {

        while (Number > To || Number < From)
        {

            cout << "Number Out The Range , Plaes Choice Another Number: ";
            cin >> Number;
        }
    }

    double ReadPostiveNumber(string messages)
    {
        double number = 0;

        do
        {
            cout << messages;
            cin >> number;

        } while (number <= 0);

        return number;
    };

    string ReadAccountNumber()
    {
        string AccountNumber;

        cout << "Enter the Account Number: ";

        getline(cin >> ws, AccountNumber);

        return AccountNumber;
    }

    string ReadUserName(string message)
    {
        string word = "";

        do
        {
            cout << message;
            getline(cin >> ws, word);
        } while (word == "");

        return word;
    };

    string ReadPassWord(string Message)
    {
        string passWord = "";
        cout << Message;
        getline(cin >> ws, passWord);

        return passWord;
    };

    string readText()
    {
        string Text;
        cout << "enter your Text: ";
        getline(cin, Text);

        return Text;
    };

    char ReadCharacter(string Message)
    {
        char Character;

        cout << Message;

        cin >> Character;

        return Character;
    };

    int RandomNumber(int from, int to)
    {
        int random = rand() % (to - from + 1) + from;

        return random;
    };

    int ReadNumberInRange(short from, short to)
    {
        int number = 0;
        cout << "Choose what do you want to do ? [" << from << " To " << to << "] ? ";
        cin >> number;

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "In Valida Data , Enter Valid One: ";

            cin >> number;
        };

        while (number > to || number < from)
        {

            cout << "Number Out The Range , Plaes Choice Another Number: ";
            cin >> number;
        }

        return number;
    }

    int ReadNumber(string Message = NULL)
    {
        int number = 0;
        cout << Message << endl;
        cin >> number;

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "In Valida Data , Enter Valid One: ";

            cin >> number;
        };

        return number;
    };

    short ReadAge()
    {

        short age = 0;

        do
        {
            cout << "Enter your age: ";

            cin >> age;

        } while (age <= 0);

        return age;
    };

    short Read_ATM_MainMenueOption()
    {
        cout << "Choose what do you want to do? [1 to 5]? ";
        short Choice = 0;
        cin >> Choice;

        ValidateNumber(Choice, 1, 5);

        return Choice;
    }

}
