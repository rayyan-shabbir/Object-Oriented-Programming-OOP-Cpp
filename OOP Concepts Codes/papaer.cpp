#include <iostream>
#include "fstream"
using namespace std;

void arrayToFile(string name, int*ar, int size)
{
	ofstream outf(name, ios::binary);

	if (!outf)
	{
		cout << "\nFile Error!\n";
		exit(0);
	}

	for (int i = 0; i < size; i++)
	{
		outf.write(reinterpret_cast<char*>(&ar[i]), sizeof(int));
	}

	outf.close();
}


void fileToArray(string name, int* ar, int size)
{
	ifstream inf(name, ios::binary);

	if (!inf)
	{
		cout << "\nFile Error!\n";
		exit(0);
	}

	for (int i = 0; i < size; i++)
	{
		inf.read(reinterpret_cast<char*>(ar[i]), sizeof(int));

		cout << ar[i] << "\t";
	}

	inf.close();
}


int main()
{
	int size = 5;
	int ar[] = { 5,6,7,8,9,25 };

	arrayToFile("fazool.txt", ar, 5);
	fileToArray("fazool.txt", ar, 5);

	return 0;
}