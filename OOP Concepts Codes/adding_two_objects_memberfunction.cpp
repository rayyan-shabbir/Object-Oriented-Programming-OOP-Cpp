#include "iostream"
using namespace std;

class Algebra {
    int a, b;

    public:
    Algebra () {
        cout << "Default Constructor..." << endl;

        a = 0;
        b = 0;
    }
    Algebra (int a1, int b1) {
        cout << "Parametrize Constructor..." << endl;

        a = a1;
        b = b1;
    }

    Algebra (const Algebra& obj) {
		cout << "Copy Constructor" << endl;

		a = obj.a;
		b = obj.b;
	}

    Algebra add (const Algebra &obj) {
        Algebra temp;
        temp.a = a + obj.a;
        temp.b = b + obj.b;
        return temp;
    }

    void print () {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }

};

int main() {
    Algebra obj1(7, 9), obj2(1, 5), obj3;
    Algebra r = obj1.add(obj2);
    r.print();
    //(obj1.add(obj2)).print();
    //obj1.add(obj2);
    return 0;
}