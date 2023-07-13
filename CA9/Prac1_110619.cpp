/******************************
   Name Jeremy Laney
   Date 11/06/2019
   File Name Prac1_110619.cpp
   Description pg 1026 #1 exceptions and templates
********************************/

// Headers
//#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables
const int NUM_MONTHS = 12;


// Function declarations

// declaration of date class
class Date
{
private:
	int month;		// month to told
	int day;		// to hold the day
	int year;		// to hold the year

	// an array of strings to hold the names of the month
	string names[NUM_MONTHS];

	// priovate member function to assign the month namesto the names of the array
	void setNames();

public:
	//constructors
	Date();
	Date(int, int, int);

	// mutators
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	// fuinctions to print the date 
	void showDate1();
	void showDate2();
	void showDate3();

	// exception classes
	class InvalidDay {};
	class InvalidMonth {};
};

// default constructor
Date::Date()
{
	setNames();
}

// overloaded constructor
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
	setNames();
}

// private member function setNames

void Date::setNames()
{
	names[0] = "January";
	names[1] = "February"; 
	names[2] = "March";
	names[3] = "April";
	names[4] = "May";
	names[5] = "June";
	names[6] = "July";
	names[7] = "August";
	names[8] = "September";
	names[9] = "October";
	names[10] = "November";
	names[11] = "December";	
}

// member function setMonth
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
	else
		throw InvalidMonth();
}

// member function setDay
void Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
		day = d;
	else
		throw InvalidDay();
}

// member function setYear
void Date::setYear(int y)
{
	year = y;
}

void Date::showDate1() // i changed the name you had a typo
{
	cout << month << "/" << day << "/" << year << endl;
}

void Date::showDate2()
{
	cout << names[month - 1] << " "  << day << "," << year << endl;
}

void Date::showDate3()
{
	cout << day << " " << names[month - 1] << " " << year << endl;
}


int main()
{
	//	Your code goes here
	// create a datye objecy and init it using the contructor overlaoder
	Date today(12, 25, 2012);

	// show date in form #1
	today.showDate1();
	// should show 12/25/2012

	for (int month = 10; month <= 13; month++)
	{
		for (int day = 28; day <= 32; day++)
		{
			try
			{
				// store a new month
				today.setMonth(month);

				// sotore a new day
				today.setDay(day);

				// display the date
				today.showDate1();
			}
			catch (Date::InvalidDay)
			{
				// invalid day was given
				cout << "\nError! Day is out of range.\n";
			}
			catch (Date::InvalidMonth)
			{
				// Invalid month was given
				cout << "\nError! Month is out of range.\n";
			}
		}
	}

	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent.  It will only work on Windows
	system("PAUSE");

	/*
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
}