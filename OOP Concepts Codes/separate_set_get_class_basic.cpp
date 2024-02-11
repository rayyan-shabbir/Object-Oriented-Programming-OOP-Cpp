#include "iostream"
using namespace std;

class Algebra {
    int a, b;
    public:

        void setA(int a1) {
            if (a1 > 0) {
                a = a1;
            }else {
                a = 0;
            }
        }

        void setB(int b1) {
             if (b1 > 0) {
                b = b1;
            }else {
                b = 0;
            }
        }

        void setData(int a1, int b1) {
            setA(a1);
            setB(b1);
        }

        void print() {
            cout << "a = " << a << "\tb = " << b << endl;
        }
};

int main() {
    Algebra obj1, obj2;

    obj1.setData(1, 2);
    obj2.setData(-3, 4);

    obj1.print();
    obj2.print();
    return 0;
};