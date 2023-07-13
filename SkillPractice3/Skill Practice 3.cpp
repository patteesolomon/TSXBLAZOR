/******************************
   Name SAO NGUYEN
   Date 9/16/19
   File Name template.cpp
   Description Skill Practice Assignment 3
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

// Global variables

// declaration for structure
struct Division
{
	char divName[12];	// division name
	int quarter;	// quarter number
	double sales;	// quarterly sales
};
// Function declarations

int main()
{
	// Variables declaration and initialization
	Division branches[16];							
	double divisionSalesTotal[4] = { 0,0,0,0 };	
	double corpSalesTotal = 0;					

	// Access the file
	fstream file;
	file.open("corp.dat", ios::in | ios::binary);
	

	// Test File 
	if (!file)
	{
		cout << "Error Opening File. Program Aborting.\n";
		return 0;
	}

	// Read the file into each struct
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*> (&branches), sizeof(branches));

		// Close the File
		file.close();
	}

	// Total yearly sales for East Division
	for (int e = 0; e < 4; e++)
	{
		divisionSalesTotal[0] += branches[e].sales;
	}
	cout << "The Total Sale for the Division in the " << branches[0].divName << " is: "
		<< divisionSalesTotal[0] << endl;

	// Total yearly sales for West Division
	for (int w = 4; w < 8; w++)
	{
		divisionSalesTotal[1] += branches[w].sales;
	}
	cout << "The Total Sale for the Division in the " << branches[4].divName << " is: "
		<< divisionSalesTotal[1] << endl;;

	// Total yearly sales for North Division
	for (int n = 8; n < 12; n++)
	{
		divisionSalesTotal[2] += branches[n].sales;
	}
	cout << "The Total Sale for the Division in the " << branches[8].divName << " is: "
		<< divisionSalesTotal[2] << endl;

	// Total yearly sales for South Division
	for (int s = 12; s < 16; s++)
	{
		divisionSalesTotal[3] += branches[s].sales;
	}
	cout << "The Total Sale for the Division in the " << branches[12].divName << " is: "
		<< divisionSalesTotal[3] << endl;


	// Total yearly corporate sales
	for (int t = 0; t < 4; t++)
	{
		corpSalesTotal += divisionSalesTotal[t];
	}
	cout << "===================================================" << endl;
	cout << "The Total Corporate Sales is: " << corpSalesTotal << endl;


	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent.  It will only work on Windows
	system("PAUSE");

	/*
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
}
