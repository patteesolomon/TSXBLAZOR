// Sao Nguyen
//unimplementation file for Pharmacy class
#include <iostream>
#include <cstdlib>
#include <string>
#include "Pharmacy.h"

using namespace std;

// constructor don't accept arguement
Pharmacy::Pharmacy()
{
	
}


// accessor or getter
// for medication 1
double Pharmacy::getMedication1()
{
	return oxyContin;
}

// for medication 2
double Pharmacy::getMedication2()
{
	return morphine;
}

// for medication 3
double Pharmacy::getMedication3()
{
	return aspirin;
}

// for medication 4
double Pharmacy::getMedication4()
{
	return memoryMedication;
}

// for medication 5
double Pharmacy::getMedication5()
{
	return glasses;
}

// for medication 6
double Pharmacy::getMedication6()
{
	return no;
}

// member function
double Pharmacy::pharmacyCharge(int choice)
{
	switch (choice)
	{
	case 1: // for medication 1
		return getMedication1();
		break;
	case 2: // for medication 2
		return getMedication2();
		break;
	case 3:    // for medication 3
		return getMedication3();
		break;
	case 4:    // for medication 4
		return getMedication4();
		break;
	case 5:    // for medication 5
		return getMedication5();
		break;
	case 6:    // for medication 6
		return getMedication6();
		break;
	default:
		return 0;
		break;
	}
}
