#include <iostream>
using namespace std;

int main() {
    int marks[] = {33, 57, 89, 96};
    cout << "*The marks are*" << endl;
    for(int i=0; i<4; i++) {
        cout << "Marks at " << i << " index is: " << marks[i] << endl;
    }
    
    int *p = marks;
    cout << "*The marks are*" << endl;
    for(int i=0; i<4; i++) {
        cout << "Marks at *(p+" <<i << ") is: " << *(p+i) << endl;
    }

    cout << "The value at marks[0] = " << *(p++) <<endl;
    cout << "The value at marks[2] = " << *(++p) << endl;
    return 0;
}