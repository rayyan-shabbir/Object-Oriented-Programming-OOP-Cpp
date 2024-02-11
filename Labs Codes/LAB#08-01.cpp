#include <iostream>
using namespace std;

template <class t>
class Array
{
    t *data;
    int size;

public:
    //CONSTRUCTORS
    Array()
    {
        size = 5;
        data = new t[size];

        for (int i = 0; i < size; i++)
            data[i] = 0;
    }
    Array(int size)
    {
        this->size = size;
        data = new t[size];

        for (int i = 0; i < size; i++)
            data[i] = 0;
    }
    Array(const Array &obj)
    {
        size = obj.size;
        data = new t[size];

        for (int i = 0; i < size; i++)
            data[i] = obj.data[i];
    }
    ~Array()
    {
         delete[] data;
    }
    //MEMBER FUNCTIONS
    int getSize()
    {
        return size;
    }

    void setElement(t k, int i)
    {
        if (i >= 0 && i < size)
            data[i] = k;
        else
            cout << "***Index does Not Exists***" << endl;
    }

    int countElement(t key)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
                count++;
        }

        if(count != 0) return count;

        return -1;
    }

    //OVERLOADED OPERATORS
    Array operator=(const Array &obj)
    {
        if (this != &obj)
        {
            if (size != obj.size)
            {
                delete[] data;

                size = obj.size;
                data = new t[size];
            }
            for (int i = 0; i < size; i++)
                data[i] = obj.data[i];
        }
        return *this;
    }

    Array getSubArray(int start_index, int end_index)
    {
        int count = 0;
        for (int i = start_index; i <= end_index; i++)
            count++;

        Array temp(count);
        for (int i = 0; i < count; i++)
        {
            temp.data[i] = data[start_index++];
        }

        return temp;
    }

    Array operator+(const Array& obj) const
    {
        int j = size;
        Array temp(obj.size + size);

        for (int i = 0; i < size; i++) temp.data[i] = data[i];
        for (int i = 0; i < obj.size; i++) temp.data[j++] = obj.data[i];
        
        return temp;
    }

    bool operator==(const Array& obj) const
    {
        if(size != obj.size) return false;

        for (int i = 0; i < size; i++)
        {
            if(obj.data[i] != data[i]) return false;
        }
        return true;
    }

    t& operator[] (int i) {
        if(i >= 0 && i < size) return data[i];

        cout << "Index does not exists";
        exit(0);
    }

    t operator[] (int i) const
    {
        if(i >= 0 && i < size) return data[i];

        cout << "Index does not exists";
        exit(0);
    }

    template <typename t1>
    friend ostream &operator<<(ostream &, const Array<t1> &);
    template <typename t2>
    friend istream &operator>>(istream &, Array<t2> &);
};

template <typename t1>
ostream &operator<<(ostream & out, const Array<t1> &obj) {
    for (int i = 0; i < obj.size; i++)
    {
        out << "data[" << i <<"] = " << obj.data[i] << endl;
    }
    return out;
}

template <typename t2>
istream &operator>>(istream &in, Array<t2> &obj) {
    for (int i = 0; i < obj.size; i++)
    {
        cout << "Enter data at " << i <<" : ";
        in >> obj.data[i];
    }
    return in;
}

int main()
{
    Array<int> obj1(3), obj4, obj5(obj1);
    Array<float> obj2, obj3(4);

    Array<char> obj8, obj9(4);
    const Array<int> obj6;

    // cin >> obj8;
    // cout << obj8;

    cout << "***Set Element***" << endl;
    obj1.setElement(5.6, 2);
    obj1.setElement(22.9, 1);
    obj4.setElement(5.6, 2);
    obj4.setElement(-22.6, 0);
    obj4.setElement(1.9, 4);

    // obj2.setElement(5.6, 2);
    // obj2.setElement(-22.6, 0);
    // obj2.setElement(1.9, 4);

    // obj1.setElement(5.6, 1);
    // obj1.setElement(22.6, 0);

    // cout << "***Count Element*** : " << obj1.countElement(5);

    // cout << "***Default Constructor***" << endl;
    // cout << obj2;
    // cout << obj4;

    // cout << "***Size Constructor***" << endl;
    // cout << obj1;
    // cout << obj3;

    // cout << "***Copy Constructor***" << endl;
    // cout << obj5;

    // cout << "***Size of obj1 = " << obj1.getSize() << endl;

    // cout << "***Comparision Operator***" << endl;
    // cout << (obj1 == obj4);

    // cout << "***Assignment Operator***" << endl;
    // obj4 = obj1;
    // cout << obj4;

    // cout << "***Subscript*** " << endl;
    // obj1[1] = 6;
    // cout << obj6[3];
    // cout << obj1[1];

    // cout << "***GetSub Array***" << endl;
    // obj4 = (obj1.getSubArray(1, 3));
    // cout << obj4;

    cout << "***Arithmetic binary(+)***" << endl;
    Array<int> obj7 = (obj1 + obj4);
    cout << obj7;

    return 0;
}