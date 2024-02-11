#include <iostream>
using namespace std;

int main() {
    int age;
    cout<<"Enter age: ";
    cin>>age;

    if(age > 150)
        cout<<"Invalid Age";
    else if(age >= 18 && age <= 150)
        cout<<"You can vote";
    else 
        cout<<"You cannot vote";
    return 0;
}