#include <iostream>
using namespace std;

class Algebra {
    public:
        int a, b;
};

int main() {
    Algebra obj1, obj2;
    obj1.a = 1;
    obj1.b = 2;

    obj2.a = 3;
    obj2.b = 4;

    cout << obj1.a << "\t" << obj1.b << endl;
    cout << obj2.a << "\t" << obj2.b << endl;
    cout << &obj1 << endl;
    cout << &obj1.a << endl;
    cout << &obj1.b << endl;
    return 0;
}