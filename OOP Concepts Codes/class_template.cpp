#include "iostream"
using namespace std;

//Class Template (for different data types i.e int, float, char etc)
template<class t>
class Algebra {
    t a, b;        //Data Members of type t ('t' type will be defined by user from main)

    public:
        //Default Constructor
        Algebra() {
            a = b = 0;
        }
        //Parametrize Constructor
        Algebra(t a, t b) {
            this->a = a;
            b = b;
        }

        setA(t a){
            this->a = a;
        }

        getA(){
            return a;
        }
        //Member Function to get input from user
        void input() {
            cout << "Enter a: ";
            cin >> a;

            cout << "Enter b: ";
            cin >> b;
        }

        //Member Function to display data on screen
        //Only Declaration of Member Function output
        void output();

        template<typename t2>  //Must write the template inside class for friend function
        friend ostream& operator<< (ostream& , const Algebra<t2> &);
};

//Define template again, when defining any member function outside of class	
template<typename t>     
void Algebra<t>::output() {
    cout << "Value of a = " << a << endl;
    cout << "Value of b = " << b << endl;
}

//Template for friend (non-member of class) stream insertion operator
template<typename t>
ostream& operator<< (ostream& out, const Algebra<t>& obj) //overloaded stream insertion operator
{
    out << "Value of a = " << obj.a << endl;
    out << "Value of b = " << obj.b << endl;

    // return out;
}

int main() {
    // Algebra<int> obj1;              //template class for int
    // cout << "***OBJ1***\n";
    // cout << obj1;

    Algebra<int> obj2(55, 5);              //Template class for int
    // obj2.input();
    cout << "***OBJ1***\n";
    // obj2.setA(7);
    cout << obj2;

    // obj2.getA

    // Algebra<float> obj3;
    // obj3.input();
    // cout << "***OBJ3***\n";          //Template class for float
    // obj3.output();

    // Algebra<char> obj4('R', 'H');    //Template class for char
    // cout << "***OBJ4***\n";
    // cout << obj4;
    return 0;
}