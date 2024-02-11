
#include "iostream"

using namespace std;

class Algebra
{
	//data members of the class
	int a, b;

public:

	//Default Constructor
	Algebra()
	{
		this->a = this->b = 0;
	}

	//Parameterized Constructor
	Algebra(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

    //making stream-insertion global operator a friend of Algebra
	friend ostream& operator<< (ostream& c, const Algebra& d);
	
	
};

//overloaded stream-insertion << operator
ostream& operator<< (ostream& out, const Algebra &obj) {
	out << "a: " << obj.a << " b: " << obj.b << endl;

	return out;
}



int main()
{
	Algebra obj1(1, 2), obj2(3, 4);

	cout << obj1 << obj2;

	return 0;
}