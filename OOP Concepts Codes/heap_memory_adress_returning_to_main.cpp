#include <iostream>
using namespace std;

int* test() {
    int *p = new int(7);
    return p;
}
int main() {
    int *q = test();

    cout << *q << endl;
    delete q;
    return 0;
}