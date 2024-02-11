#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	// int rollNo, marks;
	// string firstName, lastName;

	// ofstream fout("Student1.txt");

	// //fout.open("Student.txt");

	// if (!fout)
	// {
	// 	cout << "Error" << endl;
	// 	exit(0);
	// }

	// while (cin >> rollNo >> firstName >> lastName >> marks )
	// {
	// 	fout << rollNo << "\t" << firstName << " " << lastName << "\t" << marks << endl;
	// }

	// fout.close();

	// ifstream fin("Student1.txt");

	// if (!fin)
	// {
	// 	cout << "Error" << endl;

	// 	exit(0);

	// }

	// cout << "Roll No.\tName      \t\tMarks" << endl;

	// cout << "----------------------------------------------------" << endl;

	// while (fin >> rollNo >> firstName >> lastName >> marks)
	// {
		 
	// 	cout << rollNo << "\t\t" << firstName << " " << lastName << "\t\t" << marks << endl;

	// }

	// fin.close();


	////-------------------Task 03 -------------------------------------------


	// ifstream fin("input.txt");

	// if (!fin)
	// {
	// 	cout << "Error " << endl;
	// 	exit(0);
	// }

	// int arr[11];
	// int a;

	// while (!fin.eof())
	// {

	// 	for (int i = 0; i < 11; i++)
	// 	{
	// 		fin >> a;
	// 		arr[i] = a;
	// 		//cout << arr[i] << " ";
	// 	}

	// 	//cout << endl;


	// 	int highestMarks = arr[1];

	// 	for (int i = 2; i < 11; i++)
	// 	{
	// 		if (highestMarks < arr[i])
	// 		{
	// 			highestMarks = arr[i];
	// 		}
	// 	}

	// 	for (int i = 0; i < 11; i++)
	// 	{
	// 		cout << arr[i] << " ";
	// 	}

	// 	cout << highestMarks;

	// 	cout << endl;

	// }
		
	// fin.close();

	////-------------------Task 04-----------------------------


	ifstream fin("input.txt");


	if (!fin)
	{
		cout << "Error" << endl;
		exit(0);
	}

	ofstream fout("output.txt");

	if (!fout)
	{
		cout << "Error" << endl;
		exit(0);
	}

	int a;

	int arr[11];

	int highestMarks ,secondHigh;;

	while (!fin.eof())
	{

		for (int i = 0; i < 11; i++)
		{
			fin >> a;
			arr[i] = a;	
		}

		highestMarks = arr[1];

		secondHigh = arr[1];

		for (int i = 2; i < 11; i++)
		{
			if (highestMarks < arr[i])
			{
				highestMarks = arr[i];
			}

		}

		for (int i = 2; i < 11; i++)
		{
			if (secondHigh < arr[i] && arr[i] != highestMarks)
			{
				secondHigh = arr[i];
			}
		}

		int rollno = arr[0];

		fout << arr[0] << " " << highestMarks << " " << secondHigh << endl;


		/*for (int i = 0; i < 11; i++)
		{
			cout << arr[i] << " ";
		}

		cout << highestMarks << " " << secondHigh << endl;*/
	}

	fin.close();
	fout.close();



	return 0;
}            