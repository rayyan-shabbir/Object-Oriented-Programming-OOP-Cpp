#include <iostream>
using namespace std;

int main() {
    cout << "Operators in C++" << endl;
    cout << "Following are the types of operators in C++\n" << endl;
    
    //ASSIGNMENT OPERATOR
    int a = 4, b = 5;
    char d = 'd';

    //ARITHMETIC OPERATOR
    cout << "***ARITHMETIC OPERATOR***" << endl;
    cout << "The value of a+b is: " << a+b << endl;
    cout << "The value of a-b is: " << a-b << endl;
    cout << "The value of a*b is: " << a*b << endl;
    cout << "The value of a/b is: " << a/b << endl;
    cout << "The value of a%b is: " << a%b << endl;
    cout << "The value of a++ is: " << a++ << endl;
    cout << "The value of a-- is: " << a-- << endl;
    cout << "The value of ++a is: " << ++a << endl;
    cout << "The value of --a is: " << --a << endl << endl;

    //COMPARISION OPERATOR
    cout << "***COMPARISION OPERATOR***" << endl;
    cout << "The value of a == b is: " << (a == b) << endl;
    cout << "The value of a != b is: " << (a != b) << endl;
    cout << "The value of a >= b is: " << (a >= b) << endl;
    cout << "The value of a <= b is: " << (a <= b) << endl;
    cout << "The value of a < b is: " << (a < b) << endl;
    cout << "The value of a > b is: " << (a > b) << endl << endl;
    
    //LOGICAL OPERATOR
    cout << "***LOGICAL OPERATOR***" << endl;
    cout << "The value of Logical 'AND' operator is: " << ((a == b) && (a < b)) << endl;
    cout << "The value of Logical 'OR' operator is: " << ((a == b) || (a < b)) << endl;
    cout << "The value of Logical 'NOT' operator is: " << (!(a == b)) << endl;
    return 0;
}