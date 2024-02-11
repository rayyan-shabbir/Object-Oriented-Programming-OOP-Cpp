#include <iostream>
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

    //OVERLOADED -(UNARY) OPERATOR
    Algebra operator-() const
    {
        Algebra temp(-a, -b, -c);
        return temp;

        // return Algebra(-a, -b, -c);
    }

    //OVERLOADED +(UNARY) OPERATOR
    Algebra operator+() const
    {
        return Algebra(+a, +b, +c);
    }

    //OVERLOADED = OPERATOR
    Algebra operator=(const Algebra &obj)
    {
        if (this != &obj)
        {
            this->a = obj.a;
            b = obj.b;
        }

        return *this;
    }

    void print()
    {
        cout << "a: " << a << "\tb: " << b << "\tc: " << c << endl;
    }
};

int main()
{
    Algebra obj1(1, 2, 3), obj2(4, 5, 6);

    -obj1;

    Algebra r = +obj1;

    // a = 5, b = 5; 

    // a = -b; 
    // a = -6, b = 6;

    obj2 = -obj1;
    //obj2 = obj1.operator-(); 

    // a = a;
    // a = b;
    obj2 = obj1;
    // obj2.operator=(obj1);

    obj1.print();
    r.print();
    obj2.print();

    return 0;
}