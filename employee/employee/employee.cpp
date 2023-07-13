/******************************
   Sol	
   10/28/2019
   Employee.cpp
   Description
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"

using namespace std;

// Global variables

// Function declarations

void displayInfo(ProductionWorker);
void displayInfo2(ShiftSupervisor);

int main()
{
	//	Your code goes here
	ProductionWorker pw("John Jones", "123", "10/12/2010", 2, 18.00);
	displayInfo(pw);

	ShiftSupervisor supervisor("Kim Jones", "321", "12/15/2012", 
		75000.0, 15000.0);
	displayInfo2(supervisor);
	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent. It will only work on Windows
	system("PAUSE");

	/*
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
}

void displayInfo(ProductionWorker e)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: " << e.getName() << endl;
	cout << "Employee number: " << e.getNumber() << endl;
	cout << "Hire Date : " << e.getHireDate() << endl;
	cout << "Shift: " << e.getShiftName() << endl;
	cout << "PayRate: " << e.getPayRate() << endl;
}

void displayInfo2(ShiftSupervisor e)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: " << e.getName() << endl;
	cout << "Employee number: " << e.getNumber() << endl;
	cout << "Hire Date : " << e.getHireDate() << endl;
	cout << "Annual Salary: $ " << e.getSalary() << endl;
	cout << "Annual production Bonus: $ " << e.getBonus() << endl;

}