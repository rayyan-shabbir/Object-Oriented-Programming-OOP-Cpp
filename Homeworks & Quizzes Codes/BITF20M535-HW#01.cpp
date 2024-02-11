#include "iostream"
#include "string"
using namespace std;

class Employee {
        string name;
        int id;
        string department;
        string position;

    public:
        //Default Constructor #03
        Employee () {
            name = "";
            id = 0;
            department = "";
            position = "";
        }

        //Parametrize Constructor #01
        Employee (string empName, int empId, string empDept, string empPos) {
            name = empName;
            id = empId;
            department = empDept;
            position = empPos;
        }

        //Parametrize Constructor #02
        Employee (string empName, int empId) {
            name = empName;
            id = empId;
            department = "";
            position = "";
        }

        //Copy Constructor # 04
        Employee (const Employee &objC) {
            name = objC.name;
            id = objC.id;
            department = objC.department;
            position = objC.position;
        }

        //Destructor # 05
        ~Employee () {
            cout << "\"Destructor executed...\"" << endl;
        }

        void setName(string empName) {
            name = empName;
        }

        void setId(int empId) {
            id = empId;
        }

        void setDept(string empDept) {
            department = empDept;
        }

        void setPos(string empPos) {
            position = empPos;
        }

        string getName() {
            return name;
        }

        int getId() {
            return id;
        }

        string getDept() {
            return department;
        }

        string getPos() {
            return position;
        }

        void setInfo(string empName, int empId, string empDept, string empPos) {
            name = empName;
            id = empId;
            department = empDept;
            position = empPos;
        }

        void getInfo() {
            string empName, empDept, empPos;
            int empId;

            cout << "Enter name: ";
            getline(cin, empName);

            cout << "Enter id: ";
            cin >> empId;
            cin.ignore(); //fflush(stdin);

            cout << "Enter department: ";
            getline(cin, empDept);

            cout << "Enter position: ";
            getline(cin, empPos);

            name = empName;
            id = empId;
            department = empDept;
            position = empPos;

        }

        void putInfo() {
           
           cout << name << "\t  " << id << "\t\t" << department << "\t" << position << endl;
        }
};

int main() {
    Employee obj1, obj2, obj3, obj4;

    //I use SetInfo func to store data
    //obj1.setInfo("Naveed Ali     ", 1230, "Computer Science", "Assistant Professor");
    obj2.setInfo("Nouman Abdullah", 1231, "Software Engineering", "Lecturer");
    obj3.setInfo("Naeem Ahmad    ", 1241, "Computer Science", "Lecturer");
    obj4.setInfo("Nadia          ", 1242, "Information Technology", "Assistant Professor");

    cout << "Name \t\t  Id Number \tDepartment \t\tPosition" << endl;

    obj1.getInfo();
    //Display by using putInfo member func of class employee
    obj1.putInfo();
    obj2.putInfo();
    obj3.putInfo();
    obj4.putInfo();

    

    return 0;
}