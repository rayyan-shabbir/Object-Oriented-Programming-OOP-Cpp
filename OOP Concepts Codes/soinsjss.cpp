#include "iostream"
#include "fstream"
using namespace std;


class BooksData {
    public:

    int identifier;
    string title;
    string name;
    float price;

    void print() {
        cout << identifier << "\t" << name << " " << title << " " << price << endl;
    }


};

int main() {
    // int id;
    // string str;

    BooksData obj[4];

    //Opening File using Member open() Function and READING from it
    ifstream inf1;      
    inf1.open("test1.txt", ios::in);

    if(!inf1) {
        cout << "file not opened" << endl;
        exit(0);
    }
    // getline(inf1, obj[0].title);
    // cout << obj[0].title;

    for (int i = 0; i < 4; i++)
    {
        while(inf1 >> obj[i].title) {
            //getline(inf1, obj[i].title);
            cout << obj[i].title << " ";
            // obj[i].print();
        }
        cout << endl;
            
    }
    

    inf1.close();

    cout << endl;

    
    return 0;
}

