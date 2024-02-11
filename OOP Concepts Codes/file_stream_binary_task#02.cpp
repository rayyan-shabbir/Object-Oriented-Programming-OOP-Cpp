#include <iostream>
#include "fstream"
using namespace std;

class Student {
    int id;
    char name[20];
    float marks;

    friend ostream& operator<<(ostream &, const Student &);
    friend istream& operator>>(istream &, Student &);

    public:
        Student(int id = 0, char *name = NULL, float marks = 0) {
            this->id = id;
            *(this->name) = *name;
            this->marks = marks;
        }

        void addStudent(ostream& out) {
            ofstream outf("student.dat", ios::binary);

            outf.write(reinterpret_cast<char*>(this), sizeof(Student));

            if(outf) {
                cout << "Data is written";
            }
        }

        static void displayAllStudents(istream &) {
            ifstream inf("student.dat", ios::binary);

            inf.read(reinterpret_cast<char*>(), sizeof(Student));


        }

};

ostream& operator<<(ostream &out, const Student &obj) {
    out << obj.id;
    out << *(obj.name);
    out << obj.marks;

    return out;
}

istream &operator>>(istream& in, Student &obj) {
    cout << "Enter id: ";
    in >> obj.id;
    cout << "Enter name: ";
    in >> *(obj.name);
    cout << "Enter Marks: ";
    in >> obj.marks;
}

int main() {
    
    return 0;
}