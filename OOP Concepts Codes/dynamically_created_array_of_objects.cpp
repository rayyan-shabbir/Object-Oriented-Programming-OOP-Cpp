#include <iostream>
using namespace std;

class Algebra {
	int a, b;

	public:
	Algebra() {
		a = b = 0;
	}

	friend ostream &operator<< (ostream& , const Algebra&);
};

ostream& operator<<(ostream& out, const Algebra& obj) {
	out << obj.a << "\t" << obj.b << endl;
	

	return out;
}

int main() {
    int n = 3;
	Algebra *p = new Algebra[n];

    for(int i = 0; i<3; i++)
	    cout << p[i];

	delete[] p;
	return 0;
}