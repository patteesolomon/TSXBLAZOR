#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ship
{
private:
	string name;	// holds ship name
	string year;	// holds year ship was built

public:
	// default constructor
	Ship()
	{
		name = ""; year = "";
	}
	//construtor with variable parameters
	Ship(string aName, string aYear)
	{
		name = aName; year = aYear;
	}

	// mutators
	void setName(string n)
	{
		name = n;
	}
	void setYear(string y)
	{
		year = y;
	}
	// accessors
	string getName() const
	{
		return name;
	}
	string getYear() const
	{
		return year;
	}

	// member function
	virtual void print()
		//use virtual so the children can inherit
		//the function print with the same name. 
		//The children now get the Name and the
		//Max Passengers in their classes and not the Name + year.
	{
		cout << "Ship" << endl;
		cout << "	Ship Name: " << getName() << endl;
		cout << "	Ship Year: " << getYear() << endl << endl;
	}

};