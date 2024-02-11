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
	// ofstream outf("test.txt", ios::binary);

	// if(!outf) {
	// 	cout << "ERROR" << endl;
	// 	exit(0);
	// }

	// A o[4] = {A(1, 1.1f), A(2, 2.2f), A(3, 3.3f), A(4, 4.4f)};

	// outf.write(reinterpret_cast<char*>(&o), 4*sizeof(A));
	// outf.close();

	ifstream inf("test.txt", ios::binary);
	ofstream outf2("temp.txt", ios::binary);

	if(!inf) {
		cout << "ERROR" << endl;
		exit(0);
	}
	if(!outf2) {
		cout << "ERROR" << endl;
		exit(0);
	}

	A i;

	inf.read(reinterpret_cast<char*>(&i), sizeof(A));
    while(!inf.eof()) {
        outf2.write(reinterpret_cast<char*>(&i), sizeof(A));
		i.print();
        inf.read(reinterpret_cast<char*>(&i), sizeof(i));
    }

	// int r1 = remove("test.txt");
	// int r2 = rename("temp.txt", "test.txt");

	// if(r1 == 0) {
	// 	cout << "File deleted successfully" << endl;
	// } else {
	// 	cout << "File not deleted successfully" << endl;
	// }

	inf.close();
	outf2.close();
	return 0;
}