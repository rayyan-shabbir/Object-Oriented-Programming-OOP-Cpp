#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int salary;
};

int main()
{
    Employee ray;
    ray.name = "Rayan";
    ray.salary = 100;
    cout << "Name of employee is " << ray.name << " and his salary is " << ray.salary << "$" << endl;
    return 0;
}