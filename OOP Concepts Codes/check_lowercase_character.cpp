#include <iostream>
using namespace std;

int main() {
    char ch= 0;
    cout << "Enter character: " ;
    cin >> ch;
    if(ch >= 97 && ch <= 122) {
        cout << "It is lowercase";
    } else {
        cout << "It is not lowercase";
    }
    return 0;
}