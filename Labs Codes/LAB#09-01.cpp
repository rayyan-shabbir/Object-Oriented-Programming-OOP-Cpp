#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches& right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches& right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches& right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches& right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches& right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches& right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches& right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream& out, const FeetInches& obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream& in, FeetInches& obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

//Class RoomDimension
class RoomDimension {
    FeetInches length;
    FeetInches width;

    public:
        //Constructor
        RoomDimension(FeetInches l = 0, FeetInches w = 0) {
            setLength(l);
            setWidth(w);
        }

        //Mutators
        void setLength(FeetInches l) {
            length.setFeet(l.getFeet());
            length.setInches(l.getInches());
        }

        void setWidth(FeetInches w) {
            width.setFeet(w.getFeet());
            width.setInches(w.getInches());
        }

        //Accessors
        FeetInches getLength() {
            return length;
        }
        FeetInches getWidth() {
            return width;
        }

        //Member Function for Area
        FeetInches getArea()
        {
            FeetInches area = (length * width);

            return area;
        }

        //Member Function Display
        void display()  {
            cout << "Length: " << length;
			cout << "Width: " << width << endl;
        }

};

//Class RoomCarpet
class RoomCarpet {
    RoomDimension roomSize;
    float costPerSquareFoot;

    public:
        //Constructor
        RoomCarpet(RoomDimension rSize, float cost) {
            set_Room_Size(rSize);
            set_Cost_Per_Square_Foot(cost);
        }

        //Mutators 
        void set_Room_Size(RoomDimension rSize) {
            roomSize.setLength(rSize.getLength());
            roomSize.setWidth(rSize.getWidth());
        }

        void set_Cost_Per_Square_Foot(float cost) {
            this->costPerSquareFoot = cost;
        }

        //Accessors
        RoomDimension get_Room_Size() {
            return roomSize;
        }
        float get_Cost_Per_Square_Foot() {
            return costPerSquareFoot;
        }

        //Total Cost Member Function
        float total_Cost() {
            float totalCost = (costPerSquareFoot * (roomSize.getArea()).getFeet());

            return totalCost;
        }

        //Member Function Display
        void display()  {
            cout << "Room Size: " << roomSize.getArea() << " Cost per square foot: " << costPerSquareFoot << endl;
        }

};

int main() {
	//*** 
	// .....CLASS # 01.....
    // FeetInches len, wid;
	// cout << "***Enter Dimensions for length*** " << endl;
    // cin >> len;
	// cout << "***Enter Dimensions for width*** " << endl;
    // cin >> wid;

    // RoomDimension obj2(len, wid);
    // cout << "***Get Area*** \n" << obj2.getArea();
    // cout << "***Get Length*** \n" <<obj2.getLength();
    // cout << "***Get Width*** \n" << obj2.getWidth();

	//cout << "***Displaying length and width***\n"
    //obj2.display();
    //***

	//***
	//  ......CLASS # 02......
	// float cost_Per_Sq_Ft = 0;


    // cout << "Enter Cost per Sq, Feet: ";
    // cin >> cost_Per_Sq_Ft;

    // RoomCarpet obj3(obj2, cost_Per_Sq_Ft);

	//cout << "***RoomCarper Object***\n" << endl;
    // obj3.display();
	//***

    //***
	//.....MAIN.....
	float price = 0;
    FeetInches length, width;

	cout << "***Enter Dimensions for length*** " << endl;
	cin >> length;
	cout << "***Enter Dimensions for width*** " << endl;
	cin >> width;

	cout << "***Enter Price Per Square Foot*** :";
	cin >> price;

	cout << "***Dimensions of Room are***" << endl;
	cout << length;
	cout << width;

	RoomDimension roomDim(length, width);
	cout << endl;
	// roomDim.display();

	RoomCarpet roomSize(roomDim, price);

	cout << "Cost per Square foot is: " << roomSize.get_Cost_Per_Square_Foot() << endl;

	cout << "***Total Cost is*** = " << roomSize.total_Cost() << endl;
    //***
    return 0;
}