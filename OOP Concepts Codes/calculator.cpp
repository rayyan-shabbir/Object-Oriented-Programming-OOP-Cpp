#include <iostream>
using namespace std;

int main() {
    int result = 0;
    int num1, num2;
    char op;
    cout << "Enter 1st Number: ";
    cin >> num1;
    cout << "Enter 2nd Number: ";
    cin >> num2;
    cout << "Enter operator: ";
    cin >> op;

    if(op == '+') {
        result = num1 + num2;
    } else if(op == '-') {
        result = num1 - num2;
    } else if(op == '/') {
        result = num1 / num2;
    }  else if(op == '*') {
        result = num1 * num2;
    } else {
        cout << "Invalid input";
    }

    cout << "The answer is: " << result;
    return 0;
}