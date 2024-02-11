#include <iostream>
using namespace std;

int main() {
    int a = 8;
    a = 99;
    cout << "A = " << a << endl;

    const int b = 7;
    //b = 55; // this gives and error
    cout << "B = " << b << endl;
    return 0;
}