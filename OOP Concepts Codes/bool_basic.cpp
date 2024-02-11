#include <iostream>
using namespace std;

int main() {
    bool isMale = true;
    bool isNice = true;

    if(isMale && isNice) {
        cout << "You are a nice male";
    } else if(isMale && !isNice) {
        cout << "You are not a nice male";
    } else if(!isMale && isNice){
        cout << "You are nice but not a male";
    } else {
        cout << "You are neither nice nor a male";
    }
    return 0;
}