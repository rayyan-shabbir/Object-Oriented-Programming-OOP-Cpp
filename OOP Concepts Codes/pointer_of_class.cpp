#include "iostream"
using namespace std;

class Algebra {
    int a, b;
};

int main() {
    Algebra obj1;
    Algebra *p = &obj1;

    cout << &obj1 << endl;
    cout << p << endl;
    cout << &p << endl;
    return 0;
}