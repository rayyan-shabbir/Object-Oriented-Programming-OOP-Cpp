#include <iostream>
using namespace std;

int main() {
    int marks[10];
    for(int i=0; i<10; i++){
        cout<<"Enter Marks of "<<i+1<<"th student : ";
        cin>>marks[i];
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        cout<<"Marks of student "<<i+1<<" is : "<<marks[i]<<endl;
    }
    return 0;
}
