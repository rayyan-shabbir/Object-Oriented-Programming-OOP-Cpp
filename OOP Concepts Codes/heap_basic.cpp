#include <iostream>
using namespace std;

int main() {
	int *p = new int(5);
    *p = 99;


    cout << &p << endl; // Pointer adress
    cout << p << endl; // heap adress 
    cout << *p << endl; // value i.e 99
    delete p;
	return 0;
}