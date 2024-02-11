#include <iostream>
#include <string>
using namespace std;

int main(){
    string name = "Rayan Shabbir";
    cout<<"My name is "<<name<<endl;
    cout<<"The length of name is "<<name.length()<<endl;
    cout<<"The name is "<<name.substr(0, 3)<<endl;
    cout<<"The name is "<<name.substr(2, 3)<<endl;
    cout<<"The name is "<<name.substr(1, 1)<<endl;
    cout<<"The char found at index "<<name.find('y', 0)<<endl;
    cout<<"The string found at index "<<name.find("bbir", 0);
    return 0;
}