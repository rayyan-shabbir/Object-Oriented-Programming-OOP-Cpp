#include <iostream>
using namespace std;

int sum(int, int);

int main() {
    int a, b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;

    cout<<"Sum of a and b is "<<sum(a, b);
    return 0;
}

int sum(int a, int b){
    int c;
    c = a+b;
    return c;
}