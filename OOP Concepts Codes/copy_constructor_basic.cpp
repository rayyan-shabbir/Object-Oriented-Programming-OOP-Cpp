#include <iostream>
using namespace std;

class Algebra {
    int a, b;
    public: 
        Algebra(int a1, int b1) {
            cout << "Parametrize Constructor" << endl;
            a = a1, b = b1;
        }

        Algebra(const Algebra &obj) {
            cout << "Copy Constructor" << endl;
            a = obj.a;
            b = obj.b;
        }

        void display() {
            cout << "a = " << a << " b = " << b << endl;
        }
};

int main() {
    Algebra obj1(1, 2), obj2(3, 4), obj3(0, 0); //Parametrize constructor

    Algebra obj4(obj2); //Copy constructor
    
    obj3 = obj2; //No Copy constructor

    obj1.display();
    obj2.display();
    obj3.display();
    obj4.display();
    return 0;
}