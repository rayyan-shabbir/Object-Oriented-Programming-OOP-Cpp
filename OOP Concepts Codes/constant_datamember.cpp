#include <iostream>
using namespace std;

class Algebra {
    int a, b;
    const int c;
    public: 
        //Default Constructor
        Algebra () : c(0)
        {
            a = b =0;
        }

        //Parametrize Constructor
        Algebra (int a1, int b1, int c1) : c(c1) 
        {
            a = a1;
            b = b1;
        }

        //Copy Constructor
        Algebra (Algebra &obj) : c(obj.c)
        {
            a = obj.a;
            b = obj.b;
        }

        int add(int a1, int b1) 
        {
            a = a1;
            b = b1;

            return a+c;
            
        }

        void print () {
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout << "c: " << c << endl;
        }
};

int main() {
    Algebra obj1, obj2(1, 2, 3);
    Algebra obj3(obj2);

    cout << "Deafult Constructor..." << endl;
    obj1.print();

    cout << "Parametrize Constructor..." << endl;
    obj2.print();
    
    cout << "Copy Constructor..." << endl;
    obj3.print();


    obj3.add(1, 2);
    return 0;
}