#pragma once
#include <string>
#include "TeamLeader.h"
#include "ProductionWorker.h"
class TeamLeader : public ProductionWorker
{

private:
	double mb; // monthly bonus
	int minHours; // Required Minimunm hours for of training a year 
	int hours;

public: 

	// teamleader constructor
	TeamLeader() : ProductionWorker()
	{
		this->minHours = 0;
		this->mb = 0.0;
		this->hours;
	}

	// passing info
	TeamLeader(string aName, string aNumber, string aDate,
		int aShift, double aPayRate , double bonus, int hoursOfT, int minH) :ProductionWorker(aName, aNumber, aDate,
			 aShift, aPayRate)
	{
		mb = bonus;
		minHours = minH;
		hours = hoursOfT;
	}

	// mutators
	void setBonus(double m)
	{
		mb = m;
	}

	void setMinHours(int m)
	{
		minHours = m;
	}

	void setHours(int t)
	{
		hours = t;
	}


	// accessors
	double getBonus() const
	{
		return mb;
	}

	int getMinHours() const
	{
		return minHours;
	}


	int gethours()
	{
		return hours;
	}
};