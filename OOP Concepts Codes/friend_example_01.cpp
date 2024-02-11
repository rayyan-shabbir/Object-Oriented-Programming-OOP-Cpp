#include <iostream>
using namespace std;

class Algebra {
    int a, b;

    public:
        void setAlgebra(int n1, int n2) {
            a = n1;
            b = n2;
        }

        void print() {
            cout << "Your number is: " << a << " + " << b << endl;
        }

        friend Algebra sum(Algebra o1, Algebra o2);
};


Algebra sum(Algebra o1, Algebra o2) {
    Algebra o3;

    o3.setAlgebra((o1.a + o2.a), (o1.b + o2.b));

    return o3;
}


int main() {
    Algebra o1, o2, o3;

    o1.setAlgebra(1, 2);
    o2.setAlgebra(4, 7);

    o1.print();
    o2.print();

    o3 = sum(o1, o2);

    o3.print();
    sum(o1, o2);

    return 0;
}


/*
1- Outside class boundry
2- 

*/