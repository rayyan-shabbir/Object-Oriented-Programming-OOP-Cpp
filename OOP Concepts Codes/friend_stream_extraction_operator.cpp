
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

	//making stream-extraction global operator a friend of Algebra
	friend istream& operator>> (istream& c, Algebra &f);
};


//overloaded stream-extraction >> operator
istream& operator>> (istream& in, Algebra &obj) {
	cout << "Enter a: ";
	in >> obj.a;

	cout << "Enter b: ";
	in >> obj.b;

	return in;
}

//overloaded stream-insertion << operator
ostream& operator<< (ostream& out, const Algebra &obj) {
	out << "a: " << obj.a << " b: " << obj.b << endl;

	return out;
}

int main()
{
	Algebra obj1;

	cin >> obj1;
	cout << obj1;

	return 0;
}