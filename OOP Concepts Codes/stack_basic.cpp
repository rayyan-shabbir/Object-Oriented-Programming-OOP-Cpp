#include <iostream>
using namespace std;

int main() {
	int a = 6;
	int b = 9;
	int *q = &a;
	q = &b;
	*q = 88;

	cout << q << endl;
	cout << &b << endl;

	cout << *q << endl;
	cout << b << endl;
	return 0;
}