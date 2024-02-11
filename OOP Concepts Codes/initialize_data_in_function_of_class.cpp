#include "iostream"
using namespace std;

class Algebra {

    int a, b;

    public:
        void setData(int a1, int b1) {
           a = a1;
           b = b1;
        }

        void print() {
            cout << "a = " << a << "\tb = " << b << endl;
        }

        int add() {
            return a+b;
        }

        int subt() {
            return a-b;
        }

        int mult() {
            return a*b;
        }

        float div() {
            return static_cast<float> (a) / b;
        }
};

int main() {
    Algebra obj1, obj2;

    obj1.setData(1, 2);
    obj2.setData(3, 4);

    obj1.print();
    obj2.print();
    
    cout << "Add obj1 = " << obj1.add() << endl;
    cout << "Subt obj2 = " << obj2.subt() << endl;
    cout << "Mult obj2 = " << obj2.mult() << endl;
    cout << "Div obj1 = " << obj1.div() << endl;
    return 0;
}