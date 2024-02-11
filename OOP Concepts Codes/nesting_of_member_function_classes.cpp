#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;

public:
    void input_binary();
    void chck_binary();
    void ones_compliment();
    void display();
};

void binary ::input_binary()
{
    cout << "Enter binary: " << endl;
    cin >> s;
}

void binary ::chck_binary()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary ::ones_compliment()
{
    chck_binary(); //This is nesting of member function
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}

void binary ::display()
{
    cout << "Displaying your binary number" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{
    binary b;
    b.input_binary();
    //b.chck_binary();
    b.ones_compliment();
    b.display();
    return 0;
}