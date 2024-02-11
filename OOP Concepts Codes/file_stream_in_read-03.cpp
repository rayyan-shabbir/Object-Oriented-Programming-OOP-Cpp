#include <iostream>
#include "fstream"
using namespace std;

int main() {
    int id;
    string str;

    //Opening File using Member open() Function and READING from it
    ifstream inf1;      
    inf1.open("test1.txt", ios::in);
    getline(inf1, str);
    cout << str;

    inf1.close();

    cout << endl;

    //Opening File using Constructor and READING from it.
    ifstream inf2("test2.txt", ios::in);     //READ Operation

    while(inf2 >> id >> str) {
        cout << id << " " << str << endl;
    }
    
    inf2.close();
    return 0;
}