#include "iostream"
using namespace std;

int* fun() {
    int a= 5;
    cout << a << endl;
    cout << &a << endl;

    return &a;
}

int main() {
    int* s = NULL;

    s = fun();
    
    cout << s << endl;
    // cout << *s << endl;
    // cout << &s << endl;
}