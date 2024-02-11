#include <iostream>
using namespace std;

int *getPositive(int arr[], int size, int &newSize) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] >= 0) 
            count++;
    }
    newSize = count;
    int *p = new int[newSize];
    int j = 0;
    for(int i = 0; i < size; i++) {
            if(arr[i] >= 0) {
                p[j++] = arr[i];
            }
    }

    return p;
}
int main() {
    int arr[10] = {0, -1, -2, 3, 4, 5, -6, -7, -8, -9};

    //for (int i = 0; i < 10; i++)
    //   cout << arr[i] << endl;

    int s = 0;
    int *q = getPositive(arr, 10, s);

    for (int i = 0; i < s; i++)
        cout << q[i] << endl;
    
    delete[] q;
    return 0;
}