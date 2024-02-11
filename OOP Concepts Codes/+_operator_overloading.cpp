#include "iostream"
using namespace  std;

class Algebra {
    int a, b;

    public:
        Algebra () {
            a = 0;
            b = 0;
        }

        Algebra (int a1, int b1)
        {
            a = a1;
            b = b1;
        }

        //OVERLOADED BINARY + OPERATOR
        Algebra operator+ (const Algebra &obj) const
        {
            //Algebra temp(a + obj.a, b + obj.b);
            
            Algebra temp;
            temp.a = a + obj.a;
            temp.b = b + obj.b; 

            return temp;

            //return Algebra(a+obj.a, b+obj.b);

        }

        void print () {
            cout << "a: " << a << endl << "b: " << b << endl;
        }

};

int main() {
    Algebra obj1(1, 2), obj2(4, 5), obj3(7, 9);
    //obj1.operator+(obj2).print();

    Algebra r = obj1 + obj2 + obj3;
    r.print();

    // c = a + b
    // obj1 + obj2;
    // obj1.opeartor+(obj2);

    //((obj1.operator+(obj2)).operator+(obj3)).print();
    return 0;
}