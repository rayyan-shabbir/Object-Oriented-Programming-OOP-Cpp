#include "iostream"
using namespace std;

class Algebra {
    int a, b;
    public:
        void print() {
            cout << "a = " << a << "\tb = " << b << endl;
        }
        void getData() {
            cout << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;
        }
};

int main() {
    Algebra obj1, obj2;

    obj1.getData();
    obj2.getData();

    obj1.print();
    obj2.print();

    return 0;
}