#include <iostream>
using namespace std;

int count = 0;

class num {
    public:
        num() {
            count++;
            cout << "Constructor for Object # " << count << endl;
        }

        ~num() {
            cout << "Destructor for Object # " << count << endl;
            count--;
        }
};

int main() {
    cout << "***Main Function***" << endl;
    cout << "Creating object 1" << endl;
    num n1;
    {
        cout << "Entering the block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3;
    }
    cout << "Back to main" << endl;

    return 0;
}