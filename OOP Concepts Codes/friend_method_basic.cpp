#include <iostream>
using namespace std;

class Algebra {
    int a, b;

    public:
        Algebra (int a1, int b1) {
            a = a1;
            b = b1;
        }
        friend void test();
};

void test() {
    Algebra obj(1, 2);

    cout << "a: " << obj.a << " b: " << obj.b << endl;
}
int main() {
    test();
    return 0;
}