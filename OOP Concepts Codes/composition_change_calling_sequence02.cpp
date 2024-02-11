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
        // CPU(const CPU& obj) {
        //     model = obj.model;
        //     name = obj.name;
        // }
        //Destructor of CPU
        ~CPU() {
            cout << "***CPU DESTRUCTOR***" << endl;
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
        //**Making a call to Parameterzied Constructor of CPU "m_Cpu(cpuModel, cpuName)". Default Constructor will be executed, otherwise.** 
        Computer(int cpuModel, string cpuName) : m_Cpu(cpuModel, cpuName)
        {
            makeYear = -1;
            name = "";
        }

        //Parametrize Constructor of Computer
        //**Default Constuctor of CPU will be executed**
        Computer(int computerMakeYear,string computerName, int cpuModel, string cpuName) 
        {
            // m_Cpu(cpuModel, cpuName); --> If we try to access Parametrize Constructor of CPU class inside body of Computer class constructor then it gives and error
            this->makeYear = computerMakeYear;
            this->name = computerName;
        }

        //Copy Constructor of Computer
        //**Making a call to Parametrize Constructor of CPU "m_Cpu(cpuModel, cpuName)". Default Constructor will be executed, otherwise.**
        // Computer(const Computer& obj, int cpuModel, string cpuName) : m_Cpu(cpuModel, cpuName)
        // {
        //     makeYear = obj.makeYear;
        //     name = obj.name;
        // }

        //Copy Constructor of Computer
        //**Making a call to Default Constructor of CPU "m_Cpu()".Bcz If we dont give any call in member initializer list then it will call simple default constructor itself**
        // Computer(const Computer& obj) 
        // {
        //     makeYear = obj.makeYear;
        //     name = obj.name;
        // }

        //Destructor of Computer
        ~Computer() {
            cout << "***CONMPUTER DESTRUCTOR***" << endl;
        }

        //Print Member Function
        //**Display the data of computer**
        void print() {
            cout << "Computer Make Year: " << makeYear << "    Computer Name: " << name << endl;

            m_Cpu.print();  //Making a call to CPU's printInfo to display the data
        }

};

int main() {
    Computer obj1(5435535, "Gen Heat UPPPuXxxX"), obj2(2002, "DELL XP Pro. ", 5435535, "Gen Heat UPPPuXxxX");
    //Computer  obj3(obj2, 1928, "High Volt eEeEZzsf"), obj4(obj2);
    Computer obj4(obj2);
    
    //obj3.print();
    //obj1.print();
    //obj2.print();
    obj4.print();

    return 0;
}