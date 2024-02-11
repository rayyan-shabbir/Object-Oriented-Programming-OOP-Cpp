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
    public:     //Every Data Member and Member Function are public now.
    int dNo;
    string dName;

    Teacher *teacher;   //holds a reference to Teacher : Aggregation (weak binding)

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
    Teacher t2(598, "Shahid Ali");     //Teacher's class object.

    Department d1(02, "IT BUILD-B", &t1);      //&t1 reference of teacher. In Aggregation object is always pass by reference.

    d1.departmentInfo();    //Department Function

    d1.teacher = &t2;

    d1.departmentInfo();

    t1.teacherInfo();
    t2.teacherInfo();

    d1.teacher = NULL;
    d1.departmentInfo();
    return 0;
}