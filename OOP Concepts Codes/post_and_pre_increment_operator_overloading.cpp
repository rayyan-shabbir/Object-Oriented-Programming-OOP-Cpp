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

    //OVERLOADED PRE-INCREMENT ++ OPERATOR (UNARY)
    Algebra operator++()
    {
        ++a;
        ++b;

        return *this;
    }

    //OVERLOADED POST-INCREMENT ++ OPERATOR (UNARY)
    Algebra operator++(int)
    {
        Algebra oldState(*this);
        //OR
        //Algebra oldState(a, b, c);

        ++a;
        ++b;

        return oldState;
    }

    //OVERLOADED = OPERATOR
    Algebra operator=(const Algebra &obj)
    {
        if (this != &obj)
        {
            a = obj.a;
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

    obj2 = ++obj1;
    //obj2 = obj1.operator++();

    cout << "Pre Increment" << endl;
    obj1.print();
    obj2.print();

    obj2 = obj1++;

    cout << "Post Increment" << endl;
    obj1.print();
    obj2.print();
    return 0;
}