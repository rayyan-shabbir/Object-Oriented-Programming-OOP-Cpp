#include <iostream>
using namespace std;

//A is Parent / Base Class
class A 
{
    int dA;

    public:
        A() {
            dA = 0;
            cout << "A's Default Constructor" << endl;
        }

        ~A() {
            cout << "A's Destructor" << endl;
        }

        void printA() {
            cout << "dA = " << dA << endl;
        }
};

//B is Child Class
class B : public A      //B inherits all the features of A except Constructors, Destructor and Assignment-operator
{
    int dB;

    public: 
        B() {
            dB = 0;
            cout << "B's Default Constructor" << endl;
        }

        ~B() {
            cout << "B's Destructor" << endl;
        }

        void printB() {
            printA();       //making a call to A(parentA) class' print member function

            cout << "dB = " << dB << endl;
        }
};


int main() {
    A oa;
    B ob;

    // oa.printA();     //making a call to A(parent) class' printA member function

    ob.printB();    //making a call to B(child) class' printB member function

    // ob.printA();     //making a call to A(parent) class' printA member function

    // oa.printB();  -----> ERROR, Bcz A class is parent. Not inherited.
    return 0;
}