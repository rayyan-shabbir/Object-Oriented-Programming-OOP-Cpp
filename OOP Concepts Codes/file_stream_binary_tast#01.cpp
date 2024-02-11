#include <iostream>
#include "fstream"
using namespace std;

void arrayToFile(string fileName, int *arr, int size) {
    ofstream outf(fileName, ios::binary);

    if(!outf) {
        cout << "ERROR!";
        exit(0);
    }

    outf.write(reinterpret_cast<char*>(arr), size*sizeof(int));
    outf.close();
}

void fileToArray(string fileName, int *arr, int size) {
    ifstream inf(fileName, ios::binary);

    if(!inf) {
        cout << "ERROR!";
        exit(0);
    }

    inf.read(reinterpret_cast<char*>(arr), size*sizeof(int));

    inf.close();
}

int main() {
    int arr1[4] = {1, 2, 3, 4};
    int size = 4;

    string fName = "binary.txt";

    arrayToFile(fName, arr1, size);

    fileToArray(fName, arr1, size);

    for(int i = 0; i < 4; i++) {
        cout << arr1[i] << endl;
    }

    return 0;
}