#include <iostream>
using namespace std;

class Employee {
    private: 
        int a, b, c;
    public:
        int d, e;
        //type # 01 to use function in class
        void setData(int a1, int b1, int c1); //Decleration
        //type # 02 to use function in class
        void getData() {
            cout << "Value of a is " << a <<endl;
            cout << "Value of b is " << b <<endl;
            cout << "Value of c is " << c <<endl;
            cout << "Value of d is " << d <<endl;
            cout << "Value of e is " << e <<endl;
        }
};
//Defination, here :: known as scope resolution operator
void Employee :: setData(int a1, int b1, int c1) {
    a = a1;
    b = b1;
    c = c1;
}
int main() {
    Employee ray;
    ray.setData(1, 2, 3);
    ray.d = 4;
    ray.e = 5;
    ray.getData();
    return 0;
}