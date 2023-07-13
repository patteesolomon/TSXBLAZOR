/******************************
   Solomon Pattee
   9/11/2019
   Console app 4.cpp
   Description
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

// Global variables

struct Division
{
	char divName[12];
	int quarter;
	double sales;
};

// Function declarations

int main()
{
	//	Your code goes here
	//file stream object
	fstream file("corp.dat", ios::out | ios::binary);

	// create the division structure variables for each division
	Division east, west, north, south;

	//loop counter for each quarter
	int qtr;
	// assign the division names to the division structure var
	strcpy_s(east.divName, "East");
	strcpy_s(west.divName, "West");
	strcpy_s(north.divName, "North");
	strcpy_s(south.divName, "South");

	// get sales data for the east division
	cout << "Enter the quarterly sales for the East Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		east.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> east.sales;
		file.write(reinterpret_cast<char*>(&east), sizeof(east));
	}

	// get sales data for the east division
	cout << "Enter the quarterly sales for the Wast Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		west.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> west.sales;
		file.write(reinterpret_cast<char*>(&west), sizeof(west));
	}

	// get sales data for the east division
	cout << "Enter the quarterly sales for the North Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		east.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> north.sales;
		file.write(reinterpret_cast<char*>(&north), sizeof(north));
	}


	// get sales data for the east division
	cout << "Enter the quarterly sales for the South Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		south.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> south.sales;
		file.write(reinterpret_cast<char*>(&south), sizeof(south));
	}

	// close the file
	file.close();

	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent.  It will only work on Windows
	// system("PAUSE");

	/*
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
}
