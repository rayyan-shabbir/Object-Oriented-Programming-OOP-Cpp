#include <iostream>
using namespace std;

class Algebra {
    int a, b;
    const int c;

    public: 
        Algebra () : c(0)
        {
            a = b = 0;
        }

        Algebra (int a, int b, int c1) :c(c1)
        {
            this->a = a;
            this->b = b;
        }

        void print () {
            cout << "a: " << a << "\tb: " << b << endl;
        }

};

int main() {
    Algebra obj1, obj2(2, 4, 5);
    obj1.print();
    obj2.print();
    return 0;
}