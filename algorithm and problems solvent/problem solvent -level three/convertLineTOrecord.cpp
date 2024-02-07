#include <iostream> //to use cout, cin ...std
#include <math.h>   // to use pow , floor, ceil ...ets
#include <vector>   //to use vector
#include <cstdio>   // to use %s , %f , %d
#include <iomanip>  //to use the setw mainpulator
#include <string>   //to use string methods
#include <cctype>   //to use the char functions
#include <fstream>  // to deal with file
// my libs
#include "mArrayLib.h"
#include "mCheckLib.h"
#include "mStringLib.h"
#include "myReadLib.h"

using namespace std;

struct sClient
{
    string AccountNumber;
    string userName;
    string pinCode;
    string phoneNumber;
    double AccountBalance;
};

sClient ConvertLinetoRecord(string Record)
{

    sClient Client;

    vector<string> vClientData = mString::SplitString(Record, "#//#");

    Client.AccountNumber = vClientData[0];
    Client.pinCode = vClientData[1];
    Client.userName = vClientData[2];
    Client.phoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
};

void PrintClientRecord(sClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.pinCode;
    cout << "\nName         : " << Client.userName;
    cout << "\nPhone        : " << Client.phoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main()
{
    string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << "\nLine Record is:\n";
    cout << stLine;
    sClient Client = ConvertLinetoRecord(stLine);
    PrintClientRecord(Client);
    system("pause>0");
    return 0;
};