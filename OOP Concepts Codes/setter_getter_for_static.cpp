#include <iostream>
using namespace std;

class Algebra {
    static int s; //Declaration of static

    public:
		static void setS(int s) {
			Algebra::s = s;
		}

		static int getS() {
			return s;
		}
};

int Algebra::s(0); //Defination of static

int main() {
    Algebra obj1;
    //obj1.setS(5);
    Algebra::setS(5);

    //cout << obj1.getS() << endl;
    cout << Algebra::getS() << endl;
    return 0;
}