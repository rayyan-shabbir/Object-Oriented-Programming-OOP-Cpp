#include "iostream"
using namespace std;

//METHOD #01 :: When we have to deal '2' data types at a time in function template
//template<class t>  
      //OR
template <typename t>
t add1(t a, t b) {
    return a+b;
}

//METHOD #02 :: When we have to deal '2' data types at a time in function template
//template<class t>  
      //OR
template <typename t1, typename t2>
t2 add2(t1 a, t2 b) {
    return a+b;
}

int main() {
    //METHOD #01 :: when we have to deal 2 data types at a time in function template

    cout << "**METHOD#01**" << endl;
    cout << add1<int>(5, 3.8) << endl;    //Now it make Add Template for return type "int"
    cout << add1<float>(5, 3.8) << endl;  //Now it make Add Template for return type "float"


    //METHOD #02 :: when we have to deal 2 data types at a time in function template

    cout << "**METHOD#02**" << endl;
    // cout << add2(5, 3.3) << endl;    /*Now it make Add Template for 2nd "Parameter' 
    //                                   return type "float" */
    // cout << add2(1.6, 2) << endl;  /*Now it make Add Template for 2nd "Parameter' 
    //                                   return type "int */

                 //OR

    cout << add2<int, float>(5, 3.3) << endl;    /*Now it make Add Template for 2nd "Parameter' 
                                                    return type "float" */
    cout << add2<float, int>(1.6, 2) << endl;  /*Now it make Add Template for 2nd "Parameter' 
                                      `               return type "int */
    return 0;
}