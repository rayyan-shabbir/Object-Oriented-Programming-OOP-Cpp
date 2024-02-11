#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ref_var_swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
int main() {
    int a = 4, b = 5;
    cout << "The value of a is " << a <<" and b is " << b << endl;
    swap(&a, &b);
    cout << "The value of a is " << a <<" and b is " << b << endl;
    ref_var_swap(a, b);
    cout << "The value of a is " << a <<" and b is " << b << endl;
    return 0;
}