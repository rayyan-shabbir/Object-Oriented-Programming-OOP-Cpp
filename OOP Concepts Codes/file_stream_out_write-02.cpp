#include <iostream>
#include "fstream"
using namespace std;

int main() {
    int id;
    string str;

    //Opening File using constructor and WRITING to it.
    ofstream outf("test2.txt", ios::out);   //WRITING Operation

    if(!outf) {
        cout << "ERROR!";
        exit(0);
    }

    while(cin >> id >> str) {
        outf << id << " " << str << endl;
    }
    
    outf.close();
    return 0;
}