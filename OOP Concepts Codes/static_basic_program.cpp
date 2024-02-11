#include "iostream"
using namespace std;

class Algebra {
	static int objC;    //Declaration of static
	
	public:
		Algebra() {
			objC++;
		}
		~Algebra() {
			objC--;
		}
		static int getObjc() {	
			return objC;
		}
};
int Algebra::objC;   //Defination of static

void test() {
	cout << Algebra::getObjc() << endl;
	Algebra ar[5];
	cout << Algebra::getObjc() << endl;
}

int main() {
	cout << Algebra::getObjc() << endl;
	Algebra obj1, obj2, obj3;
	test();
	cout << Algebra::getObjc() << endl;
	return 0;
}