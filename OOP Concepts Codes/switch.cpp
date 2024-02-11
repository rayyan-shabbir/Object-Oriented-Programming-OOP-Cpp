#include <iostream>
using namespace std;

int main() {
    int a;
    cout<<"Enter value: ";
    cin>>a;
    switch(a) {
        case 1:
            cout<<"Rating is *";
            break;
        case 2:
            cout<<"Rating is **";
            break;
        case 3:
            cout<<"Rating is ***";
            break;
        case 4:
            cout<<"Rating is ****";
            break;
        case 5:
            cout<<"Rating is *****";
            break;
        default :
            cout<<"Invalid Rating";
    }
    return 0;
}