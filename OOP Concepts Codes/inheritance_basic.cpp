#include <iostream>
using namespace std;

class Chef {
    public:
        void makeChicken() {
            cout << "The Chef can make chicken" << endl;
        }
        void makeSalad() {
            cout << "The Chef can make salad" << endl;
        }
        void makeSpecialDish() {
            cout << "The Chef can make bbq ribs" << endl;
        }

};

class ItalianChef : public Chef {
    public:
        void makeSpecialDish() {
            cout << "The Chef can make Chowmein";
        }
};

int main() {
    Chef nchef;
    ItalianChef ichef;
    nchef.makeChicken();
    ichef.makeChicken();

    nchef.makeSpecialDish();
    ichef.makeSpecialDish();

    return 0;
}