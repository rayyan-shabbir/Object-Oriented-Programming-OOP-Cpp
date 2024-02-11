#include <iostream>
using namespace std;

class A {
	int dA;
	public:
		A() {
			dA = 0;
			cout << "A's Default Constructor" << endl;
		}
		A(int dA) {
			this->dA = dA;
			cout << "A's Parametrize Constructor" << endl;
		}
		A(const A &obj) {
			dA = obj.dA;
			cout << "A's Copy Constructor" << endl;
		}
        
		virtual ~A()     //Always make base class destructor virual, to avoid memmory leaks.
        {          
			cout << "A's Destructor" << endl;
		}

		void display()          
        {
			cout << "dA = " << dA << endl;
		}

        //Virtual test Function
		virtual void test()    //test() would be overriden in child classe(s).         
        {
			cout << "Class B's test Function" << endl;
		}           
        
};

class B    //B inherits all the features of A except Constructors, Destructor, Assignment-operator and V-Table.
{
	int dB;
	public:
		B() {
			dB = 0;
			cout << "B's Default Constructor" << endl;
		}
		B(int dB)
		{
			this->dB = dB;
			cout << "B's Parametrize Constructor" << endl;
		}
		B(const B &obj)
		{
			dB = obj.dB;
			cout << "B's Copy Constructor" << endl;
		}

		virtual ~B()            //Always make base class destructor virual, to avoid memmory leaks.
        {
			cout << "B's Destructor" << endl;
		}

        //Vitual display Function
		virtual void display()          //display() would be overriden in child classe(s).
        {
			cout << "dB = " << dB << endl;
		}

        //Virtual test Function
		virtual void test()        //test() would be overriden in child classe(s).
        {
			cout << "Class B's test Function" << endl;
		}
};

//Sequence Matters,,, 1st-> A , then 2nd-> B class's features comes in class C
class C : public A, public B    //C inherits all the features of A and B except Constructors, Destructor, Assignment-operator and V-Table
{
	int dC;
	public:
		C() {
			dC  = 0;
			cout << "C's Default Constructor" << endl;
		}
		C(int dA, int dB, int dC) : A(dA) , B(dB)  //calling A's and B's parameterized constructors.
		{
			this->dC = dC;
			cout << "C's Parametrize Constructor" << endl;
		}
		C(const C &obj) : A(obj), B(obj)    //calling A's and B's copy constructors. The object of child class can be assigned to its parent.
		{
			dC = obj.dC;
			cout << "C's Copy Constructor" << endl;
		}

		~C()                //C's destructor is also virtual
        {
			cout << "C's Destructor" << endl;
		}

		void display()          //overriden function. display() is also virtual here only by parent class B, not by parent class A.
        {
			A::display();     //making a call to A(parent) class' display member function
            B::display();     //making a call to B(parent) class' display member function
			cout << "dC = " << dC << endl;
		}

        //Overriden function. test() remains virtual only for parent class B, not for parent class A.
		void test()           
        {
			cout << "Class C's test Function" << endl;
		}
};

int main() {
    C oc(1, 2, 3);
    cout << "--> 'C' dsiplay function will print." << endl;
    oc.display();  //--> 'C' dsiplay function will print.
    cout << endl << endl;

    A* pa = &oc;
    cout << "//--> 'A' pointers type display function will print" << endl;
    pa->display();   //--> 'A' pointers type display function will print
    cout << endl << endl;

    B* pb = &oc;     
    cout << "//--> 'C' objects type display function will print" << endl;
    pb->display();  //--> 'C' objects type display function will print
    cout << endl << endl;

	return 0;
}