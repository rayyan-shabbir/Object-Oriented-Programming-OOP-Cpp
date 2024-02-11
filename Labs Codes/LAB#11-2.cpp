#include <iostream>
using namespace std;

class Employee
{
    string firstName, lastName, SSN;

public:
    Employee(string fN, string lN, string SSN)
    {
        this->setFn(firstName);
        this->setLn(lastName);
        this->setSSN(SSN);
    }

    void setFn(string firstName)
    {
        this->firstName = firstName;
    }
    void setLn(string lastName)
    {
        this->lastName = lastName;
    }
    void setSSN(string SSN)
    {
        this->SSN = SSN;
    }

    string getFn()
    {
        return this->firstName;
    }
    string getLn()
    {
        return this->lastName;
    }
    string getSSN()
    {
        return this->SSN;
    }

    virtual void print()
    {
        cout << "Name: " << firstName << " " << lastName << "\nSSN: " << SSN << endl;
    }

    virtual double earnings() = 0;
};

class SalariedEmployee : public Employee
{
    double weeklySalary;

public:
    SalariedEmployee(string fn, string ln, string ssn, double ws = 0) : Employee(fn, ln, ssn)
    {
        this->setWS(ws);
    }

    void setWS(double ws)
    {
        this->weeklySalary = ws;
    }

    double getWS()
    {
        return weeklySalary;
    }

    virtual void print()
    {
        Employee::print();
        cout << "WeeklySalary: " << weeklySalary << endl;
    }

    virtual double earnings()
    {
        return weeklySalary;
    };
};

class HourlyEmployee : public Employee
{
    double wage, hours;

public:
    HourlyEmployee(string fn, string ln, string ssn, double wage = 0, double hours = 0) : Employee(fn, ln, ssn)
    {
        this->setWage(wage);
        this->setHours(hours);
    }

    void setWage(double wage)
    {
        this->wage = wage;
    }

    double getWages()
    {
        return this->wage;
    }

    void setHours(double hours)
    {
        this->hours = hours;
    }

    double getHours()
    {
        return this->hours;
    }

    virtual void print()
    {
        Employee::print();
        cout << "Wage: " << wage << endl;
        cout << "Hours: " << hours << endl;
    }

    virtual double earnings()
    {
        return (hours * wage);
    };
};

class ComissionEmployee : public Employee
{
    double grossSale, comissionRate;

public:
    ComissionEmployee(string fn, string ln, string ssn, double grossSale = 0, double comissionRate = 0) : Employee(fn, ln, ssn)
    {
        this->setGS(grossSale);
        this->setCR(comissionRate);
    }

    void setGS(double grossSale)
    {
        this->grossSale = grossSale;
    }

    double getGS()
    {
        return this->wage;
    }

    void setHours(double hours)
    {
        this->hours = hours;
    }

    double getHours()
    {
        return this->hours;
    }

    virtual void print()
    {
        Employee::print();
        cout << "Wage: " << wage << endl;
        cout << "Hours: " << hours << endl;
    }

    virtual double earnings()
    {
        return (hours * wage);
    };
};

int main()
{

    return 0;
}