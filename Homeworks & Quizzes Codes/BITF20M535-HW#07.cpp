#include <iostream>
using namespace std;

class Package {
    string sName, rName;
    string sAdress, rAdress;
    string sCity, rCity;
    float weight;
    float costPerOunce;

    public:
        //Constructor
        Package (string sName, string rName, string sAdress, string rAdress, string sCity, string rCity, float weight, float costPerOunce) {
            setSenderName(sName);
            setReceiverName(rName);

            setSenderAdress(sAdress);
            setReceiverAdress(rAdress);

            setSenderCity(sCity);
            setReceiverCity(rCity);

            setWeight(weight);

            setCostPerOunce(costPerOunce);
        }

        //Setters
        void setSenderName(string sName) {
            this->sName = sName;
        }

        void setReceiverName(string rName) {
            this->rName = rName;
        }

        void setSenderAdress(string sAdress) {
            this->sAdress = sAdress;
        }

        void setReceiverAdress(string rAdress) {
            this->rAdress = rAdress;
        }

        void setSenderCity(string sCity) {
            this->sCity = sCity;
        }

        void setReceiverCity(string rCity) {
            this->rCity = rCity;
        }

        void setWeight(float weight) {
            if(weight > 0) this->weight = weight;
            else this->weight = 0;
        }

        void setCostPerOunce(float costPerOunce) {
            if(costPerOunce > 0) this->costPerOunce = costPerOunce;
            else this->costPerOunce = 0; 
        }

        //Getters
        string getSenderName() {
            return sName;
        }

        string getReceiverName() {
            return rName;
        }

        string getSenderAdress() {
            return sAdress;
        }

        string getReceiverAdress() {
            return rAdress;
        }

        string getSenderCity() {
            return sCity;
        }

        string getReceiverCity() {
            return rCity;
        }

        float getWeight() {
            return weight;
        }

        float getCostPerOunce() {
            return costPerOunce;
        }

        //CalculateCost Member Function
        float calculateCost() {
            float cost = weight * costPerOunce;
    
            return cost;
        }
};

class TwoDayPackage : public Package
{
    float flatFee;

    public:
        //Constructor
        TwoDayPackage (string sN, string rN, string sA, string rA, string sC, string rC, float we, float cos, float flatFee) : Package (sN, rN, sA, rA, sC, rC, we, cos)
        {
            setFlatFee(flatFee);
        }

        //Setter
        void setFlatFee(float flatFee) {
            if(flatFee > 0) this->flatFee = flatFee;
            else this->flatFee = 0;
        }

        //Getter
        float getFlatFee() {
            return flatFee;
        }

        //CalculateCost Member Function
        float calculateCost() {
            float shippingCost = 0;
            float weightBase = 0;

            weightBase = Package :: calculateCost();
            shippingCost  = (this->getFlatFee()) + weightBase;

            return shippingCost;
        }

};

class OvernightPackage : public Package
{
    float feePerOunce;

    public:
        //Constructor
        OvernightPackage(string sN, string rN, string sA, string rA, string sC, string rC, float we, float cos, float feePerOunce) : Package (sN, rN, sA, rA, sC, rC, we, cos)
        {
            setFeePerOunce(feePerOunce);
        }

        //Setter
        void setFeePerOunce(float feePerOunce) {
            if(feePerOunce > 0) this->feePerOunce  = feePerOunce ;
            else this->feePerOunce  = 0;
        }

        //Getter
        float getFeePerOunce() {
            return feePerOunce;
        }

        //CalculateCost Member Function
        float calculateCost() {
            float cost = this->getFeePerOunce() + this->getCostPerOunce();

            return (this->getWeight() * cost);
        }

};


int main() {
    //***Class Package***
    Package obj1("Sulaiman", "Rayan", "Wapda Town", "Ali Town", "Gujranwala", "Lahore", 13.5, 1300);
    cout << "Total Cost: " << obj1.calculateCost() << endl;



    //***Class TwoDayPackage***
    TwoDayPackage obj2("Ahmed", "Faizzan", "Town", "Ali Town", "Gujrat", "Karachi", 31, 2020, 120);
    cout << "Total Cost: " << obj2.calculateCost() << endl;


    //***Class OvernightPackage***
    OvernightPackage obj3("Sulaiman", "Rayan", "Wapda Town", "Ali Town", "Gujranwala", "Lahore", 5, 10, 2);
    cout << "Total Cost: " << obj3.calculateCost() << endl;

    return 0;
}