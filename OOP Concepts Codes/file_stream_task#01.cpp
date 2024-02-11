#include <iostream>
#include "fstream"
using namespace std;

int main() {
    int roll;
    string fName , lName;
    float marks;

    ofstream outf("student.txt", ios::out);

    if(!outf) {
        cout << "EROOR!" << endl;
        exit(0);
    }

    while(cin >> roll >> fName >> lName >> marks) {
       outf << roll << "\t" <<fName << " " << lName << "\t" << marks << endl << endl;
    }
    outf.close();
    return 0;
}