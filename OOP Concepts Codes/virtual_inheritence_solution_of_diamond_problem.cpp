#include <iostream>
using namespace std;

class A
{
    int dA;

public:
    A()
    {
        dA = 0;
        cout << "A's Default Constructor" << endl;
    }
    A(int dA)
    {
        this->dA = dA;
        cout << "A's Parametrize Constructor" << endl;
    }
    A(const A &obj)
    {
        dA = obj.dA;
        cout << "A's Copy Constructor" << endl;
    }

    virtual ~A() //Always make base class destructor virual, to avoid memmory leaks.
    {
        cout << "A's Destructor" << endl;
    }

    //Vitual display Function
    virtual void display() //display() would be overriden in child classe(s).
    {
        cout << "dA = " << dA << endl;
    }

    //Virtual test Function
    virtual void test() //test() would be overriden in child classe(s).
    {
        cout << "Class A's test Function" << endl;
    }
};

class B : virtual public A //B inherits all the features of A except Constructors, Destructor, Assignment-operator and V-Table.
{
    int dB;

public:
    B()
    {
        dB = 0;
        cout << "B's Default Constructor" << endl;
    }
    B(int dA, int dB) : A(dA) //calling A's parameterized constructor
    {
        this->dB = dB;
        cout << "B's Parametrize Constructor" << endl;
    }
    B(const B &obj) : A(obj) //calling A's copy constructor. The object of child class can be assigned to its parent.
    {
        dB = obj.dB;
        cout << "B's Copy Constructor" << endl;
    }

    ~B() //B's destructor is also virtual
    {
        cout << "B's Destructor" << endl;
    }
};

class C : virtual public A //C inherits all the features of A except Constructors, Destructor, Assignment-operator and V-Table
{
    int dC;

public:
    C()
    {
        dC = 0;
        cout << "C's Default Constructor" << endl;
    }
    C(int dA, int dC) : A(dA) //calling A's parameterized constructor
    {
        this->dC = dC;
        cout << "C's Parametrize Constructor" << endl;
    }
    C(const C &obj) : A(obj) //calling A's copy constructor. The object of child class can be assigned to its parent.
    {
        dC = obj.dC;
        cout << "C's Copy Constructor" << endl;
    }

    ~C() //C's destructor is also virtual
    {
        cout << "C's Destructor" << endl;
    }
};

//Sequence Matters,,, 1st-> B , then 2nd-> C class's features comes in class C
class D : public B, public C //C inherits all the features of B and C except Constructors, Destructor, Assignment-operator and V-Table
{
    int dD;

public:
    D()
    {
        dD = 0;
        cout << "D's Default Constructor" << endl;
    }
    D(int dA, int dB, int dC, int dD) : B(dA, dB), C(dA, dC) //calling B's and C's parameterized constructors.
    {
        this->dD = dD;
        cout << "D's Parametrize Constructor" << endl;
    }
    D(const D &obj) : B(obj), C(obj) //calling B's and C's copy constructors. The object of child class can be assigned to its parent.
    {
        dD = obj.dD;
        cout << "D's Copy Constructor" << endl;
    }

    ~D() //D's destructor is also virtual
    {
        cout << "D's Destructor" << endl;
    }
};

int main()
{
    D od;

    od.test(); //--->> VALID!!! Bcz 'A' class is now virtually inherited in 'B' and 'C' classes(which means both 'B' and 'C' classes contains each additional pointer in them which points towards class A). Thus, object D (od) can now choose only one pointer as a path to go to test function of 'A'. Thus, 'od' does not became ambiguous here.

    od.display(); //--->> VALID!!! Bcz 'A' class is now virtually inherited in 'B' and 'C' classes(which means both 'B' and 'C' classes contains each additional pointer in them which points towards class A). Thus, object D (od) can now choose only one pointer as a path to go to display function of 'A'. Thus, 'od' does not became ambiguous here.
    return 0;
}