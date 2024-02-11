#include "iostream"
using namespace std;

class NumDays
{
    float days;
    float hours;

public:
    //***Constructor***
    NumDays(float hours = 0)
    {
        setHours(hours);
    }

    //***Setters***
    void setHours(float hours)
    {
        this->hours = hours;
        setDays(hours);
    }

    void setDays(float hours)
    {
        this->days = (hours / 8);
    }

    //***Getters***
    float getHours()
    {
        return hours;
    }

    float getDays()
    {
        return days;
    }

    //***Overloaded Operators***

    //Addition Operator (+)
    NumDays operator+(const NumDays &rdx) const
    {
        NumDays temp(this->hours + rdx.hours);
        return temp;
    }
    //Subtraction Operator (-)
    NumDays operator-(const NumDays &rdx) const
    {
        NumDays temp(this->hours - rdx.hours);
        return temp;
    }

    //Prefix Increment Operator (++)
    NumDays operator++()
    {
        hours++;
        setHours(hours);

        return *this;
    }

    //Postfix Increment Operator (++)
    NumDays operator++(int)
    {
        NumDays originalState(*this);
        hours++;
        setHours(hours);

        return originalState;
    }

    //Prefix Decrement Operator (--)
    NumDays operator--()
    {
        hours--;
        setHours(hours);

        return *this;
    }

    //Postfix Decrement Operator (--)
    NumDays operator--(int)
    {
        NumDays original_State(*this);
        hours--;
        setHours(hours);

        return original_State;
    }
};

class TimeOff
{
    string eName;
    int eId;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;

public:
    //***Constructor***
    TimeOff(string eName, int eId, float maxSickHours, float sickTakenHours, float maxVacHours, float vacTakenHours, float maxUnpaidHours, float unpaidTakenHours) : maxSickDays(maxSickHours), sickTaken(sickTakenHours), maxVacation(maxVacHours), vacTaken(vacTakenHours), maxUnpaid(maxUnpaidHours), unpaidTaken(unpaidTakenHours)
    {
        this->eName = eName;
        this->eId = eId;
    }

    //***Setters***
    void setEname(string eName)
    {
        this->eName = eName;
    }

    void setEid(int eId)
    {
        this->eId = eId;
    }

    //***Getters***
    string getEname()
    {
        return eName;
    }

    int getEid()
    {
        return eId;
    }

    //***Setters for NumDays instances***

    void setMaxSickDays(float months)
    {
        maxSickDays.setHours(8 * months);
    }

    void setSickTaken(float hours)
    {
        sickTaken.setHours(hours);
    }

    void setMaxVacation(float months)
    {
        float hours = months * 730.00;

        if (hours <= 240)
        {
            maxVacation.setHours(12 * months);
        }
        else
        {
            cout << "MaxVacation Hours cannot be greater than '240'" << endl;
            maxVacation.setHours(0);
        }
    }

    void setVacTaken(float hours)
    {
        vacTaken.setHours(hours);
    }

    void setMaxUnpaid(float months)
    {
        maxUnpaid.setHours(12 * months);
    }

    void setUnpaidTaken(float hours)
    {
        unpaidTaken.setHours(hours);
    }

    //***Getters for NumDays instances***
    NumDays getMaxSickDays()
    {
        return maxSickDays;
    }

    NumDays getSickTaken()
    {
        return sickTaken;
    }

    NumDays getMaxVacation()
    {
        return maxVacation;
    }

    NumDays getVacTaken()
    {
        return vacTaken;
    }

    NumDays getMaxUnpaid()
    {
        return maxUnpaid;
    }

    NumDays getUnpaidTaken()
    {
        return unpaidTaken;
    }
};

int main()
{
    float months = 0;
    float hours = 0;

    cout << "Enter the No. Of Months that an Employee has worked for the Company: ";
    cin >> months;

    hours = months * 730.001;

    TimeOff ray1("Rayan Ahmed", 20535, 12, 10, 04, 53, 8, 9);

    float sickDays = months * (ray1.getMaxSickDays()).getDays();
    float vacDays = months * (ray1.getMaxVacation()).getDays();
    float unpaidDays = months * (ray1.getMaxUnpaid()).getDays();

    cout << "Employee gets '" << sickDays << "' Max Sick Days" << endl;
    cout << "Employee gets '" << vacDays << "' Max Paid Vacation Days" << endl;
    cout << "Employee gets '" << unpaidDays << "' Max Unpaid Vacation Days" << endl << endl;

    ray1.setMaxSickDays(months);
    ray1.setMaxUnpaid(months);
    ray1.setMaxVacation(months);

    return 0;
}
