#include "iostream"
using namespace std;

class Integer {
    int *val;
    
    public:
        //Default Constructor
        Integer () {
            val = new int(0);
        }

        //Parametrize Constructor
        Integer (int number) {
            val = new int(number);
        }

        //Copy Constructor
        Integer (const Integer &obj) {
            val = new int;
            *val = *(obj.val);
            //OR
            //*val = new int(*(obj.val));
        }

        //Destructor
        ~Integer () {
            delete val;
        }

        //Assignment Operator
        Integer operator= (const Integer &obj) {
            if(this != &obj)
                *val = *(obj.val);
                
            return *this;
        }

        //Member Input Function
        void inputVal() {
            cout << "Enter Number: ";
            cin >> *val;
        }

        //Setter
        void setVal(int number) {
            *val = number;
        }

        //Getter
        int getVal() {
            return *val;
        }

        //Member Display Function
        void display() {
            cout << "Value: " << *val << endl;
        }
};

int main() {
    Integer  obj1, obj2(93);
    //obj2 = obj1;

    obj2.setVal(62);
    obj2.inputVal();

    obj2.display();

    cout << obj1.getVal() << endl;
    return 0;
}
