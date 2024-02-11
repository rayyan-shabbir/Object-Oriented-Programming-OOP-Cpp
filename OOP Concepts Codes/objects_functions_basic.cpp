#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        string major;
        float gpa;

        Student(string n, string m, int g) {
            name = n;
            major = m;
            gpa = g;
        }

        bool honorsRoll() {
            if(gpa >= 3.5) { 
                return true;
            }

            return false;
        }

};

int main() {
    Student s1("Rayan", "IT", 3.9);
    Student s2("khurram", "Arts", 2.6);

    cout << s1.honorsRoll() << endl;
    cout << s1.honorsRoll() << endl;
    return 0;
}