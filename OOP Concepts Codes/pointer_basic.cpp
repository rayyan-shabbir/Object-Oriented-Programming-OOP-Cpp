#include <iostream>
using namespace std;

int main() {
    int a = 7;
    int *ptra;
    ptra = &a;

    cout << "Value of a is: " << a << endl;
    cout << "Value of a is: " << *ptra << endl;
    cout << "Value of a is: " << *&a << endl;
    cout << "Adress of a is: " << &a << endl;
    cout << "Adress of a is: " << ptra << endl;
    cout << "Adress of ptra is: " << &ptra << endl << endl;;
    
    //Pointer to pointer
    cout << "***Pointer to Pointer" <<endl;
    int **c = &ptra;
    cout << "Adress of ptra is: " << &ptra << endl;
    cout << "Adress of ptra is: " << c << endl;
    cout << "Value of ptra (at adress c) is: " << *c << endl;
    cout << "Value at adress value_at(value_at(c)) is: " << **c << endl;
    return 0;
}