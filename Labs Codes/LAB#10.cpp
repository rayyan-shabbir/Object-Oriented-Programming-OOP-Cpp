#include <iostream>
using namespace std;

class Animal {
    protected:
        int id;
    public:
        Animal() {
            this->set_ID(0);
            cout << "Animal CLASS default constructor executed..." << endl;
        }
        Animal(int id) {
            this->set_ID(id);
            cout << "Animal CLASS parameterized constructor executed..." << endl;
        }
        ~Animal() {
            cout << "Animal CLASS destructor executed..." << endl;
        }
        void set_ID(int id) {
            this->id = id;
        }
        int get_ID() {
            return this->id;
        }
        void tell_about_self() {
            cout << "CLASS ANIMAL." << endl;
        }
        void Speak() {
            cout << "I am animal i can't speak." << endl;
        }
};

class Reptile : public Animal {
    public:
        Reptile() {
            this->set_ID(1);
            cout << "Reptile CLASS default constructor executed..." << endl;
        }
        Reptile(int id) : Animal(id) 
        {
            cout << "Reptile CLASS parameterized constructor executed..." << endl;
        } 
        ~Reptile() {
            cout << "Reptile CLASS destructor executed..." << endl;
        }
        void tell_about_self() {
            cout << "CLASS REPTILE." << endl;
        }
        void Speak() {
            this->Animal :: Speak();
            cout << "Family of Reptile's." << endl;
        }
};

class Bird : public Animal {
    public:
        Bird() {
            this->set_ID(2);
        }
        Bird(int id) : Animal(id) {
            cout << "Bird CLASS parameterized constructor executed..." << endl;
        } 
        ~Bird() {
            cout << "Bird CLASS destructor executed..." << endl;
        }
        void tell_about_self() {
            cout << "CLASS BIRD." << endl;
        }
        void Speak() {
            this->Animal :: Speak();
            cout << "Family of Bird's." << endl;
        }
};

class Mamal : public Animal {
    public:
        Mamal() {
            this->set_ID(3);
        }
        Mamal(int id) : Animal(id) {
            cout << "Bird CLASS parameterized constructor executed..." << endl;
        }
        ~Mamal() {
            cout << "Mamal CLASS destructor executed..." << endl;
        }
        void tell_about_self() {
            cout << "CLASS MAMAL." << endl;
        }
        void Speak() {
            this->Animal :: Speak();
            cout << "Family of Mamal's." << endl;
        }
};

class Snake : public Reptile {
    public:
        int get_family(){
            return this->get_ID();
        }
        void tell_about_self() {
            cout << "CLASS SNAkE." << endl;
        }
        void Speak() {
            this->Reptile :: Speak();
            cout << "shhhh...." << endl;
        }
};

class Parrot : public Bird {
    public:
        int get_family() {
            return this->get_ID();
        }
        void tell_about_self() {
            cout << "CLASS PARROT." << endl;
        }
        void Speak() {
            this->Bird:: Speak();
            cout << "Trrrr....." << endl;
        }
};

class Horse : public Mamal {
    public:
        int get_family() {
            return this->get_ID();
        }
        void tell_about_self() {
            cout << "CLASS MAMAL." << endl;
        }
        void Speak() {
            this->Mamal :: Speak();
            cout << "Hurrr...." << endl;
        }
};



int main() {
    
    Horse obj;
    obj.Speak();
    obj.get_family();
    obj.tell_about_self();
    return 0;
}