#include <iostream>
using namespace std;

void print(int p[], int s) {
    for(int i = 0; i < s; i++) {
        cout << "A[" << i << "] = " << p[i] << endl;
    }
}
int main() {
    int size = 5;
    int* ptr = new int[size];
 
    for(int i = 0; i < size; i++) {
        ptr[i] = i;
    }

    print(ptr, size);
    delete[] ptr;
    return 0;
}