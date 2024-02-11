#include "iostream"
using namespace std;

class Algebra
{
    int a, b;
    const int c;

public:
    Algebra() : c(0)
    {
        a = 0;
        b = 0;
    }

    Algebra(int a1, int b1, int c1) : c(c1)
    {
        a = a1;
        b = b1;
    }

    //OVERLOADED += OPERATOR
    Algebra operator+=(const Algebra &obj)
    {

        /*a = a + obj.a;
        b = b + obj.b;*/

        a += obj.a;
        b += obj.b;

        return *this;
    }

    void print()
    {
        cout << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl;
    }
};

int main()
{
    Algebra obj1(1, 2, 3), obj2(4, 5, 6), obj3(7, 8, 9);

    obj1 += obj2 += obj3;

    // a += b;
    // a = a + b;
    //obj1.operator+=(obj2);

    obj1.print();

    return 0;
}
