#include<iostream>
#include<string>

#define minimumBalance 100
#define maximumTransactions 2

using namespace std;

//****************
//               ADT: Account                *
//****************
class Account
{
	// Data Members
protected:
	string firstName, lastName;
	double curBalance;
public:
	// Default Constructor
	Account()
	{
		firstName = "";
		lastName = "";
		curBalance = 0;
	}

	// Parameterized Constructor
	Account(const string & firstName, const string & lastName, const double curBalance)
	{
		setfirstName(firstName);
		setlastName(lastName);
		setcurBalance(curBalance);
	}

	// Destructor
	virtual ~Account() {}

	// First NAme Setter
	void setfirstName(const string &firstName){ this->firstName = firstName; }

	// Last Name Setter
	void setlastName(const string &lastName){ this->lastName = lastName; }

	// Sets Balance
	void setcurBalance(const double curBalance){ this->curBalance = curBalance; }

	// Getter of First Name
	string getfirstName() const{ return firstName; }

	// Getter of Last Name
	string getlastName() const{ return lastName; }

	// Getter of Balance
	double getcurBalance() const{ return curBalance; }

	virtual string getAcctType() const{ return "Account"; }

	// Subtract the transaction amount from the account.
	virtual double debitTransaction(const double debitamount){ return curBalance -= debitamount; }

	// Add the transaction amount to the account.
	virtual double creditTransaction(const double creditamount){ return curBalance += creditamount; }

	// Print the three fields to the parameter ostream.
	void print(ostream& os)
	{
		os << lastName << ", " << firstName << "\t\t" << getAcctType() << "    \t" << curBalance << endl;
	}

};

//****************
//             ADT:ChechkingAccount          *
//****************
class ChechkingAccount : public Account
{
	void chargeFee(){curBalance -= 10;}
public:
	// ParaMeterized Constructor
	ChechkingAccount(const string & firstName, const string & lastName, const double curBalance)
	{
		setfirstName(firstName);
		setlastName(lastName);
		setcurBalance(curBalance);
	}

	// Subtracts the transaction amount from the account and possibly charges a transaction fee.
	virtual double debitTransaction(const double debitamount)
	{
		if ((curBalance - debitamount) < minimumBalance)
		{
			Account::debitTransaction(debitamount);
			chargeFee();
			cout << "Debitting " << debitamount << " -- The balance is " << curBalance << endl;
			return curBalance;
		}
		Account::debitTransaction(debitamount);
		cout << "Debitting " << debitamount << " -- The balance is " << curBalance << endl;
		return curBalance;
	}

	// Adds the transaction amount to the account and possibly charges a transaction fee.
	virtual double creditTransaction(const double creditamount)
	{
		if ((curBalance + creditamount) < minimumBalance)
		{
			Account::creditTransaction(creditamount);
			chargeFee();
			cout << "Crediting " << creditamount << " -- The balance is " << curBalance << endl;
			return curBalance;
		}

		Account::creditTransaction(creditamount);
		cout << "Crediting " << creditamount << " -- The balance is " << curBalance << endl;
		return curBalance;
	}

	virtual string getAcctType() const{ return "Checking Account"; }

	// Destructor
	~ChechkingAccount(){}
};

//****************
//             ADT:Savings Account           *
//****************
class SavingsAccount : public Account
{
	void payInterest(){ curBalance += (curBalance * (.02)); }
public:
	// Holds Number of Transictions 
	int transactions;

	// Parameterized Constructor
	SavingsAccount(const string & firstName, const string & lastName, const double curBalance)
	{
		setfirstName(firstName);
		setlastName(lastName);
		setcurBalance(curBalance);
    	transactions = 0;
	}

	// If there are less than two transactions, subtracts the transaction amount from the account and pays interest
	virtual double debitTransaction(const double debitamount)
	{
		if (transactions < maximumTransactions )
		{
			Account::debitTransaction(debitamount);
			payInterest();
			transactions++;
			cout << "Debitting " << debitamount << " -- The balance is " << curBalance << endl;
			return curBalance;
		}
		cout << "Sorry! You Have Acceeded Maximum Number Of Transactions!\n";
	}

	// If there are less than two transactions, adds the transaction amount to the account and pays interest
	virtual double creditTransaction(const double creditamount)
	{
		if (transactions < maximumTransactions)
		{
			Account::creditTransaction(creditamount);
			payInterest();
			transactions++;
			cout << "Crediting " << creditamount << " -- The balance is " << curBalance << endl;
			return curBalance;
		}
		cout << "Sorry! You Have Acceeded Maximum Number Of Transactions!\n";
	}

	virtual string getAcctType() const{ return "Savings Account"; }

	// Destructor
	~SavingsAccount(){}

};

int main()
{
	ChechkingAccount obj1("Yaseen", "Saghir", 200.00);
	SavingsAccount  obj2("Shahid", "Husnain", 1000.00);
	Account * ptr1 = &obj1;
	Account *ptr2 = &obj2;

	cout << "** Two Accounts! **\n\n";
	ptr1->print(cout);
	ptr2->print(cout);

	cout << "\n\n";
	cout << "==== Test for Checking Account! ====\n\n";

	cout << "1. ";
	ptr1->debitTransaction(150.00);

	cout << "2. ";
	ptr1->debitTransaction(5.00);

	cout << "3. ";
	ptr1->creditTransaction(200.00);

	cout << "(*) Final account information.\n\n";

	ptr1->print(cout);
	cout << endl << endl;

	//////////////////////////////////////////////////////////////////////

	cout << "==== Test for Savings Account! ====\n\n";

	cout << "1. ";
	ptr2->debitTransaction(150.00);

	cout << "3. ";
	ptr2->creditTransaction(200.00);
	
	cout << "2. ";
	ptr2->debitTransaction(5.00);

	cout << "(*) Final account information.\n\n";

	ptr2->print(cout);
	cout << endl << endl;

	system("pause");
	return 0;
}