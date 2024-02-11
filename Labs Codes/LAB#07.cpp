#include <iostream>
using namespace std;

class Collection
{
    float *data;
    int size;

public:
    //Constructors
    Collection(int s);
    Collection(float array[], int s);
    Collection(const Collection &obj);
    ~Collection();

    //Member Function
    int getSize();
    void insertElement(float f, int i);
    bool findElement(float key);
    Collection operator=(const Collection &obj);
    Collection getSubCollection(int start_index, int end_index);


    Collection operator-(const Collection &obj) const;
   

    bool operator!=(const Collection &obj);
    float &operator[](int index);
    float operator[](int index) const;
    bool operator+();

    friend ostream &operator<<(ostream &out, const Collection &obj);
    friend istream &operator>>(istream &in, Collection &obj);
};

//Constructors
Collection::Collection(int s)
{
    size = s;
    data = new float[size];

    for (int i = 0; i < size; i++)
        data[i] = 0;
}

Collection::Collection(float array[], int s)
{
    size = s;
    data = new float[size];

    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
            data[i] = array[i];
        else
            data[i] = 0;
    }
}

Collection::Collection(const Collection &obj)
{
    size = obj.size;
    data = new float[size];

    for (int i = 0; i < size; i++)
        data[i] = obj.data[i];
}

Collection::~Collection()
{
    
    delete[] data;
}

//Member Function
int Collection::getSize()
{
    return size;
}

void Collection::insertElement(float f, int i)
{
    if (i >= 0 && i < size)
    {
        if (f > 0)
            data[i] = f;
        else
            data[i] = 0;
    }

    cout << "Index does not exist" << endl;
}

bool Collection::findElement(float key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == data[i])
            return true;
    }

    return false;
}

Collection Collection::operator=(const Collection &obj)
{
    if (this != &obj)
    {
        if (size != obj.size)
        {
            delete[] data;

            size = obj.size;
            data = new float[this->size];
        }

        for (int i = 0; i < size; i++)
            data[i] = obj.data[i];
    }

    return *this;
}

Collection Collection::getSubCollection(int start_index, int end_index)
{
    int count = end_index-start_index+2;
    for (int i = start_index; i <= end_index; i++)
        count++;

    Collection temp(count);

    for (int i = 0; i < count; i++) {
        temp.data[i] = this->data[start_index];
        start_index++;
    }
    return temp;
}

Collection Collection::operator-(const Collection &obj) const
{
    int q=obj.size;
    Collection temp1(q);
    
    if (size == obj.size)
    {
        Collection temp(size);

        for (int i = 0; i < size; i++)
        {
            temp.data[i] = data[i] - obj.data[i];
        }

        return temp;
    }

    cout << "Sizes are not equal So, subtraction is not possible" << endl;
    return temp1;
}

bool Collection::operator!=(const Collection &obj)
{
    if (size != obj.size)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] != obj.data[i])
                return true;
        }
    }

    return false;
}

float& Collection::operator[](int index)
{
    if (index >= 0 && index < size)
        return data[index];

    cout << "Index does not exists" << endl;

    exit(0);
}

float Collection::operator[](int index) const
{
    if (index >= 0 && index < size)
        return data[index];

    cout << "Index does not exists" << endl;

    exit(0);
}

bool Collection::operator+()
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == 0)
            return false;
    }

    return true;
}

ostream &operator<<(ostream &out, const Collection &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        out << "Data[" << i << "] = " << obj.data[i] << endl;
        ;
    }

    return out;
}

istream &operator>>(istream &in, Collection &obj)
{
    int arr[obj.size];
    for (int i = 0; i < obj.size; i++)
    {
        cout << "Enter Data[" << i << "] : " << endl;
        in >> arr[i];
    }

    for (int i = 0; i < obj.size; i++)
    {
        if (arr[i] > 0)
            obj.data[i] = arr[i];
        else
            obj.data[i] = 0;
    }

    return in;
}

int main()
{
    float arr[5] = {1.3, -3.5, 5.7, -7.9, -9.2};
    Collection obj1(5), obj2(arr, 5), obj3(obj2);
    const Collection obj4(obj2);

    // cout << obj2.operator+() << endl;
    // cout << obj4[1] << endl;
    // obj3 = (obj1 - obj2);
    // int q = 0;
    // cout << "Enter data you wanted to input" << endl;
    // cin >> q;

    // if(q >= 0) obj2[3] = q;

    // cout << obj2[3] << endl;
    // cout << (obj3 != obj2) << endl;
    // cout << (obj1 != obj2) << endl;
    // cin >> obj1;
    // Collection temp1 = obj2.getSubCollection(1, 3);

    // cout << temp1 << endl;
    // obj1 = obj2;
    // cout << obj2.findElement(-3.5) << endl;
    // obj2.insertElement(6.1, 1);

    // cout << obj1 << endl;
    // cout << obj2 << endl;
    // cout << obj3.getSize() << endl;
    // cout << obj2.getSize() << endl;
    // cout << obj1.getSize() << endl;
    return 0;
}