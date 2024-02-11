#include <iostream>
using namespace std;

class Role {
    public:
        int role_id;
        string role_title;
        string role_description;

        void addRole() {

        }

        void editRole() {

        }

        void deleteRole() {

        }

        void searchRole() {

        }

        void assignRole() {

        }

};

class Permission {
    public:
        int permission_id;
        int permission_role_id;
        string permission_title;
        string permission_module;
        string permission_description;

        void addPermission() {

        }

        void editPermission() {

        }

        void deletePermission() {

        }

        void searchPermission() {

        }
};

class Classes
{
    public:
        int class_id;
        string class_type;
        string class_description;
        string class_name;
        string class_room;
        int class_student_id;

        Permission *perm1;

        void addClasses() {

        }

        void editClasses() {


        }

        void deleteClasses() {

        }

        void searchClasses() {


        }
};

class User : public Role, public Permission
{
    public:
        int user_id;
        int user_role_id;
        string user_name;
        string user_email;
        int user_dob;
        string user_adress;

        void addUser() {

        }

        void editUser() {
            
        }

        void deleteUser() {
            
        }

        void searchUser() {
            
        }

};

class Registration
{
    public:
        int registration_id;
        string registration_type;
        string registration_description;
        string registration_number;
        string registration_name;
        int registration_student_id;
        int registration_date;

        Permission *perm1;

        void addRegistration() {

        }

        void editRegistration() {


        }

        void deleteRegistration() {

        }

        void searchRegistration() {


        }
};

class Colleges {
    public:
        int college_id;
        string college_name;
        string college_description;
        string college_adress;

        Permission *perm1;

        void addCollege() {

        }

        void editCollege() {


        }

        void deleteCollege() {

        }

        void searchCollege() {


        }

};

class Student {
    public:
        int student_id;
        string student_name;
        string student_mobile;
        string student_email;
        string student_adress;
        string student_password;
        string student_username;
        int student_college_id;

        Permission *perm1;

        void addStudent() {

        }

        void editStudent() {


        }

        void deleteStudent() {

        }

        void searchStudent() {


        }

};

class Course {
    public:
        int course_id;
        string course_type;
        string course_name;
        string course_description;
        string course_year;
        int course_student_id;

        Permission *perm1;

        void addCourse() {

        }

        void editCourse() {


        }

        void deleteCourse() {

        }

        void searchCourse() {


        }

};

int main() {
    
    return 0;
}