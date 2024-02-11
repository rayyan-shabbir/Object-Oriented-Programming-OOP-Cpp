#include <iostream>
using namespace std;

class Employee {
    public:
        string name;
        int salary;

        void printdetails() {
            cout << "The name of employee is " << this->name << " and his salary is " << this->salary << "$";

        }
};

int main() {
    Employee ray;
    ray.name = "Rayan";
    ray.salary = 100;
    ray.printdetails();
}