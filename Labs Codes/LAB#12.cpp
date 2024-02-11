#include <iostream>
using namespace std;

class Vehicle {
    protected:
        float load, weight, miles;
    
    public:
        Vehicle() {
            load = weight = miles = 0;
            cout << "Vehicle's Default Constructor" << endl;
        }
        Vehicle(float load, float weight, float miles) {
            this->load = load;
            this->weight = weight;
            this->miles = miles;
            cout << "Vehicle's Parametrize Constructor" << endl;
        }
        Vehicle(const Vehicle& obj) {
            load = obj.load;
            weight = obj.weight;
            miles = obj.miles;
            cout << "Vehicle's Copy Constructor" << endl;
        }

        void initialize(float load, float weight, float miles) {
            this->load = load;
            this->weight = weight;
            this->miles = miles;
        }

        float efficiency() {
            return (load / (load + weight));
        }

        float cost_per_ton(float fuel_cost) {
            return (fuel_cost / (load / 2000.0));
        }
};

class Driver {
    protected:
    float pay, weight;

    public:
        Driver() {
            pay = weight = 0;
            cout << "Drivers's Default Constructor" << endl;
        }
        Driver(float pay, float weight) {
            this->pay = pay;
            this->weight = weight;
            cout << "Drivers's Parametrize Constructor" << endl;
        }
        Driver(const Driver& obj) {
            pay = obj.pay;
            weight = obj.weight;
            cout << "Drivers's Copy Constructor" << endl;
        }

        void initialize(float pay, float weight) {
            this->pay = pay;
            this->weight = weight;
        }

        float cost_per_mile() {
            return (pay / 55.0);
        }

        float drivers_weight() {
            return this->weight;
        }
};

class Crane : public Vehicle, public Driver
{
    public:
        Crane() : Vehicle(), Driver() 
        {
            cout << "Crane's Default Constructor" << endl;
        }
        Crane(float load, float weight1, float miles, float pay, float weight2) :Vehicle(load, weight1, miles), Driver(pay, weight2)
        {
            cout << "Crane's Parametrize Constructor" << endl;
        }
        Crane(const Crane& obj) : Vehicle(obj), Driver(obj) 
        {
            cout << "Crane's Copy Constructor" << endl;
        }

        void initialize(float load, float weight1, float miles, float pay, float weight2) {
            this->load = load;
            this->Vehicle::weight = weight1;
            this->miles = miles;
            this->pay = pay;
            this->Driver::weight = weight2;
        }

        float cost_per_full_day(float cost_of_gas) {
            return ((8.0 * pay + 8.0 * cost_of_gas * 55.0) / miles);
        }

        float total_weight() {
            float total_weight = (Vehicle::weight + Driver::weight);

            return total_weight;
        }
};

int main() {
    Crane samsung;

    samsung.initialize(4.5, 123.33, 21.76, 1500.20, 63);
    samsung.Driver::initialize(990.96, 57.2);
    
    cout << "Efficiency: " << samsung.efficiency() << endl;
    cout << "Cost/Mile: " << samsung.cost_per_mile() << endl;
    cout << "Cost/Day: " << samsung.cost_per_full_day(6.31) << endl;
    cout << "Total Weight: " << samsung.total_weight() << endl;


    Vehicle obj1, obj2(1.3, 49, 11.7), obj3(obj1);
    Driver obj4, obj5(2230.344, 71), obj6(obj5);
    Crane obj7, obj8(23, 11, 12, 3, 9), obj9(obj7);

    return 0;
}