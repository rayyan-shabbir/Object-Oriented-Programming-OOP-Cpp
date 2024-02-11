#include <iostream>
using namespace std;

class Algebra {
	int a, b;

	public:
    Algebra() {
        a = b = 1;
    }

	Algebra(int a, int b) {
		this->a = a;
		this->b = b;
	}

	friend ostream &operator<< (ostream& , const Algebra&);
};

ostream& operator<<(ostream& out, const Algebra& obj) {
	out << obj.a << "\t" << obj.b << endl;

	return out;
}

int main() {
	Algebra *p = new Algebra;
    Algebra *q = new Algebra(3, 4);

	cout << "Default Constructor" << endl << *p << endl;

    cout << "Parametrize Constructor" << endl << *q << endl;

	delete p;
    delete q;
	return 0;
}