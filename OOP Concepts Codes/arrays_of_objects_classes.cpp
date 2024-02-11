#include <iostream>
using namespace std;

class Employee {
    int id;
    int salary;
    //int count;
    public:
        void setData() {
            cout << "\nEnter id of Employee: ";
            cin >> id;
            cout << "Enter salary of Employee: ";
            cin >> salary;
        }
        void getData() {
            cout << "\nThe id of Employee is " << id << " and his salary is " << salary << endl;
        }
};

int main() {
    Employee comp[4];

    for(int i=0; i<4; i++) {
        comp[i].setData();
        comp[i].getData();
    }
    return 0;
}