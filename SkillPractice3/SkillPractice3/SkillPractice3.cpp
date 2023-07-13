/******************************
   Solomon Pattee
   9/16/2019
   SkillPractice3.cpp
   A program that reads in 
   a file and outputs figures
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Global variables

const int MAX = 3;

struct Division
{
	char divName[12]; // 12 bytes
	int quarter; // 4 byts
	double sales; // 8 bytes
};

struct Data
{
	int salesData[16];
};


// Function declarations
void average(double east[MAX], double west[MAX], double north[MAX], double south[MAX]);

int main()
{
	// Your code goes here
	// file stream object
	fstream file;
	
	// open the file
	file.open("corp.dat", ios::in | ios::out | ios::binary);
		// if file is not there or empty
		/*if (file.eof() <= 0)
		{
			cout << "File cannot be found..." << endl;
		}*/

	// create the division structure variables for each division
	Division east, west, north, south; // each has 4 quarters of number data

	//Data so;

	// loop counter for each quarter
	int qtr;

	// assign the division names to the division structure var
	strcpy_s(east.divName, "East");
	strcpy_s(west.divName, "West");
	strcpy_s(north.divName, "North");
	strcpy_s(south.divName, "South");

	// get sales data for the east division
	cout << "Enter the quarterly sales for the East Division:\n";
	double quarterET[4] = { 0 };
	for (qtr = 1; qtr <= 4; qtr++)
	{
		east.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> east.sales;
		file.write(reinterpret_cast<char*>(&east), sizeof(east));
		// le four ints for western qq

			if (east.quarter == 0)
			{
				quarterET[0] += east.sales;
			}
			if (west.quarter == 1)
			{
				quarterET[1] += east.sales;
			}
			if (west.quarter == 2)
			{
				quarterET[2] += east.sales;
			}
			if (west.quarter == 3)
			{
				quarterET[3] += east.sales;
			}
		
	}
//*/ 
	 //get sales data for the west division
	double quarterWT[4] = { 0 };
	cout << "Enter the quarterly sales for the West Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		west.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> west.sales;
		file.write(reinterpret_cast<char*>(&west), sizeof(west));
		// le four ints for western qq

			if (west.quarter == 0)
			{
				quarterWT[0] += west.sales;
			}
			if (west.quarter == 1)
			{
				quarterWT[1] += west.sales;
			}
			if (west.quarter == 2)
			{
				quarterWT[2] += west.sales;
			}
			if (west.quarter == 3)
			{
				quarterWT[3] += west.sales;
			}
		
	}
	
//
//	get sales data for the north division
	double quarterNT[4] = { 0 };
	cout << "Enter the quarterly sales for the North Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		north.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> north.sales;
		file.write(reinterpret_cast<char*>(&north), sizeof(north));
		// le four ints for western qq
	
			if (north.quarter == 0)
			{
				quarterNT[0] += north.sales;
			}
			if (west.quarter == 1)
			{
				quarterNT[1] += north.sales;
			}
			if (west.quarter == 2)
			{
				quarterNT[2] += north.sales;
			}
			if (west.quarter == 3)
			{
				quarterNT[3] += north.sales;
			}
		
	}
//
//	1000 each quarter for each division is what I used
//	south quarter
	double quarterST[4] = { 0 };

	cout << "Enter the quarterly sales for the South Division:\n";
	for (qtr = 1; qtr <= 4; qtr++)
	{
		south.quarter = qtr;
		cout << "\tQuarter " << qtr << ": ";
		cin >> south.sales;
		file.write(reinterpret_cast<char*>(&south), sizeof(south));
		// le four ints for western qq
		if (south.quarter == 1)
		{
			quarterST[0] += south.sales;
		}
		if (south.quarter == 2)
		{
			quarterST[1] += south.sales;
		}
		if (south.quarter == 3)
		{
			quarterST[2] += south.sales;
		}
		if (south.quarter == 4)
		{
			quarterST[3] += south.sales;
		}
	} 

	//pulling the data 

	// ints

	double newDataE[] = { quarterET[3] };
	double newDataN[] = { quarterNT[3] };
	double newDataS[] = { quarterST[3] };
	double newDataW[] = { quarterWT[3] };

	// west data
	file.read(reinterpret_cast<char*>(&west), sizeof(west));
	newDataW[] += west.sales;

	// north data
	file.read(reinterpret_cast<char*>(&north), sizeof(north));
	newDataS[] += south.sales;
	// south data
		file.read(reinterpret_cast<char*>(&south), sizeof(south));
	newDataN[] += north.sales;

	// east data
	file.read(reinterpret_cast<char*>(&east), sizeof(east));
	newDataE[] += east.sales;

//*/
// get sales data for the east division
	cout << "The Average quarterly sales for the division are: ";

	// Average function call
	/*average(east, west, north, south);*/
	average(newDataE, newDataW, newDataN, newDataS);

	// close the file
	file.close();

	// Make sure we place the end message on a new line
	cout << endl;

	// The following is system dependent. It will only work on Windows
    system("PAUSE");

	/*
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
	//1000
}

void average(double east[MAX], double west[MAX], double north[MAX], double south[MAX])
{
	//variable numbers 
	int eastS = 0;
	int westS = 0;
	int northS = 0; 
	int southS = 0;
	int average = 0;
	int total = 0;
	//

	total = eastS + westS + northS + southS;

	average += (total) / 4;

	// average calculation
	cout << average;
}