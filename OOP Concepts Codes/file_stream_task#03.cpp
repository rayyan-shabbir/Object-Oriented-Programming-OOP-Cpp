#include <iostream>
#include "fstream"
using namespace std;

int main() {
    int arr[11];
    ifstream inf("input.txt", ios::in);

    if(!inf) {
        cout << "ERROR!";
        exit(0);
    }

    while(!inf.eof()) {
        for(int i = 0; i < 11; i++) inf >> arr[i];

        int highest = arr[1];

        for (int i = 2; i < 11; i++) {
            if(highest < arr[i]) highest = arr[i];
        }

        for (int i = 0; i < 11; i++){
            cout << arr[i] << " ";
        }
        cout << highest << endl;
    }

    inf.close();
    return 0;
}