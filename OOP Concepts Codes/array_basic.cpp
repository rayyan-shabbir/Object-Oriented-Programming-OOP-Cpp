#include <iostream>
using namespace std;

int add(int a, int b) {
    return a+b;
}
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    for(int i=0; i<5; i++) {
        cout << add(a[i], 5) << endl;
    }
    return 0;
}