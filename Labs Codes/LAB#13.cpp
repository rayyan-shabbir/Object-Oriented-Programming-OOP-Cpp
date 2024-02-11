#include <iostream>
using namespace std;

class Ship {
    string name;
    string year;

    public:
        Ship(string name = " ", string year = " ") {
            this->setName(name);
            this->setYear(year);
        }

        void setName(string name) {
            this->name = name;
        }
        void setYear(string year) {
            this->year = year;
        }

        string getName() {
            return this->name;
        }
        string getYear() {
            return this->year;
        }

        virtual void print() {
            cout << "Ship Name: " << name << endl;
            cout << "Ship Year: " << year << endl;
        }
};

class CruiseShip : public Ship
{
    int no_passengers;

    public:
        CruiseShip(string name = " ", string year = " ", int no_passengers = 0) : Ship(name, year)
        {
            this->setPassengers(no_passengers);
        }

        void setPassengers(int no_passengers) {
            this->no_passengers = no_passengers;
        }

        int getPassengers() {
            return this->no_passengers;
        }

        void print() {
            Ship::print();
            cout << "No of Passengers are: " << no_passengers << endl;
        }
};


class CargoShip : public Ship
{
    int cargo_capacity;

    public:
        CargoShip(string name = " ", string year = " ", int cargo_capacity = 0) : Ship(name, year)
        {
            this->setCC(cargo_capacity);
        }

        void setCC(int cargo_capacity) {
            this->cargo_capacity = cargo_capacity;
        }

        int getCC() {
            return this->cargo_capacity;
        }

        void print() {
            cout << "Ship Name: " << getName() << endl;
            cout << "Ship Cargo Capacity: " << cargo_capacity << endl;
        }
};

class BattleShip : public Ship
{
    int no_missiles;

    public:
        BattleShip(string name = " ", string year = " ", int no_missiles = 0) : Ship(name, year)
        {
            this->setMissiles(no_missiles);
        }

        void setMissiles(int no_missiles) {
            this->no_missiles = no_missiles;
        }

        int getMissiles() {
            return this->no_missiles;
        }

        void print() {
            cout << "Shape Name: " << getName() << endl;
            cout << "Missile's Capacity: " << no_missiles << endl;
        }
};

int main() {
    Ship spObj("Abdullah", "1887");
    CruiseShip crObj("Rayan", "1932", 31);
    CargoShip coObj("Ahmed", "2002", 13);
    BattleShip btObj("Arshman", "2020", 6);

    Ship* arr[4] = {&spObj, &crObj, &coObj, &btObj};

    for (int i = 0; i < 4; i++)
        arr[i]->print();
    
    return 0;
}