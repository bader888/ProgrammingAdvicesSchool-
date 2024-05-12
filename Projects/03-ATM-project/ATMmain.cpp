#include "../lib/mFile.h"
#include "../lib/myReadLib.h"
#include "../lib/mCheckLib.h"
#include "../lib/mGlobal.h"
#include "../lib/numberToWordsExtintion.h"

// Global
void ShowMainMenue();

void Login();

const string ClientsFileName = "Clients.txt";

myFiles::sClient CurrentClient;

int arrQuickWithdrawOprions[8] = {
    20,
    50,
    100,
    200,
    400,
    600,
    800,
    1000,
};

enum en_ATM_MainMenueOptions
{
    enQuickWithDraw = 1,
    enNormalWithDraw = 2,
    enDeposit = 3,
    enCheckBalance = 4,
    enLogout = 5,
};

void GoBackTo_ATM_MainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

// perform transaction atm task
void PrintClientBalance()
{
    cout << "\nYour Balance Is: ";
    cout << CurrentClient.AccountBalance;
    cout << " ( " << Text::ConvertNumberToText(CurrentClient.AccountBalance) << " )";
}

void PrintClientName()
{
    cout << CurrentClient.Name;
}

// perform Quick WithDraw Option
void PrintQuickWithdrawOptions()
{

    for (short i = 0; i < 8; i++)
    {

        printf("[%d] %-4d    ", i + 1, arrQuickWithdrawOprions[i]);
        if (i % 2 != 0)
        {
            cout << endl;
        };
    };
    cout << "[9] Exit";
    cout << "\n========================================\n";
};

bool CheckAccountBalance(double AccountBalance, int WithDrawAmount)
{

    return (WithDrawAmount % 5 == 0 && WithDrawAmount < AccountBalance);
}

bool QuickWithDraw(string AccountNumber, int Number, vector<myFiles::sClient> &vClients)
{

    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

        if (CurrentClient.AccountNumber == AccountNumber)
        {
            CurrentClient.AccountBalance -= arrQuickWithdrawOprions[Number - 1];

            myFiles::SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nDone Successfully. New balance is: " << CurrentClient.AccountBalance;

            cout << " (" << Text::ConvertNumberToText(CurrentClient.AccountBalance) << ")";

            return true;
        }

        return false;
    }
}

// perform Normal WithDraw Option
bool NormalWithDraw(string AccountNumber, int WithDrawAmount, vector<myFiles::sClient> &vClients)
{

    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

        if (CurrentClient.AccountNumber == AccountNumber)
        {
            CurrentClient.AccountBalance -= WithDrawAmount;

            myFiles::SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nDone Successfully. New balance is: " << CurrentClient.AccountBalance;

            cout << " (" << Text::ConvertNumberToText(CurrentClient.AccountBalance) << ")";

            return true;
        }

        return false;
    }
}

// perform deposit
bool DepositBalance(string AccountNumber, double Amount, vector<myFiles::sClient> &vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {

        for (myFiles::sClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                myFiles::SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
                cout << " (" << Text::ConvertNumberToText(C.AccountBalance) << ")";
                return true;
            }
        }

        return false;
    }
}

// prtfrom all tasks
void Perfrom_ATM_MainMenueOption(en_ATM_MainMenueOptions ATM_MainMenueOption)
{
    switch (ATM_MainMenueOption)
    {
    case en_ATM_MainMenueOptions::enQuickWithDraw:
    {
        system("cls");
        ShowQuickWithDarwScreen();
        GoBackTo_ATM_MainMenue();
        break;
    }
    case en_ATM_MainMenueOptions::enNormalWithDraw:
        system("cls");
        ShowNormalWithDarwScreen();
        GoBackTo_ATM_MainMenue();
        break;

    case en_ATM_MainMenueOptions::enDeposit:
        system("cls");
        ShowDeopsitScreen();
        GoBackTo_ATM_MainMenue();
        break;

    case en_ATM_MainMenueOptions::enCheckBalance:
        system("cls");
        ShowCheckBalanceScreen();
        GoBackTo_ATM_MainMenue();
        break;

    case en_ATM_MainMenueOptions::enLogout:
        system("cls");
        ShowLogInScreen();
        Login();
        break;
    }
}

// show section
void ShowQuickWithDarwScreen()
{
    mGlobal::showMessage("Quick WithDraw Screen");

    short ClientChose = 0;

    vector<myFiles::sClient> vClients = myFiles::LoadCleintsDataFromFile(ClientsFileName);

    PrintQuickWithdrawOptions();

    PrintClientBalance();

    cout << "\nChose What to withdraw From [1] to [9] : ";

    cin >> ClientChose;

    mReadLib::ValidateNumber(ClientChose, 1, 9);

    if (ClientChose == 9)
        return GoBackTo_ATM_MainMenue();

    if (!CheckAccountBalance(CurrentClient.AccountBalance, arrQuickWithdrawOprions[ClientChose - 1]))
        cout << "You Don't Have This Amount Of Money ... !";
    else
        QuickWithDraw(CurrentClient.AccountNumber, ClientChose, vClients);
};

void ShowNormalWithDarwScreen()
{
    mGlobal::showMessage("Normal WithDraw Screen");

    vector<myFiles::sClient> vClients = myFiles::LoadCleintsDataFromFile(ClientsFileName);

    short WithDrawAmount = 0;

    cout << "\nEnter an Amount Multiple of 5's ? ";
    cin >> WithDrawAmount;

    while (!CheckAccountBalance(CurrentClient.AccountBalance, WithDrawAmount))
    {
        cout << "\nInvalid Amount , try Another Amount: ";

        cin >> WithDrawAmount;
    }

    NormalWithDraw(CurrentClient.AccountNumber, WithDrawAmount, vClients);
}

void ShowDeopsitScreen()
{
    mGlobal::showMessage("Deposit Screen");

    vector<myFiles::sClient> vClients = myFiles::LoadCleintsDataFromFile(ClientsFileName);

    double AmountBalance = mReadLib::ReadPostiveNumber("Enter a Positive Deposit Amount ? ");

    DepositBalance(CurrentClient.AccountNumber, AmountBalance, vClients);
}

void ShowCheckBalanceScreen()
{
    mGlobal::showMessage("Check Balance Screen");
    cout << "\nHI ";
    PrintClientName();
    PrintClientBalance();
}

void ShowLogInScreen()
{
    mGlobal::showMessage("LogIn Screen");
}

void ShowMainMenue()
{
    mGlobal::ClearTheScreen();
    mGlobal::showMessage("ATM Main Menue Screen");

    cout << "\t[1] Quick WithDraw.\n";
    cout << "\t[2] Normal WithDraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";

    Perfrom_ATM_MainMenueOption((en_ATM_MainMenueOptions)mReadLib::Read_ATM_MainMenueOption());
}

// log In section
bool LoadClientInfo(string Username, string Password)
{

    if (myFiles::FindClientByAcountNumberAndPinCode(Username, Password, CurrentClient))
        return true;
    else
        return false;
};

void Login()
{
    bool LoginFaild = false;

    string AcountNumber, PinCode;
    do
    {
        mGlobal::ClearTheScreen();

        mGlobal::showMessage("LogIn Screen");

        if (LoginFaild)
        {
            mGlobal::PrintInValidMsg(" Invlaid AcountNumber / Password !");
        }

        cout << "Enter AcountNumber? ";
        cin >> AcountNumber;

        cout << "Enter PinCode? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AcountNumber, PinCode);

    } while (LoginFaild);

    ShowMainMenue();
}

int main()
{
    
    Login();

    return 0;

}