#include "iostream"
using namespace std;

class RationalNumber
{
    int numerator;
    int denominator;

public:
    //Mutators
    void setNum (int numerator)
    {
        this->numerator = numerator;
    }

    void setDen (int denominator)
    {
        if (denominator == 0) {
             this->denominator = 1;
        } else if (denominator < 0) {
            this->denominator = -1 * denominator;
            this->numerator = -1 * numerator;
        } else {
            this->denominator = denominator;
        }
    }

    //Accessors
    int getNum ()
    {
        return numerator;
    }

    int getDen ()
    {
        return denominator;
    }

    //Constructors
    RationalNumber (int numerator, int denominator)
    {
        setNum(numerator);
        setDen(denominator);
    }

    RationalNumber (int numerator)
    {
        setNum(numerator);
        denominator = 1;
    }

    //Overloaded Operators
    RationalNumber operator+ (const RationalNumber &rdx) const
    {
        RationalNumber temp ((numerator * rdx.denominator + denominator * rdx.numerator), denominator * rdx.denominator);
        return temp;
    }

    RationalNumber operator- (const RationalNumber &rdx) const
    {
        RationalNumber temp ((numerator * rdx.denominator - denominator * rdx.numerator), denominator * rdx.denominator);
        return temp;
    }

    RationalNumber operator* (const RationalNumber &rdx) const
    {
        RationalNumber temp (numerator * rdx.numerator, denominator * rdx.denominator);
        return temp;
    }

    RationalNumber operator/ (const RationalNumber &rdx) const
    {
        RationalNumber temp (numerator * rdx.denominator, rdx.numerator * denominator);
        return temp;
    }

    bool operator< (const RationalNumber &rdx) const
    {
        if (numerator * rdx.denominator < rdx.numerator * denominator)
            return true;

        return false;
    }

    bool operator== (const RationalNumber &rdx) const
    {
        if (numerator * rdx.denominator == rdx.numerator * denominator)
            return true;

        return false;
    }

    RationalNumber operator- ()
    {
        if (numerator > 0)
            numerator = -1 * numerator;

        return *this;
    }

    bool operator! () const
    {
        if (numerator < 0)
            return true;

        return false;
    }

    friend ostream &operator<<(ostream &out, const RationalNumber &rdx);
    friend istream &operator>>(istream &in, RationalNumber &rdx);
};

//Stream insertion operator
ostream &operator<< (ostream &out, const RationalNumber &rdx)
{
    cout << "Rational Number is = ";
    out << rdx.numerator << "/" << rdx.denominator << endl;

    return out;
}

//Stream extraction operator
istream &operator>> (istream &in, RationalNumber &rdx)
{
    char c;
    int den;

    cout << "Enter Rational Number (In ' / ' Form): ";
    in >> rdx.numerator >> c >> den;

    rdx.setDen(den);
    return in;
}

int main()
{
    RationalNumber rdx1(8, 4), rdx2(3);

    cin >> rdx2;
    cout << rdx2;

    //cout << (!rdx2) << endl;
    //RationalNumber temp = -rdx2;

    //cout << temp;
    //cout << (rdx1 == rdx2);
    //cout << (rdx1 < rdx2);

    //RationalNumber temp = rdx1 / rdx2;
    //RationalNumber temp = rdx1 * rdx2;
    //RationalNumber temp = rdx1 + rdx2;
    //RationalNumber temp = rdx1 - rdx2;

    //cout << temp;
    /*cout << rdx1;
    cin >> rdx1;
    cout << rdx1;*/

    //rdx1.setDen(0);
    //rdx1.print();
    //rdx2.print();

    //cout << rdx1.getDen() << endl;
    //cout << rdx2.getDen() << endl;
    return 0;
}