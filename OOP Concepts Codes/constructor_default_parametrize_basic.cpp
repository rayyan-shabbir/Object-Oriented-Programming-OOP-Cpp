#include "iostream"
using namespace std;

class Algebra {
    int a, b;
    public:
        Algebra() {
           cout << "Default Constructor" << endl;
         a = b = 0;
        }

        Algebra(int x, int y) {
            cout << "Parametrize Constructor" << endl;
            a = x;
            b = y;
        }

        void display() {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }


};

int main() {
    Algebra obj1, obj2(1, 2);

    obj1.display();
    obj2.display();
    return 0;
}