#include "iostream"
using namespace std;

class Algebra {
    int a, b;
    public: 
        Algebra (int a1, int b1) {
            a = a1;
            b = b1;
        }
        void print() const 
        {
            // a = 5; // --> ERROR!!!!!!!!!!!!!!

            cout << "a: " << a << "\tb: " << b << endl;
        }
};

int main() {
    const Algebra obj1(1, 2);
    obj1.print();
    return 0;
}