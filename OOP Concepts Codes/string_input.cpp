#include <iostream>
using namespace std;

int main(){
    string name1;
    string name2;
   
    cout << "Enter your name 1: ";
    getline(cin, name1);
    cout << "Your name 1 is " << name1 << endl;

    cout << "Enter your name 2: ";
    cin >> name2;
    cout << "Your name 2 is " << name2 << endl;
    return 0;
}