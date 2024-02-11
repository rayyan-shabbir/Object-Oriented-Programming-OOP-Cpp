#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a = 7, b = 257, c = 83621;
    cout << "Hello World" << endl; //endl is a manipulator
    cout << "Value of a = " << setw(5) << a << endl;
    cout << "Value of b = " << setw(5) << b << endl;
    cout << "Value of c = " << setw(5) << c << endl;

}