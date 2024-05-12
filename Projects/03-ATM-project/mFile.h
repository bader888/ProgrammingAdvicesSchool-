#pragma once
#include <iostream> //to use cout, cin ...std
#include <math.h>   // to use pow , floor, ceil ...ets
#include <vector>   //to use vector
#include <cstdio>   // to use %s , %f , %d
#include <iomanip>  //to use the setw mainpulator
#include <string>   //to use string methods
#include <cctype>   //to use the char functions
#include <fstream>  // to deal with file
// my libs
#include "mStringLib.h"
#include "mCheckLib.h"
#include "myReadLib.h"
using namespace std;

namespace myFiles
{
    const string ClientsFileName = "ClientsData.txt";
    const string atmClientsFileName = "Clients.txt";

    struct sClient
    {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        double AccountBalance;
        bool MarkForDelete = false;
        string date = NULL;
    };

    sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
    {
        sClient Client;
        vector<string> vClientData;
        vClientData = mString::SplitString(Line, Seperator);
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]); // cast string to doublereturn Client;
        return Client;
    };

    void showAnErrerMesage(string SearchWord)
    {

        cout << "The User With Account Number (" << SearchWord << ") Not Found :(";
    }

    bool SearchToFintTheClient(vector<sClient> vClient, sClient &TheWantedClient, string SearchWord)
    {
        for (sClient Client : vClient)
        {

            if (Client.AccountNumber == SearchWord)
            {
                TheWantedClient = Client;

                return true;
            }
        }

        return false;
    };

    void ShowClientData(sClient Clinet)
    {
        cout << "Account Number : " << Clinet.AccountNumber << endl;
        cout << "Pin Code       : " << Clinet.PinCode << endl;
        cout << "Client Name    : " << Clinet.Name << endl;
        cout << "Client Phone   : " << Clinet.Phone << endl;
        cout << "Account Balance: " << Clinet.AccountBalance << endl;
    }

    vector<sClient> LoadCleintsDataFromFile(string FileName)
    {
        vector<sClient> vClients;
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        // read Mode
        if (MyFile.is_open())
        {
            string Line;
            sClient Client;
            while (getline(MyFile, Line))
            {
                Client = ConvertLinetoRecord(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    };

    bool FindClientByAcountNumberAndPinCode(string AccountNumber, string PinCode, myFiles::sClient &Client)
    {

        vector<myFiles::sClient> vClient = myFiles::LoadCleintsDataFromFile(atmClientsFileName);

        for (myFiles::sClient C : vClient)
        {

            if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
            {
                Client = C;
                return true;
            }
        }
        return false;
    }

    bool FindClientByAccountNumber(string AccountNumber, sClient &Client)
    {
        vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
        for (sClient C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;
    };

    bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient &Client)
    {
        for (sClient C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;
    }

    void PrintClientCard(sClient Client)
    {
        cout << "\nThe following are the client details:\n";
        cout << "\nAccout Number: " << Client.AccountNumber;
        cout << "\nPin Code     : " << Client.PinCode;
        cout << "\nName         : " << Client.Name;
        cout << "\nPhone        : " << Client.Phone;
        cout << "\nAccount Balance: " << Client.AccountBalance;
    };

    sClient ChangeClientRecord(string AccountNumber)
    {
        sClient Client;
        Client.AccountNumber = AccountNumber;
        cout << "\n\nEnter PinCode? ";
        getline(cin >> ws, Client.PinCode);
        cout << "Enter Name? ";
        getline(cin, Client.Name);
        cout << "Enter Phone? ";
        getline(cin, Client.Phone);
        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;
        return Client;
    }

    string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.AccountNumber + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += Client.Name + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;
    }

    vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out); // overwrite
        string DataLine;
        if (MyFile.is_open())
        {
            for (sClient C : vClients)
            {
                if (C.MarkForDelete == false)
                { // we only write records that are not marked for delete.
                    DataLine = ConvertRecordToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
        return vClients;
    }

    bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
    {
        sClient Client;
        char Answer = 'n';
        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);
            cout << "\n\nAre you sure you want update this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                for (sClient &C : vClients)
                {
                    if (C.AccountNumber == AccountNumber)
                    {
                        C = ChangeClientRecord(AccountNumber);
                        break;
                    }
                }
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nClient Updated Successfully.";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
        }
    };

    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient> &vClients)
    {
        for (sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.MarkForDelete = true;
                return true;
            }
        }
        return false;
    };

    bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
    {
        sClient Client;
        char Answer = 'n';
        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);
            cout << "\n\nAre you sure you want delete this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
                SaveCleintsDataToFile(ClientsFileName, vClients);
                // Refresh Clients
                vClients = LoadCleintsDataFromFile(ClientsFileName);
                cout << "\n\nClient Deleted Successfully.";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
        };
    }

    void PrintClientRecord(sClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(40) << left << Client.Name;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

    void PrintAllClientsData(vector<sClient> vClients)
    {
        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        for (sClient Client : vClients)
        {
            PrintClientRecord(Client);
            cout << endl;
        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    };

    void AddDataLineToFile(string FileName, string stDataLine)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    };

    sClient ReadNewClient()
    {
        sClient Client;
        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
        cout << "Enter PinCode? ";
        getline(cin, Client.PinCode);
        cout << "Enter Name? ";
        getline(cin, Client.Name);
        cout << "Enter Phone? ";
        getline(cin, Client.Phone);
        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;
        return Client;
    }

    vector<sClient> LaodClientsDataFromFile(string FileName)
    {

        fstream MyFile;

        vector<sClient> vClients;

        MyFile.open(FileName, ios::in); // read mode onle

        if (MyFile.is_open())
        {

            string line;
            sClient Client;

            while (getline(MyFile, line))
            {
                Client = ConvertLinetoRecord(line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

}
