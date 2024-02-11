#include "iostream"
using namespace std;

class Algebra {
    int a, b;

    public:
        Algebra () {
            a = b = 0;
        }

        Algebra (int a1, int b1) {
            a = a1;
            b = b1;
        }

        //Setting data 
        void setData(int a1, int b1) {
            a = a1;
            b = b1;
        }

        //printing data 
        void print() {
            cout << "a: " << a << "\tb: " << b << endl;
        }

        bool testArray (Algebra ar[], int size) {
            for(int i = 0; i < size; i++) {
                 if((a = ar[i].a) && (b = ar[i].b)) {
                     return true;
                 }
            }

            return false;
        }

};

int main() {
    Algebra ar[5] = {Algebra(), Algebra(1, 6), Algebra(6, 9), Algebra(2, 3), Algebra()};
    Algebra obj2(3, 4);

    for(int i = 0; i < 5; i++) {
        ar[i].setData(i, i+1);
    }

    for(int i = 0; i < 5; i++) {
        ar[i].print();
    }

    if(obj2.testArray(ar, 5)) {
        cout << "Exist" << endl;
    } else {
        cout << "Does not exist" << endl;
    }
    return 0;
}