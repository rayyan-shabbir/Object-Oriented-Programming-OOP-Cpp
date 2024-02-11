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

    //OVERLOADED == OPERATOR
    bool operator== (const Algebra &obj) const
    {
        //if ((a == obj.a) && (b == obj.b) && (c == obj.c)) return true;
        //return false;

        return ((a == obj.a) && (b == obj.b) && (c == obj.c));
    }

    //OVERLOADED != OPERATOR
    bool operator!= (const Algebra &obj) const 
    {
        //if ((a == obj.a) && (b == obj.b) && (c == obj.c)) return false;
        //return true;
        
        return !(*this == obj);
    }

};


int main() {
    Algebra obj1(1, 2, 3), obj2(4, 5, 6);

    // cout << obj1 == obj2;
    cout << (obj1.operator==(obj2)) << endl;

    cout << (obj1 != obj2) << endl;
    
    return 0;
}