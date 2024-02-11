#include <iostream>
using namespace std;

int c = 45;

int main() {
    int a = 4, b = 8;
    int c = a + b;
    cout << "Local variable c = " << c << endl;
    cout << "Global variable c = " << ::c << endl; // '::' known as scope resolution operator 
    return 0;
}