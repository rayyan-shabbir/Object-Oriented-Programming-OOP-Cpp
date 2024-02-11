#include <iostream>
using namespace std;

class Algebra {
    int a, b ;
    public: 
        void print() {
            cout << this << endl; //Adress of calling obj
        }
};

int main() {
    Algebra obj1, obj2;
    obj1.print();
    cout << &obj1 << endl;
    return 0;
}