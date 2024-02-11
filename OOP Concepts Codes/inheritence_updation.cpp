#include <iostream>
using namespace std;

//A is Parent / Base Class
class A 
{
    int dA;

    public:
        A() {
            dA = 0;
            cout << "A's Default Constructor." << endl;
        }

        A(int dA) {
            this->dA = dA;
            cout << "A's Parameterized Constructor." << endl;
        }

        A(const A &oa) {
            dA = oa.dA;
            cout << "A's Copy Constructor." << endl;
        }

        ~A() {
            cout << "A's Destructor" << endl;
        }

        void print() {
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
            cout << "B's Default Constructor." << endl;
        }

        B(int dA, int dB) : A(dA)   //calling A's parameterized constructor
        {
            this->dB = dB;
            cout << "B's Parameterized Constructor." << endl;
        }

        B(const B &ob) : A(ob)    //calling A's copy constructor. The object of child class can be assigned to its parent.
        {
            dB = ob.dB;
            cout << "B's Copy Constructor." << endl;
        }
        ~B() {
            cout << "B's Destructor" << endl;
        }

        void print() {
            A::print();       //making a call to A(parent) class' print member function

            cout << "dB = " << dB << endl;
        }
};


int main() {
    A oa(5);
	B ob(1, 2);

    ob.A::print();  //making a call to A(parent) class' print member function

    ob.print();     //making a call to B(child) class' print member function

    oa = ob;		//The object of child class can be assigned to its parent. Because every object of B(child) class is-a object of A(parent) class. Here Compiler only takes the data member (dA) of child class(B) that exist same in parent class(A), and assign them to that data member(dA), no other data member.

    oa.print();		//A(parent) class' print member function will be called, because the call will be made on the basis of object type not on memory's type.  
    
    return 0;
}