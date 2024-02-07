#include <iostream>
#include <string>
using namespace std;
string ReadWord(string message)
{
    string word = "";

    do
    {
        cout << message << endl;
        getline(cin, word);
    } while (word == "");

    return word;
}

void GuessPasswordOf3_letters(string passWord)
{
    string word = "";
    int count = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                if (word == passWord)
                {
                    cout << "passWord found after trial"
                         << "[" << count << "]";
                }
                else
                {

                    cout << "trial"
                         << "[" << count << "]: " << word;
                    word = "";
                }
            }
        }
    }
};
////////////ANOTHER SOLUTION
string ReadPassWord()
{
    string passWord = "";
    cout << "enter password 3-letter cabital";
    cin >> passWord;

    return passWord;
}

bool GuessPassWord(string OriginalPassWord)
{
    string word = "";
    int count = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << "trial"
                     << "[" << count << "]: " << word << endl;

                if (word == OriginalPassWord)
                {
                    cout << "\nthe passWord is: " << word;
                    cout << "passWord found after trial"
                         << "[" << count << "]";
                    return true;
                }
                word = "";
            }
        }
    }
}
int main()
{

    GuessPassWord(ReadPassWord());

    return 0;
};