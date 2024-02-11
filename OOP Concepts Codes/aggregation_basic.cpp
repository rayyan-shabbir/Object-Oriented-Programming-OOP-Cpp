#include <iostream>
using namespace std;

class Teacher {
    int eCode;
    string tName;

    public:
        Teacher(int eCode, string tName) {
            this->eCode = eCode;
            this->tName = tName;
        }

        void teacherInfo() {
            cout << "\nTeacher's Code: " << eCode << "\tTeacher's Name: " << tName << endl;
        }

};

class Department {
    int dNo;
    string dName;

    Teacher *teacher;   //holds a reference to Teacher : Aggregation (weak binding)

    public:
        Department(int dNo, string dName, Teacher *teacher = NULL){
            this->dNo = dNo;
            this->dName = dName;

            this->teacher = teacher;    //data member teacher holds the reference/address of a Teacher
        }

        void departmentInfo() {
            cout << "Department No: " << dNo << "\tDepartment Name: " << dName << endl;

            if(teacher != NULL)                 //if teacher exists
                teacher->teacherInfo();         //display teacher information
        }
};

int main() {
    Teacher t1(535, "Rayan Ahmed");     //Teacher's class object.

    Department d1(02, "IT BUILD-B", &t1);      //&t1 reference of teacher. In Aggregation object is always pass by reference.

    d1.departmentInfo();    //Department Function
    return 0;
}