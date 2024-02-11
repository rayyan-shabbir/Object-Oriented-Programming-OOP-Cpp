#include <iostream>
using namespace std;

class Algebra {
    int a;
    static int s; //Declaration of static

    public:
       void setA(int a1, int s1) {
           a = a1;
           Algebra::s = s1;
       }
       void print() {
           cout << "a: " << a << "\ts: " << s << endl;
       }

};

int Algebra::s(0); //Defination of static

int main() {
    Algebra obj1;
    obj1.setA(5, 2);
    obj1.print();
    //cout << Algebra::c << endl;// as s is declared in private so it cannot accessible here in main
    //cout << obj1.c << endl; // as s is declared in private so it cannot accessible here by obj1
    return 0;
}