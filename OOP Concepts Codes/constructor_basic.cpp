#include <iostream>
using namespace std;

class Book {
    public:
        string title;
        string author;
        int pages;
        Book(string title1, string author1, int pages1) {
            cout << "Creating constructor" << endl;
            title = title1;
            author = author1;
            pages = pages1; 
        }
};

int main() {
    Book book1("Harry Potter", "RK Rowden", 370);
   
    cout << book1.title << endl;
    cout << book1.author << endl;
    cout << book1.pages << endl;
}