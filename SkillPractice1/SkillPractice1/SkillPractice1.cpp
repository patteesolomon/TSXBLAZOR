// SkillPractice1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/******************************
   Name: Solomon Pattee
   Date: 8/28/2019
   FileName: SkillPractice1.cpp
   Description: Inventory Management for the Bins
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Global variables
const int NUM_OF_BINS = 10;

// Bin struct. Name first then number second.
struct BIN
{
	string partName;
	int num;
};

// Function declarations

int getChoice(BIN c[]);

int addParts(BIN add[], int userChoice);

int removeParts(BIN rem[], int userChoice);

void binChanger(BIN c[], int userChoice);

int main()
{
	// Bin parts
	BIN Bins[NUM_OF_BINS] = {
	{"	Valve		\t", 10},
	{"	Bearing		\t", 5},
	{"	Bushing		\t", 15},
	{"	Coupling	\t", 21},
	{"	Flange		\t", 7},
	{"	Gear		\t", 5},
	{"	Gear Housing	\t", 5},
	{"	Vacuum Gripper	\t", 25},
	{"	Cable		\t", 18},
	{"	Rod		\t", 12}
	};
	
	//Main Menu
	int userChoice{};

	userChoice = getChoice(Bins);

	while (userChoice != 11)
	{
		
		// displaying menu binChanger
		binChanger(Bins, userChoice);

		// all the bins
		userChoice = getChoice(Bins);

	};

	// Exiting the Program..
	system("PAUSE");

	return 0;
}

int getChoice(BIN c[])
{
	// display the bin list
	cout << "Part Description\t\t Number of Parts in the Bin" << endl;

	int userChoice;
	// user input
	cout << endl;

	// Bin list display
	for (int x = 0; x < NUM_OF_BINS; x++)
	{
		cout << (x + 1) << ")" << c[x].partName << "\t";
		cout << c[x].num << endl;
	}

	// display the last menu item, which is to leave Bin Warehouse
	cout << (NUM_OF_BINS + 1)
		<< ") \tLeave Warehouse\n\n";

	// user picks the bin and type
	cout << "Select the part: ";
	cin >> userChoice;

	//Validate choice2
	while (userChoice < 1 || userChoice > 11)
	{
		cout << "invalid option..." << endl;
		cout << "Choose part: ";
		cin >> userChoice;
	}

	// If you wana leave this hell. Wouldn't blame ya.
	if (userChoice == 11)
	{ 
		cout << "Goodbye!" << endl;
		return userChoice;
	}

	return userChoice -1;
}

int addParts(BIN add[], int userChoice)
{
	// amount integer
	int amount = 0;

	// ask the User how many to add
	cout << "how many to add?" << endl;
	cin >> amount;

	add[userChoice].num += amount;

	return add[userChoice].num -1;
}

int removeParts(BIN rem[], int userChoice)
{
	// amount integer
	int amount;

	// ask the User how many to add
	cout << "how many to remove?" << endl;
	cin >> amount;

	rem[userChoice].num -= amount;

	return rem[userChoice].num - 1;
}

void binChanger(BIN c[], int userChoice)
{
	// choice to add or remove
	char choice2;

	// user chooses once the bin is seleced they may add or remove
	cout << "(1) Add \n or \n (2) Remove the part(s)? " << endl;

	cin >> choice2;

	if (choice2 == '1')
	{
		// adding said part
		addParts(c, userChoice);
	}
	else if (choice2 == '2')
	{
		// removing said part 
		removeParts(c, userChoice);
	}
	else
	{
		// Invalid option
		cout << "invalid option..." << endl;
		cin >> choice2;
	};

	//Validate choice2
	while (choice2 < '1' || choice2 > '2')
	{
		cout << "invalid option..." << endl;
		cout << "Choose to add (1) or remove (2): ";
		cin >> choice2;
	}

	//Validation

	// for adding
	if (c[userChoice].num > 30)
	{
		//too many items requirement...
		cout << "Maximum capacity!" << endl;

		// maxium value 30
		c[userChoice].num = 30;
	}

	// for removing
	if (c[userChoice].num < 0)
	{
		//too little items requirement...
		cout << "That's not enough!" << endl;

		// minimum value 0
		c[userChoice].num = 0;
	}

	system("CLS");
}