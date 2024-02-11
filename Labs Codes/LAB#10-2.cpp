#include <iostream>
using namespace std;

class Animal {
    protected:
        int id;
    public:
        Animal() {
            this->setId(0);
            cout << "Animal's Deafult Constructor" << endl;
        }

        Animal(int id) {
            this->setId(id);
            cout << "Animal's Parametrize Constructor" << endl;
        }

        ~Animal() {
             cout << "Animal's Destructor" << endl;
        }

        void setId(int id) {
            this->id = id;
        }
        int getId() {
            return this->id;
        }

        void tellAboutSelf() {
            cout << "Class Animal" << endl;
        }

        void Speak() {
            cout << "I am Animal, I can't Speak..." << endl;
        }

};

class Reptile : public Animal {
    public:
        Reptile() {
            this->setId(1);
            cout << "Reptile's Deafult Constructor" << endl;
        }
        Reptile(int id_R, int id_A) : Animal(id_A)
        {
            this->setId(id_R);
            cout << "Reptile's Parametrize Constructor" << endl;
        }
        ~Reptile() {
            cout << "Reptile's Destructor" << endl;
        }

        void tellAboutSelf() {
            cout << "Class Reptile, Belongs to Animal Class" << endl;
        }

        void Speak() {
            this->Animal :: Speak();
            cout << "Family of Reptiles..." << endl;
        }
};

class Bird : public Animal {
    public:
        Bird() {
            this->setId(2);
            cout << "Bird's Deafult Constructor" << endl;
        }
        Bird(int id_B, int id_A) : Animal(id_A)
        {
            this->setId(id_B);
            cout << "Bird's Parametrize Constructor" << endl;
        }
        ~Bird() {
            cout << "Bird's Destructor" << endl;
        }

        void tellAboutSelf() {
            cout << "Class Bird, Belongs to Animal Class" << endl;
        }

        void Speak() {
            this->Animal :: Speak();
            cout << "Family of Birds..." << endl;
        }
};

class Mammal : public Animal {
    public:
        Mammal() {
            this->setId(2);
            cout << "Mammal's Deafult Constructor" << endl;
        }
        Mammal(int id_M, int id_A) : Animal(id_A) 
        {
            this->setId(id_M);
            cout << "Mammal's Parametrize Constructor" << endl;
        }
        ~Mammal() {
            cout << "Mammal's Destructor" << endl;
        }

        void tellAboutSelf() {
            cout << "Class Mammal, Belongs to Animal Class" << endl;
        }

        void Speak() {
            this->Animal :: Speak();
            cout << "Family of Mammals..." << endl;
        }
};

class Frog : public Reptile {
    public:
        ~Frog() {
            cout << "Frog's Destructor" << endl;
        }

        int getFamily() {
            return this->id;
        }

        void tellAboutSelf() {
            cout << "Class Frog, Belongs to Reptile Class" << endl;
        }

        void Speak() {
            this->Reptile :: Speak();
            cout << "Tur Tur Tur..." << endl;
        }
};

class Sparrow : public Bird {
    public:
        ~Sparrow() {
            cout << "Sparrow's Destructor" << endl;
        }

        int getFamily() {
            return this->id;
        }

        void tellAboutSelf() {
            cout << "Class Sparrow, Belongs to Bird Class" << endl;
        }

        void Speak() {
            this->Bird :: Speak();
            cout << "Cheen Cheen Chenn..." << endl;
        }
};

class Cow: public Mammal {
    public:
        ~Cow() {
            cout << "Cow's Destructor" << endl;
        }

        int getFamily() {
            return this->id;
        }

        void tellAboutSelf() {
            cout << "Class Cow, Belongs to Mammal Class" << endl;
        }

        void Speak() {
            this->Mammal :: Speak();
            cout << "Ghaaan..." << endl;
        }
};

int main() {
    Animal ob1;
    cout << "***Calling Animal's Class***" << endl;
    ob1.tellAboutSelf();
    ob1.Speak();

    cout << endl << "***" << endl;

    Reptile ob2;
    cout << "***Calling Reptile's Class***" << endl;
    ob2.tellAboutSelf();
    ob2.Speak();

    cout << endl << "***" << endl;

    Bird ob3;
    cout << "***Calling Bird's Class***" << endl;
    ob3.tellAboutSelf();
    ob3.Speak();

    cout << endl << "***" << endl;

    Mammal ob4;
    cout << "***Calling Mammal's Class***" << endl;
    ob4.tellAboutSelf();
    ob4.Speak();

    cout << endl << "***" << endl;

    Frog ob5;
    cout << "***Calling Frog's Class***" << endl;
    ob5.tellAboutSelf();
    ob5.Speak();
    ob5.getFamily();

    cout << endl << "***" << endl;

    Sparrow ob6;
    cout << "***Calling Sparrow's Class***" << endl;
    ob6.tellAboutSelf();
    ob6.Speak();
    ob6.getFamily();

    cout << endl << "***" << endl;

    Cow ob7;
    cout << "***Calling Cow's Class***" << endl;
    ob7.tellAboutSelf();
    ob7.Speak();
    ob7.getFamily();

    cout << endl << "***" << endl;


    return 0;
}