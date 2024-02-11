#include <iostream>
#include "fstream"
#include "cstdio"
using namespace std;

class A{
    public:
    int a;
    float b;
        A(int a1 = 0, float b1 = 0) : a(a1), b(b1) {

        }

        void print() {
            cout << a << " " << b << endl;
        }
};

int main() {
    ofstream outf("test.txt", ios::binary);

    A o[3] = {A(1, 1.1f), A(2, 2.2f), A(3, 3.3f)};

    outf.write(reinterpret_cast<char*>(o), 3*sizeof(A));

    outf.close();

    ifstream inf("test.txt", ios::binary);
    // fstream outf2("temp.txt", ios::binary|ios::in|ios::out);

    // A i;

    // inf.read(reinterpret_cast<char*>(&i), sizeof(A));
    
    // while(!inf.eof()) {
    //     if(i.a != 3) {
    //         outf2.write(reinterpret_cast<char*>(&i), sizeof(A));
    //         //i.print();
    //         inf.read(reinterpret_cast<char*>(&i), sizeof(A));
    //     }
    // }

    // A i2;

    // ifstream inf2("temp.txt", ios::binary);

    // inf2.read(reinterpret_cast<char*>(&i2), sizeof(A));

    // while(!inf2.eof()) {
    //     i2.print();
    //     inf2.read(reinterpret_cast<char*>(&i2), sizeof(A));
    // }

    A i[3];

    inf.read(reinterpret_cast<char*>(i), 3*sizeof(A));
    i[0].print();
    i[1].print();
    i[2].print();
    return 0;
}