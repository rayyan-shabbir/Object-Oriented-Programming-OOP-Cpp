#include "iostream"
using namespace std;

class Algebra {
	int a;
	static int s;
	public: 
		Algebra();
		Algebra(int, int);
		~Algebra();
		void setA(int);
        int getA();
		static void setObjc(int);
		static int getObjc();
		void print();
};

int Algebra::s;

Algebra::Algebra() {
	a = 0;
}
Algebra::Algebra(int a, int b) {
	this->a = a;
}
Algebra::~Algebra() {
	cout << "Destructor executed" << endl;
}
void Algebra::setA(int a) {
	this->a = a;
}
int Algebra::getA() {
	return a;
}
void Algebra::setObjc(int s1) {
	Algebra::s = s1;
}

int Algebra::getObjc() {
	return s;
}

void Algebra::print() {
	cout << "a: " << a << endl;
}

int main() {
	Algebra obj1;

	obj1.setA(5);
	//obj1.print();

	Algebra::setObjc(8);
	cout << Algebra::getObjc() << endl;
	//cout << obj1.getA() << endl;
	return 0;
}
