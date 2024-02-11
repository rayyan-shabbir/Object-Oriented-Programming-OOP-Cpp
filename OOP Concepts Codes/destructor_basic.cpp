#include <iostream>
using namespace std;

class Algebra {
    int a, b;
    public:
        ~Algebra() {
            cout << "Destructor" << endl;
        }
};

int main() {
    Algebra obj1, obj2;
    return 0;
}