 #include "iostream"
using namespace std;

class Array {
    int *arr;   //holds reference of array, created on heap
    int size;   //holds the maximum size of array

    public:
        //Default Constructor
        Array() {
            size = 5;               //default size of array
            arr = new int[size];       //allocating array on heap

            for(int i = 0; i < size; i++) 
                arr[i] = 0;         //initializing array to default data
        }

        //Overloaded Constructor. accept the size of array as parameter
        Array(int size) {
            this->size = size;      //initializing size of array
            arr = new int[size];    //allocating array on heap

            for(int i = 0; i < size; i++)
                arr[i] = 0;         //initializing array to default data
        }

        //Overloaded Constructor. accept an array with its size and intialize object's data with them
        Array(int arr[], int size) {
            this->size = size;               //initializing size of array
            this->arr = new int[size];       //allocating array on heap

            for(int i = 0; i < size; i++)
                this->arr[i] = arr[i];       //initializing object's array with the data of array passed as argument
        }

        //Copy Constructor (Necessary BIG-3)
        Array(const Array& obj) {
            size = obj.size;                    //initializing size of array
            this->arr = new int[size];          //allocating array on heap

            for(int i = 0; i < size; i++) 
                this->arr[i] = obj.arr[i];      //initializing object's array with the data of right-hand side object
        }

        //Destructor (Necessary BIG-3)
        ~Array() {
            delete[] arr;       //free memory resources allocated on heap 
        }

        //Overloaded Assignment Operator (Necessary BIG-3)
        Array operator= (const Array& obj) {
            
            if(this != &obj) {              //avoiding self assignment of object
                if(size != obj.size) {      //checking the sizes of both object's array
                    
                    delete[] arr;           //freeing memory resources allocated on heap

                    size = obj.size;        //setting the size of left-hand side object
                    arr = new int[size];    //allocating new array on heap for left-hand side object
                }
                for(int i = 0; i < size; i++) 
                    arr[i] = obj.arr[i];    //initializing object's array with the data of right-hand side object
            }
            return *this;
        }

        //Overloaded Index [] Operator for non-constant objects to handle lvalue and rvalue
        int& operator[] (int index) {

            if(index >= 0 && index < size)      //bound checking of array's index
                return arr[index];              //returning the legal memory location

            cout << "You enter a wrong index";
            exit(0);                            //closing the program (if required)
        }

        //overloaded index [] operator for constant objects to handle only rvalue
        int operator[] (int index) const
        {
            if(index < 0 && index >= size)      //bound checking of array's index
                exit(0);                        //closing the program (if required)

            return arr[index];                   //returning the legal memory location
        }

        //Overloaded Addition operator two add two arrays
        Array operator+ (const Array& obj) {
            Array temp;                     //Creating a temporary obj

            if(this->size == obj.size) {   //Comparing sizes of LHS and RHS array's
                temp.size = size;          //Assigning size to newly created temp obejct

                for(int i = 0; i < size; i++) {
                    temp.arr[i] = arr[i] + obj.arr[i];  //Adding two arrays
                }
            }
            return temp;   //Return the array which consist addition of two arrays
        }
 
        //Member Function to take input from user for array
        void getInput() {
            for(int i = 0; i < size; i++) {
                cout << "Enter value at index "<<i<<" : ";
                cin >> arr[i];
            }
                
        }

        //Member Function to display array
        void print() {
            for(int i = 0; i < size; i++)
                cout << "Arr["<<i<<"] = " << arr[i] << endl;
            cout << endl;
        }
};

int main() {
    int arr[4] = {1, 3, 5, 7};
    Array arr1, arr2(4), arr3(arr, 4), arr4(arr2);

    arr2.getInput();
    Array temp = arr2 + arr3;
    temp.print();

    //const Array arr5(arr3);
    //arr5[2] = 8; ERROR

    //cout << arr5[2] << endl;
    //arr3[1] = 9; 
    //cout << arr3[1] << endl;;


    /*arr2.print();
    arr2 = arr3;
    arr2.print();*/

    /*arr1.getInput();
    arr1.print();*/

    //arr1.print();
    
    //arr3.print();
    //arr4.print();

    return 0;
}