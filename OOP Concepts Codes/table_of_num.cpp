#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter Number you want table of ";
    cin>>num;

    for(int i=0; i<10; i++) {
        cout<<num<<" X "<<i+1<<" = "<<num*(i+1)<<endl;
    }
    return 0;
}