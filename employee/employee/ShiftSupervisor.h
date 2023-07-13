#pragma once
#include <string>
#include "Employee.h"

using namespace std;

class ShiftSupervisor : public Employee
{
private:
	double salary;
	double bonus;

public:
	// default constructor
	ShiftSupervisor() : Employee()
	{
		salary = 0.0; bonus = 0.0;

	}
	// the "fun" constructor
	ShiftSupervisor(string aName, string aNumber, string aDate,
		double aSalary, double aBonus): Employee(aName, aNumber, aDate)
	{
		salary = aSalary; bonus = aBonus;
	}
	
	//mutator 
	void setSalary(double s)
	{
		salary = s;
	}

	void setBonus(double b)
	{
		bonus = b;
	}

	// accessor
	double getSalary() const
	{
		return salary;
	}

	double getBonus() const
	{
		return bonus;
	}


};

