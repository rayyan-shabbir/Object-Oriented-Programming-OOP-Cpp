#include "iostream"
using namespace std;

class Algebra {
    static int count;
    public:
        Algebra() {
            count++;
        }
        Algebra(int a, int b) {
            count++;
        }
        ~Algebra() {
            count--;
        }
        static int getCount() {
            return count;
        }
};

int Algebra::count;

int main() {
    Algebra obj1, obj2(5, 6), obj3;
    cout << Algebra::getCount() << endl;
    return 0;
}