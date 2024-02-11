#include "iostream"
using namespace std;

//template<class t>  
      //OR
template <typename t> //Add Function Template for different data types
t add(t a, t b) {
    return a+b;
}

template <typename t> //Subtraction Function Template for different data types
t sub(t a, t b) {
    return a-b;
}

int main() {
    //FOR ADDITION
    cout << "***FOR ADDITION***" << endl;
    cout << add(7, 6) << endl;                      //Making Function for integer
    cout << add<float>(3.22223777777f , 5.78912377777f) << endl;       //Making Function for float
    cout << add<double>(3.228374737777777, 5.773738383777777) << endl;   //Making Function for long


    //FOR SUBTRACTION
    cout << "***FOR SUBTRACTION***" << endl;
    cout << sub(7, 6) << endl;                      //Making Function for integer
    cout << sub(3.22223f, 5.789123f) << endl;       //Making Function for float
    cout << sub(3.22837473, 5.773738383) << endl;   //Making Function for long

    return 0;
}