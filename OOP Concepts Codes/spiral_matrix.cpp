#include "iostream"
using namespace std;


int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int arr[n][n];

    int count = (n*n);

    int c1 = 0;
    int m2 = 2;

    int r1 = 1;
    int m3 = 2;

    int c2 = 1;
    int m4 = 0;

    int r2 = 1;
    int m1 = 0;

    int i = 0;
    while (i < 9) {
        if (i >= 1) {
            c1 = m1;
            r1 = m2;
            c2 = m3;
            r2 = m4;

        }


        while (c1 <= m2 && i < 9) {
            arr[m1][c1++] = ++i;
        }

        // m2 = m2 - 1;
        m1 = m1 + 1;

        while(r1 <= m3 && i < 9)
            arr[r1++][m2] = ++i;

        m2 = m2 - 1;

        while(c2 >= m4 && i < 9) 
            arr[m3][c2--] = ++i;

        m3 = m3 - 1;

        while(r2 >= m1 && i < 9)
            arr[r2--][m4] = ++i;

        m4 = m4 + 1;

    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << "[ ";
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
    return 0;
}