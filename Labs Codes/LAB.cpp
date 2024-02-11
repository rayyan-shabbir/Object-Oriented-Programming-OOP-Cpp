#include "FeetInches.h"

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
            cout << "Length: " << length << " Width: " << width << endl;
        }

};

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
        void set_Room_Size(RoomDimension rS) {
            roomSize.setLength(rS.getLength());
            roomSize.setWidth(rS.getWidth());
        }

        void set_Cost_Per_Square_Foot(float cost) {
            costPerSquareFoot = cost;
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
	// float price;
    // FeetInches length, width;

	// cout << "***Enter Dimensions for length*** " << endl;
	// cin >> length;
	// cout << "***Enter Dimensions for width*** " << endl;
	// cin >> width;

	// cout << "***Enter Price Per Square Foot*** :";
	// cin >> price;

	// RoomDimension roomDim(length, width);

	// RoomCarpet roomSize(roomDim, price);

	// cout << "***Total Cost is*** = " << roomSize.total_Cost() << endl;
	//***
    return 0;
}