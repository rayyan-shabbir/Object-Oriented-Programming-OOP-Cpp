#include <iostream>
#include "fstream"
using namespace std;

int main() {
    ofstream outf("output.txt", ios::out);
    ifstream inf("input.txt", ios::in);

    if(!outf) {
        cout << "ERROR!";
        exit(0);
    }

    if(!inf) {
        cout << "ERROR!";
        exit(0);
    }

    int arr[11];

    while(!inf.eof()) {
        for(int i = 0; i < 11; i++)  inf >> arr[i];

        int h1 = arr[1];
        int h2 = arr[1];

        for(int i = 2; i < 11; i++) {
            if(h1 < arr[i]) h1 = arr[i];
        }

        for(int i = 2; i < 11; i++) {
            if(h2 < arr[i] && arr[i] != h1) h2 = arr[i];
        }

        outf << arr[0] << " " << h1 << " " << h2 << endl;
    }

    outf.close();
    inf.close();
    return 0;
}