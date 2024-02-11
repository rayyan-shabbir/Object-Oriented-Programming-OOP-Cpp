#include <iostream>
#include "fstream"
using namespace std;

int main() {
    int id;
    string str;

    fstream oif("test3.txt", ios::out|ios::in);

    if(!oif) {
        cout << "ERROR!" << endl;
        exit(0);
    }

    while(cin >> id >> str) {
        oif << id << " " << str << endl;
    }
    oif.close();
    oif.open("test3.txt");

    while(oif >> id >> str) {
        cout << id << " " << str << endl;
    }
    oif.close();
    return 0;
}