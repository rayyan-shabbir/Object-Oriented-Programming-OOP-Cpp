#include <iostream>
using namespace std;

class Employee
{
    string firstName, lastName, SSN;

public:
    Employee(string firstName, string lastName, string SSN)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->SSN = SSN;
    }

    void setFN(string firstName)
    {
        this->firstName = firstName;
    }
    void setLN(string lastName)
    {
        this->lastName = lastName;
    }
    void setSSN(string SSN)
    {
        this->SSN = SSN;
    }

    string getFN()
    {
        return firstName;
    }

    string getLN()
    {
        return lastName;
    }
    string getSSN()
    {
        return SSN;
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
    SalariedEmployee(string fN, string lN, string ssn, double weeklySalary = 0) : Employee(fN, lN, ssn)
    {
        this->weeklySalary = weeklySalary;
    }

    void setWS(double weeklySalary)
    {
        this->weeklySalary = weeklySalary;
    }

    double getWS()
    {
        return weeklySalary;
    }

    virtual void print()
    {
        cout << "Name: " << getFN() << " " << getLN() << "\nSSN: " << getSSN() << endl;
        cout << "WeeklySalary: " << weeklySalary << endl;
    }

    virtual double earnings()
    {
        return this->getWS();
    }
};

class CommisonEmployee : public Employee
{
    double grossSales, comissionRate;

public:
    CommisonEmployee(string fN, string lN, string ssn, double grossSales = 0, double comissionRate = 0) : Employee(fN, lN, ssn)
    {
        this->setGS(grossSales);
        this->setCR(comissionRate);
    }

    void setGS(double grossSales)
    {
        this->grossSales = grossSales;
    }
    void setCR(double comissionRate)
    {
        this->comissionRate = comissionRate;
    }

    double getGS()
    {
        return grossSales;
    }

    double getCR()
    {
        return comissionRate;
    }

    virtual void print()
    {
        cout << "Name: " << getFN() << " " << getLN() << "\nSSN: " << getSSN() << endl;
        cout << "Gross Sales: " << grossSales << endl;
        cout << "ComissionRate: " << comissionRate << endl;
    }

    virtual double earnings()
    {
        double sal = grossSales * comissionRate;

        return sal;
    }
};

class HourlyEmployee : public Employee
{
    double wage, hours;

public:
    HourlyEmployee(string fN, string lN, string ssn, double wage = 0, double hours = 0) : Employee(fN, lN, ssn)
    {
        this->setWage(wage);
        this->setHours(hours);
    }

    void setWage(double wage)
    {
        this->wage = wage;
    }

    void setHours(double hours)
    {
        this->hours = hours;
    }

    double getWage()
    {
        return wage;
    }
    double getHours()
    {
        return hours;
    }

    virtual void print()
    {
        cout << "Name: " << getFN() << " " << getLN() << "\nSSN: " << getSSN() << endl;
        cout << "Wage: " << wage << endl;
        cout << "Hours: " << hours << endl;
    }

    virtual double earnings()
    {
        double sal = hours * wage;

        return sal;
    }
};

class BasePlusCommisonEmployee : public CommisonEmployee
{
    double baseSalary;

public:
    BasePlusCommisonEmployee(string fN, string lN, string ssn, double grossSales = 0, double comissionRate = 0, double baseSalary = 0) : CommisonEmployee(fN, lN, ssn, grossSales, comissionRate)
    {
        this->setBS(baseSalary);
    }

    void setBS(double baseSalary)
    {
        this->baseSalary = baseSalary;
    }
    double getBS()
    {
        return baseSalary;
    }

    virtual void print()
    {
        cout << "Name: " << getFN() << " " << getLN() << "\nSSN: " << getSSN() << endl;
        cout << "Gross Sales: " << getGS() << endl;
        cout << "ComissionRate: " << getCR() << endl;
        cout << "Base Salary: " << baseSalary << endl;
    }

    virtual double earnings()
    {
        double sal = (CommisonEmployee::earnings() + baseSalary);

        return sal;
    }
};

int main()
{
    SalariedEmployee obj1("Rayan", "Shabbir", "F20535", 19);
    // obj1.print();
    //cout << "Earnings obj1: " << obj1.earnings() << endl;
    CommisonEmployee obj2("Ali", "Hamza", "F20M515", 18, 2);
    // obj2.print();
    //cout << "Earnings obj2: " << obj2.earnings() << endl;
    HourlyEmployee obj3("Uzair", "Anwar", "F18M012", 2, 8);
    // obj3.print();
    //cout << "Earnings obj3: " << obj3.earnings() << endl;
    BasePlusCommisonEmployee obj4("Yasir", "Arfat", "F19A451", 1, 7, 1);
    // obj4.print();
    //cout << "Earnings obj4: " << obj4.earnings() << endl;

    Employee *eptr[4] = {&obj1, &obj3, &obj2, &obj4};

    for (int i = 0; i < 4; i++)
    {
        eptr[i]->print();
        eptr[i]->earnings();
    }
    return 0;
}