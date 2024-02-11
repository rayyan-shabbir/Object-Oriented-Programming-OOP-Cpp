#include <iostream>
using namespace std;

class IntegerSet
{
    int *array;     //Data Member integer pointer
    const int size; //Data Member constant integer

public:
    //=======Declerations=======
    //***Constructors***
    IntegerSet(int s);                 //Default Constructor
    IntegerSet(const IntegerSet &obj); //Copy Constructor
    ~IntegerSet();                     //Destructor

    //***Overloaded Operator***
    IntegerSet operator=(const IntegerSet &obj);  //Assignment(=) Operator
    bool operator==(const IntegerSet &obj) const; //Equal(==) Operator
    IntegerSet operator!() const;                 //Logic Not(!) Operator

    //***Member Functions***
    void insertElement(int k);                                  //Insert Element
    void deleteElement(int k);                                  //Delete Element
    IntegerSet unionOfSets(const IntegerSet &obj) const;        //Union of Set
    IntegerSet intersectionOfSets(const IntegerSet &obj) const; //Intersection of Set
    bool findElement(int key);                                  //Find Element
    bool isNullSet();                                           //Null Set

    //Making Friend Stream Insertion Operator(<<)
    friend ostream &operator<<(ostream &out, const IntegerSet &obj);
};
//***Constructors***

//Default Constructor
IntegerSet::IntegerSet(int s) : size(s)
{
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = 0;
}
//Copy Constructor
IntegerSet::IntegerSet(const IntegerSet &obj) : size(obj.size)
{
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = obj.array[i];
}
//Destructor
IntegerSet::~IntegerSet()
{
    if (this != NULL)
        delete[] array;
}

//***Overloaded Operators***

//Stream Insertion Operator(<<)
ostream &operator<<(ostream &out, const IntegerSet &obj)
{

    for (int i = 0; i < obj.size; i++)
    {
        if (obj.array[i] == 1)
            out << i << " ";
    }

    cout << endl;

    int count = 0;
    for (int i = 0; i < obj.size; i++)
    {
        if (obj.array[i] == 0)
            count++;
    }

    if (count == obj.size)
        out << "---" << endl;

    return out;
}
//Assignment(=) Operator
IntegerSet IntegerSet::operator=(const IntegerSet &obj)
{
    if (this != &obj)
    {
        if (obj.size == size)
        {
            for (int i = 0; i < size; i++)
                this->array[i] = obj.array[i];
        }
    }

    return *this;
}
//Equal(==) Operator
bool IntegerSet::operator==(const IntegerSet &obj) const
{
    if (size != obj.size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] != obj.array[i])
                return false;
        }
    }
    return true;
}
//Logic Not(!) Operator
IntegerSet IntegerSet::operator!() const
{
    IntegerSet rev(this->size);

    for (int i = 0; i < size; i++)
    {
        if (array[i] == 1)
            rev.array[i] = 0;
        else if (array[i] == 0)
            rev.array[i] = 1;
    }

    return rev;
}

//***Member Functions***

//Insert Element
void IntegerSet::insertElement(int k)
{
    if (k >= 0 && k < size)
        this->array[k] = 1;
    else
        cout << "***k is not an index of your array***" << endl;
}
//Delete Element
void IntegerSet::deleteElement(int k)
{
    if (k >= 0 && k < size)
        this->array[k] = 0;
    else
        cout << "***k is not an index of your array***" << endl;
}
//Union of Set
IntegerSet IntegerSet::unionOfSets(const IntegerSet &obj) const
{
    if (size == obj.size)
    {
        IntegerSet unionT(size);

        for (int i = 0; i < size; i++)
        {
            if (this->array[i] == 1 || obj.array[i] == 1)
                unionT.array[i] = 1;
            else if (this->array[i] == 0 && obj.array[i] == 0)
                unionT.array[i] = 0;
        }
        return unionT;
    }

    cout << "Sizes are not same(equal).So, Union is not possible!" << endl;
    exit(0);
}
//Intersection of Set
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &obj) const
{
    if (size == obj.size)
    {
        IntegerSet interT(size);

        for (int i = 0; i < size; i++)
        {
            if (this->array[i] == 0 || obj.array[i] == 0)
                interT.array[i] = 0;
            else if (this->array[i] == 1 && obj.array[i] == 1)
                interT.array[i] = 1;
        }
        return interT;
    }

    cout << "Sizes are not same(equal).So, Intersection is not possible!" << endl;
    exit(0);
}
//Find Element
bool IntegerSet::findElement(int key)
{
    if (key >= 0 && key < size)
    {
        if (array[key] == 1)
            return true;
    }

    return false;
}
//Null Set
bool IntegerSet::isNullSet()
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    IntegerSet rdx1(7), rdx2(rdx1), rdx3(7);

    // ****By Default Constructor****
    // cout << rdx1;
    // ****By Copy Constructor****
    // cout << rdx2;

    // ****Assignment(=) Operator****
    // rdx1 = rdx2;
    // cout << rdx1;

    // ****Equal(==) Operator****
    // cout << (rdx3 == rdx1) << endl;

    // ****Logic Not(!) Operator****
    // IntegerSet temp = (!rdx1);
    // cout << temp;

    // ****Insert Element Member Function****
    // rdx1.insertElement(3);
    // rdx1.insertElement(4);
    // rdx1.insertElement(1);
    // rdx1.insertElement(0);
    // rdx1.insertElement(-5);
    // cout << rdx1;

    // rdx3.insertElement(3);
    // rdx3.insertElement(4);
    // rdx3.insertElement(-5);

    // ****Delete Element Member Function****
    // rdx1.deleteElement(0);
    // rdx1.deleteElement(-5);
    // rdx1.deleteElement(1);
    // cout << rdx1;

    // ****Find Element Member Function****
    // cout << rdx1.findElement(2) << endl;

    // ****Null Set Member Function****
    // cout << rdx1.isNullSet() << endl;
    // cout << rdx2.isNullSet() << endl;

    // ****Union of Set****
    // rdx2 = (rdx1.unionOfSets(rdx3));
    // cout << rdx2;

    // ****Intersection of set****
    // rdx2 = (rdx1.intersectionOfSets(rdx3));
    // cout << rdx2;

    //**** THANKYOU ****
    return 0;
}