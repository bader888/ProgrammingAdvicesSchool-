#include <iostream>
#include <string>
using namespace std;

string readText()
{
    string name;
    cout << "enter your name: ";
    getline(cin, name);

    return name;
};

string encyptText(string text, short encryptKey)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] + encryptKey);
    }

    return text;
}

string decryptText(string text, short encryptKey)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] - encryptKey);
    };
    return text;
}
int main()
{
    short key = 2; // this is the key

    string text = readText();

    cout << "name before encryption: " << text << endl;
    cout << "name after encryption: " << encyptText(text, key) << endl;
    cout << "name after decrypttion: " << decryptText(text, key) << endl;
    return 0;
};