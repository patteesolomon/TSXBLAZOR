// Christina Camacho
//unimplementation file for PatientAccount class
#include <iostream>
#include <cstdlib>
#include <string>
#include "PatientAccount.h"
using namespace std;

// constructor
PatientAccount::PatientAccount()
{ //intializing variables
	dailyRate = 100.00;
	surgeryCharge = 0.00;
	pharmacyCharge = 0.00;
	dailyCharge = 0.00;
	totalCharges = 0.00;
	numDays = 0;
}

// mutator and setting the variables
void PatientAccount::setNumDays(int nd)
{
	numDays = nd;
}
void PatientAccount::setSurgeryCharge(double sc)
{
	surgeryCharge = sc;
}
void PatientAccount::setPharmacyCharge(double pc)
{
	pharmacyCharge = pc;
}
void PatientAccount::setDailyCharge()
{
	dailyCharge = (dailyRate * numDays);
}
void PatientAccount::setTotalCharges(double sc, double pc, double dc)
{
	totalCharges = (sc + pc + dc);
}

// accessor or getters
int PatientAccount::getNumDays()
{
	return numDays;
}
double PatientAccount::getSurgeryCharge()
{
	return surgeryCharge;
}
double PatientAccount::getPharmacyCharge()
{
	return pharmacyCharge;
}
double PatientAccount::getDailyCharge()
{
	return dailyCharge;
}
double PatientAccount::getTotalCharges()
{
	return totalCharges;
}
