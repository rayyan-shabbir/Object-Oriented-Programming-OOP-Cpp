
#include "iostream"
#include "fstream"

using namespace std;

class Grade
{
	int id;
	float cgpa;

public:
	Grade(int id = 0, float cgpa = 0)		//constructor
	{
		this->id = id;
		this->cgpa = cgpa;
	}

	void print()							//display the data of Grade
	{
		cout << id << "\t" << cgpa << endl;
	}
};

int main(void)
{
	//open or create a binary file in output (writing) mode
	ofstream outf("test.txt", ios::binary);
	
	if (!outf)		//checking file is opened/created
	{
		cout << "File Error!" << endl;
		exit(0);
	}

	//objects of Grade class
	Grade o1(1, 1.1f);
	Grade o2(2, 2.2f);
	Grade o3(3, 3.3f);

	//writing three object in file, one-by-one
	outf.write(reinterpret_cast<char*>(&o1), sizeof(Grade));	
	outf.write(reinterpret_cast<char*>(&o2), sizeof(Grade));
	outf.write(reinterpret_cast<char*>(&o3), sizeof(Grade));
	
	outf.close();	//closing the file


	/*Reading from file*/

	//open a binary file in input (reading) mode
	ifstream inf("test.txt", ios::binary);

	//object of Grade to hold data read from file one-by-one
	Grade g;

	inf.read(reinterpret_cast<char*>(&g), sizeof(Grade));	//reading a record from file
	while (!inf.eof())			//keep iterating until EOF occurs
	{
		g.print();				//print the info of object read from file

		inf.read(reinterpret_cast<char*>(&g), sizeof(Grade));	//read the next record
	}
	
	inf.close();	//closing the file		

	return 0;
}