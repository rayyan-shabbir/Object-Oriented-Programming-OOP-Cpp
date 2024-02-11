#include <iostream>
#include "cstdio"
#include "fstream"
using namespace std;

class A {
	public:
		int a;
		float b;

		A(int a1 = 0, float b1 = 0) : a(a1), b(b1)
		{
		}

		void print() {
			cout << a << " " << b << endl;
		}
};

int main() {
	ofstream outf("test.txt", ios::binary);

	if(!outf) {
		cout << "ERROR" << endl;
		exit(0);
	}

	A o[4] = {A(1, 1.1f), A(2, 2.2f), A(3, 3.3f), A(4, 4.4f)};

	outf.write(reinterpret_cast<char*>(&o), 4*sizeof(A));
	outf.close();

	ifstream inf("test.txt", ios::binary);

	if(!inf) {
		cout << "ERROR" << endl;
		exit(0);
	}

	A i;

	inf.read(reinterpret_cast<char*>(&i), sizeof(A));
    while(!inf.eof()) {
        if(i.a != 3) {
            i.print();
            inf.read(reinterpret_cast<char*>(&i), sizeof(i));
        }
    }

	inf.close();
	return 0;
}