#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

static int trans = 0;

// ~~~ ADT : Account ~~~
class Account
{
protected:
    //Data Members
    string firstName;
    string lastName;
    double currentBalance;

public:
    //Parametrize Constructor
    Account(string firstName, string lastName, double currentBalance)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->currentBalance = currentBalance;
    }

    virtual string getAcctType() const
    {
        return "Account";
    }

    //DebitTransaction member function (For Subtracting the debitamount from account)
    virtual double debitTransaction(double debitamount)
    {
        this->currentBalance -= debitamount;
        return this->currentBalance;
    }

    //CreditTransaction member function (For Adding the creditamount to account)
    virtual double creditTransaction(double creditamount)
    {
        this->currentBalance += creditamount;
        return this->currentBalance;
    }

    //Member Function print().
    void print()
    {
        cout << firstName << " " << lastName << "\t\t" << getAcctType() << "\t\t" << fixed << setprecision(2) << currentBalance << endl;
    }
};


// ~~~ ADT : CheckingAccount (Derived from Account Class) ~~~
class CheckingAccount : public Account
{
private:
    void chargeFee () {
        currentBalance -= 10;
    }

public:
    //Parametrize Constructor
    CheckingAccount(string firstName, string lastName, double currentBalance) : Account(firstName, lastName, currentBalance) { }

    virtual string getAcctType() const
    {
        return "CheckingAccount";
    }

    //DebitTransaction member function (For Subtracting the debitamount from account)
    virtual double debitTransaction(double debitamount)
    {
        if (currentBalance < 100)
            this->chargeFee();

        Account::debitTransaction(debitamount);
        return currentBalance;
    }

    //CreditTransaction member function (For Adding the creditamount to account)
    virtual double creditTransaction(double creditamount)
    {
        if((currentBalance + creditamount) < 100)
            this->chargeFee();

        Account::creditTransaction(creditamount);
        return currentBalance;
    }
};


// ~~~ ADT : CheckingAccount (Derived from Account Class) ~~~
class SavingsAccount : public Account
{
private:
    void payInterest () {
        currentBalance += (currentBalance * 0.02);
    }

public:
    //int trans;

    //Parametrize Constructor
    SavingsAccount(string firstName, string lastName, double currentBalance) : Account(firstName, lastName, currentBalance) { }

    virtual string getAcctType() const
    {
        return "SavingsAccount";
    }

    virtual double debitTransaction(double debitamount)
    {
        if (trans < 2)
        {
            Account::debitTransaction(debitamount);
            payInterest();
            trans++;
        }
        return currentBalance;
    }

    virtual double creditTransaction(double creditamount)
    {
        if (trans < 2)
        {
            Account::creditTransaction(creditamount);
            payInterest();
            trans++;
        }
        return currentBalance;
    }
};

int main()
{
    Account *ac2 = new CheckingAccount("Saud", "Yaseen", 200.0);
    Account *ac1 = new SavingsAccount("Hunain", "Shahid", 1000.0);

    cout << endl << endl;
    cout << "*** Two Accounts ***" << endl;
    ac2->print();
    ac1->print();

    cout << endl << endl;

    //For Checking Account
    double c1 = ac2->debitTransaction(150.00);
    ac2->print();
    double c2 = ac2->debitTransaction(5.00);
    ac2->print();
    double c3 = ac2->creditTransaction(200.00);
    ac2->print();

    //For Savings Account
    double s1 = ac1->debitTransaction(150.00);
    ac1->print();
    double s2 = ac1->creditTransaction(200.00);
    ac1->print();
    double s3 = ac1->debitTransaction(5.00);
    ac1->print();

    //cout << "\n<<OUTPUT>> " << endl << endl;

    cout << endl << endl;

    cout << "=== Test for CheckingAccount ===" << endl << endl;
    cout << "(1) Debitting 150.00 -- The balance is " << c1 << endl;
    cout << "(2) Debitting 5.00 -- The balance is " << c2 << endl;
    cout << "(3) Crediting 200.00 -- The balance is " << c3 << endl;
    cout << "(*) Final account information" << endl << endl;
    ac2->print();

    cout << endl << endl;


    cout << "=== Test for SavingsAccount ===" << endl << endl;
    cout << "(1) Debitting 150.00 -- The balance is " << s1 << endl;
    cout << "(2) Crediting 200.00 -- The balance is " << s2 << endl;
    cout << "(3) Debitting 5.00 -- The balance is " << s3 << endl;

    cout << "(*) Final account information" << endl << endl;
    ac1->print();

    return 0;
}