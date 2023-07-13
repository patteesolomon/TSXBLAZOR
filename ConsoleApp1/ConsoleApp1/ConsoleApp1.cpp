/*
// Name: Solomon Pattee
// Date: created as of 8/26/2019
// FileName: ConsoleApp1.cpp
// Description: Page 662 #13 Drink Machine
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

//global variables
const int NUM_DRINKS = 5;

//declaration for the drink structure

struct Drink
{
	string name;
	double price;
	int num;
};

// Function prototypes
int getChoice(Drink[]);
void transaction(Drink[], int, double&);

int main()
{
	// Menu
	int choice;

	// drink machine earnings
	double earnings = 0;

	// array of drinks in the machine
	Drink machine[NUM_DRINKS] = {
		{" Cola	", 0.75, 20},
		{" Root Beer", 0.75, 20},
		{" Lemon-Lime", 0.75, 20},
		{" Grape Soda", 0.80, 20},
		{" Cream Soda", 0.80, 20}
	};

	// set the floating-point output formatting
	cout << fixed << showpoint << setprecision(2);

	// display the menu and process the user choice 
	// takes in the array of drinks
	choice = getChoice(machine);

	// process the transaction
	while (choice != 5)
	{
		// Transaction has a function call (getChoice) within it as a parameter
		transaction(machine, choice, earnings);
		// get the next choice
		choice = getChoice(machine);
	}

	// display the machine's total earnings
	cout << "Total earnings: $" << earnings << endl;

	system("PAUSE");

	return 0;
}

//function getChoice 
// this function gets the choice and returns that value -1. This adjustment
// is made because the value will be used as a subscript into the Drink
// array by the transaction function.

int getChoice(Drink m[])
{
	// the user's choice 
	int choice;
	cout << endl;
	// display a list of drinks preceded by a number
	// this will be the menu
	for (int x = 0; x < NUM_DRINKS; x++)
	{
		cout << (x + 1) << ")" << m[x].name << "\t\t";
		cout << m[x].price << endl;
	}

	// display the last menu item, which is to leave the drink machine
	cout << (NUM_DRINKS + 1)
		<< ") Leave the drink machine\n\n";

	// get the user choice 
	cout << "Chose one: ";
	cin >> choice;

	// validate the choice 
	while (choice < 1 || choice > 6)
	{
		cout << "Bad choice. Choose one: ";
		cin >> choice;
	}
	// return the choice, as a subscript into the array of drinks 
	return choice - 1;
}

// transaction function
// this processes the user's choice and updates the earnings var.

void transaction(Drink m[], int choice, double& earnings)
{
	// the amout of money tendered
	double money;

	// if the selected drink is sold out, display a message and get out
	// of the function
	if (m[choice].num <= 0)
	{
		cout << "Sorry, that selection is sold out.\n";
		return;
	}

	// get some money from the customer
	cout << "Enter an amount of money: ";
	cin >> money;

	// make sure the customer entered at least enough for the selected drink
	// and no more than $1.00
	while (money < m[choice].price || money > 1.0)
	{
		cout << "Enter at least " << m[choice].price;
		cout << " and not more than 1 dollar.\n";
		cin >> money;
	}

	// process the selection and give back any change that is due
	if (money >= m[choice].price)
	{
		//dispence the drink 
		cout << "\nThump, thump, thump, dung!\n"
			<< "Enjoy your beverage!\n\n";

		cout << "Change calculated: "
			<< (money - m[choice].price) << endl;

		// if change is due, give to user
		if ((money - m[choice].price) > 0)
			cout << "Your change, " << (money - m[choice].price)
			<< " has just dropped into the change dispenser. \n\n";

		// update 
		earnings += m[choice].price;

		// decrease the number of cans of the selected drink
		m[choice].num--;

		// display the number of the cans this drink currently has in the machine
		cout << "There are " << m[choice].num << " drinks of that type left\n";
	}
}