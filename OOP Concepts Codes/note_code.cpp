#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;
    char c;
    cout << "Enter values: ";
    cin >> a >> c >> b;

        //Here acb gives an error.
//  cout << "a + b = " << acb << endl;
        //This gives a+b output
    cout << "a + b = " << a << c << b << endl;
        //this gives sum of a and b.
    cout << "a + b = " << a+b << endl;
    return 0;
}