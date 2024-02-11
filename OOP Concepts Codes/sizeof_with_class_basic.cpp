#include <iostream>
using namespace std;

class Algebra {
    int a, b;
};

int main() {
    Algebra obj1, obj2;
    cout << sizeof(obj1) << endl;
    cout << sizeof(obj2) << endl;
    cout << sizeof(Algebra) << endl;
    return 0;
}