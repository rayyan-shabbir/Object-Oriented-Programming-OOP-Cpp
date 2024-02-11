#include <iostream>
using namespace std;

class Algebra {
    int a, b;
    static int c;

    public:
        Algebra() {
            a = 0;
            b = 0;
            Algebra::c = 0;
        }

};

int main() {
    Algebra obj1;
    cout << sizeof(obj1) << endl;
    return 0;
}