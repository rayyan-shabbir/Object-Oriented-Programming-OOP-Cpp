#include <iostream>
using namespace std;


int main() {
    int size = 4;
    int *p = new int[size];
    p[0] = 5;
    *(p+1) = 6;
    p[2] = 7;
    *(p+3) = 8 ;

    for(int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = " << p[i] << endl;
    } 

    delete[] p;
    return 0;
}