#include <iostream>
using namespace std;

int main() {
    int a = 34;
    int &b = a; //this is reference variable
    cout << "Value of a is: " << a << endl;
    cout << "Value of a is: " << b << endl;
}