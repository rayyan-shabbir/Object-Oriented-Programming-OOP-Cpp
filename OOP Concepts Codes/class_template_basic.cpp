#include "iostream"
using namespace std;

//Class Template (for different data types i.e int, float, char etc)
template<class t>
class Algebra {
    t a, b;     //Data Members of type t ('t' type will be defined by user from main)

    public:
        //Default Constructor
        Algebra() {
            a = b = 0;
        }

        //Member Input Function
        void input() {
            cout << "Enter value of a: ";
            cin >> a;
            cout << "Enter value of b: ";
            cin >> b; 
        }

        void output() {
            cout << "a = " << a << " b = " << b << endl;
        }

};

int main() {
    Algebra<int> obj1;          //Template class for int

    obj1.input();
    obj1.output();

    return 0;
}