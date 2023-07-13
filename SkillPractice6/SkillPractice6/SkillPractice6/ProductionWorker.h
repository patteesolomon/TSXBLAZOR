#pragma once

#include <string>
#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee
{
private:
	int shift;	// the worker's shift
	double payRate;	// the worker's hourly pay rate

public:
	// default constructor
	ProductionWorker() : Employee()
	{
		shift = 0;
		payRate = 0.0;

	}
	// constructor (the hard one)
	ProductionWorker(string aName, string aNumber, string aDate,
		int aShift, double aPayRate) :Employee(aName, aNumber, aDate)
	{
		shift = aShift; payRate = aPayRate;
	}

	// mutator (also called a setter)
	void setShift(int s)
	{
		shift = s;
	}

	void setPayRate(double r)
	{
		payRate = r;
	}

	// accessor (also called a getter)
	int getShiftNumber() const
	{
		return shift;
	}

	string getShiftName() const
	{
		if (shift == 1)
			return "Day";
		else if (shift == 2)
			return "Night";
		else
			return "invalid";
	}

	double getPayRate() const
	{
		return payRate;
	}


};

