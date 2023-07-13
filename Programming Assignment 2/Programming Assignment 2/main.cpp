/******************************
   Team Name: THE TERMINATORS
   Date: 9/30/19
   File Name spc13-20.cpp
   Description Programming 2
********************************/
// Chapter 13, Programming Challenge 20: Patient Fees
#include <iostream>
#include <iomanip>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"
using namespace std;

// Function prototypes
int getSurgeryType();
int getMedicationType();

int main() // Christion Butterworth
{
	//variable declaration for everything used in program c.b
	int days;            // hold number of days stay at the hospital
	int mChoice;        //for grabbing the medication selection c.b
	int sChoice;        //for grabbing the surgery choice c.b
	double surgCost;    // hold surgery cost
	double medCost;        // hold medication cost
	double stayCost;    // hold daily rate cost

	// class variables
	Surgery surg;        //creating variable to access the surgery class c.b
	Pharmacy med;        //another variable to access medication class c.b
	PatientAccount patient;     // patient of patient account class

	// display
	cout << endl
	<< "||Welcome to a VERY NORMAL Hospital!?!||\n"
		<< "(we'll try to 'kill' (oops!) cure you (*v*) \n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	// for surgery
	sChoice = getSurgeryType();           //using variable to get the choice of user c.b
	surgCost = surg.surgeryCharge(sChoice);    //passing varibale for slection c.b
	cout << "\n";
	mChoice = getMedicationType();                //variable gets choice of medication c.b
	medCost = med.pharmacyCharge(mChoice);        //passing the variable to find selection c.b
	cout << "Please Enter Number of Days You Stayed: ";
	cin >> days;
	patient.setNumDays(days);
	patient.setDailyCharge();
	stayCost = patient.getDailyCharge();
	patient.setTotalCharges(surgCost, medCost, stayCost);
	cout << "==========================================================\n";
	cout << "Your Total Hospital Fee: $"
		<< fixed << showpoint << setprecision(2) << patient.getTotalCharges() << endl;
	cout << "*Kaching* ($v$), Thank You For Paying!!\n"
		<< "Please Come Back Again Soon (+v+) *Muahahahah* \n";
	return 0;
}

//***********************************************
// Function getSurgeryType                      *
// Displays a menu of surgery types and gets    *
// a selection from the user. The selection     *
// is returned.                                 *
//***********************************************

int getSurgeryType()    //Jeremy Laney
{
	int choice;    // variable to hold the user's choice form the menu
	//display menu for user to choose from
	cout << "-----------------------------------------------------------\n";
	cout << "Please select the surgery provided from the following list: " << endl
		<< "1. Knee Surgery        = $100.00" << endl
		<< "2. Back surgery        = $200.00" << endl
		<< "3. Heart Surgery	   = $300.00" << endl
		<< "4. Brain surgery	   = $400.00" << endl
		<< "5. Eyeball surgery     = $500.00" << endl
		<< "6. None: For Those Who Don't Want to Risk Their Life " << endl << endl
		<< "Please Select (1-6): ";
	// get user input
	cin >> choice;

	// validate user input
	while (choice < 1 || choice > 6)
	{
		cout << "Please Enter (1-6): ";
		cin >> choice;
	}
	return choice;
}

//***********************************************
// Function getMedicationType                   *
// Displays a menu of medication types and gets *
// a selection from the user. The selection     *
// is returned.                                 *
//***********************************************

int getMedicationType()    // Jeremy Laney
{
	int choice;    // variable to hold the user's choice form the menu
	// display menu for user to select from
	cout << "------------------------------------------------------------\n";
	cout << "Please select medication from the following list: " << endl
		<< "1. OxyContin			  = $100.00" << endl
		<< "2. Morphine				  = $200.00" << endl
		<< "3. Aspirin				  = $400.00" << endl
		<< "4. Memory Medication      = $500.00" << endl
		<< "5. Glasses				  = $600.00" << endl
		<< "6. None: For Those Who Don't Want to Risk Their Life" << endl << endl
		<< "Please Select (1-6): ";
	cin >> choice;
	// validate user input
	while (choice < 1 || choice > 6)
	{
		cout << "Please Enter (1-6): ";
		cin >> choice;
	}
	return choice;
}
