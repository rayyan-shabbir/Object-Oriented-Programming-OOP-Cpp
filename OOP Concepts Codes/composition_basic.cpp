#include <iostream>
using namespace std;

class CPU {
    int model;
    string name;

    public:
        //Default Constructor of CPU
        CPU() {
            model = -1;
            name = "";
        }

        //Parametrize Constructor of CPU
        CPU(int model, string name) {
            this->model = model;
            this->name = name;
        }

        //Copy Constructor of CPU
        CPU(const CPU& obj) {
            model = obj.model;
            name = obj.name;
        }

        //Destructor of CPU
        ~CPU() {
            cout << "***CPU DESTRUCTOR***" << endl;
        }

        //Input Member Function of CPU
        void input() {
            cout << "Enter CPU Model: ";
            cin >> model;

            cin.ignore();
            
            cout << "Enter CPU Name: ";
            getline(cin, name);

        }

        //Print Member Function of CPU
        void print() {
            cout << "CPU Model: " << model << "    CPU Name: " << name << endl;
        }
};

class Computer {
    int makeYear;
    string name;

    //Composition (has-a relationship. Computer "has-a" CPU)
    CPU m_Cpu;  //CPU's object is composed in Computer. The life cycle of m_Cpu depends on Computer's Object.


    public:
        //Default Constructor of Computer
        //**Default Constuctor of CPU will be executed**
        Computer()
        {
            // m_Cpu(0, ""); --> If we try to access Default Constructor of CPU class inside body of Computer class constructor then it gives and ERROR
            makeYear = -1;
            name = "";
        }

        //Parametrize Constructor of Computer
        //**Making a call to Parameterzied Constructor of CPU "m_Cpu(cpuModel, cpuName)". Default Constructor will be executed, otherwise.** 
        Computer(int computerMakeYear,string computerName, int cpuModel, string cpuName) : m_Cpu(cpuModel, cpuName)
        {
            // m_Cpu(cpuModel, cpuName); --> If we try to access Parametrize Constructor of CPU class inside body of Computer class constructor then it gives and ERROR
            
            this->makeYear = computerMakeYear; 
            this->name = computerName;
        }

        //Copy Constructor of Computer
        //**Making a call to Copy Constructor of CPU "m_Cpu(obj.m_Cpu)". Default Constructor will be executed, otherwise.**
        Computer(const Computer& obj) : m_Cpu(obj.m_Cpu)
        {
            // m_Cpu(obj.m_Cpu); --> If we try to access Copy Constructor of CPU class inside body of Computer class constructor then it gives and ERROR.
            makeYear = obj.makeYear;
            name = obj.name;
        }

        //Destructor of Computer
        ~Computer() {
            cout << "***CONMPUTER DESTRUCTOR***" << endl;
        }

        //Print Input Function
        //**Get the data of computer**
        void input() {
            cout << "Enter Computer Make Year: ";
            cin >> makeYear;

            cin.ignore();

            cout << "Enter Computer Name: ";
            getline(cin, name);


            m_Cpu.input();   //Making a call to CPU's inputFunction to get the data
        }

        //Print Member Function
        //**Display the data of computer**
        void print() {
            cout << "Computer Make Year: " << makeYear << "    Computer Name: " << name << endl;

            m_Cpu.print();  //Making a call to CPU's printInfo to display the data
        }

};

int main() {
    Computer obj1, obj2(2002, "DELL XP Pro. ", 5435535, "Gen Heat UPPPuXxxX"), obj3(obj2);

    //obj3.print();
    obj1.input();
    obj1.print();
    //obj2.print();
    return 0;
}