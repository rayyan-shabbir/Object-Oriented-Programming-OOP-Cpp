#include <iostream>
using namespace std;

class Employee {
    public:
        string name;
        int salary;

        Employee(string n, int s, int sp){
            this->name = n;
            this->salary = s;
            this->secretpassword = sp;
        }

        void printdetails() {
            cout<<"The name of employee is "<<this->name<<" and his salary is "<<this->salary<<"$"<<endl;
        }

        void printsecretpassword() {
            /*HERE SECRETPASSWORD CAN BE ACCESSED AND EASILY PRINT BCZ THIS IS INSIDE THE 
            CLASS */
            cout<<"The secret password is "<<this->secretpassword;
        }
    private:
        int secretpassword;
};

int main() {
    Employee ray("Rayan constructor", 100, 786);
    ray.printdetails();
    ray.printsecretpassword();
    /* cout<<"Secret password is "<<ray.secretpassword; *THIS CANNOT BE PRINT BCZ 
    SECRETPASSWORD IS PRIVATE NOT PUBLIC SO IT CANNOT BE ACCESSED OR PRINT HERE IN MAIN */
}