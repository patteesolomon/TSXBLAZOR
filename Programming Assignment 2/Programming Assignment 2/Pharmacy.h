// Sao Nguyen
#pragma once
// specification file for the Pharmacy class
#ifndef PHARMACY_H
#define PHARMACY_H

class Pharmacy
{
private:
	// variables
	double oxyContin = 100.00;
	double morphine = 200.00;
	double aspirin = 400.00;
	double memoryMedication = 500.00;
	double glasses = 600.00;
	double no = 0.00;

public:
	// constructor
	Pharmacy();

	// accessor or getter
	double getMedication1();
	double getMedication2();
	double getMedication3();
	double getMedication4();
	double getMedication5();
	double getMedication6();

	// member function
	double pharmacyCharge(int choice);
};
#endif
