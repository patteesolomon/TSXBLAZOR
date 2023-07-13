// ch13ProgrammingChallenge1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/******************************
   Jeremy Laney
  09/25/2019   
  File Name template.cpp
  Chapter 13 programming Challenge 1
********************************/

// Headers
//#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables
// constants
const int NUM_MONTHS = 12;

// Function declarations

// declaration of date class
class Date
{
private:
	int month;	// hold month
	int day;	// hold day
	int year;	// hold year
	string names[NUM_MONTHS];	// array of strings hold names of the months
	void setNames();	// private member funciton to assign the names of months to names array

public:
	// constructors
	Date();					
	Date(int, int, int);	// overloaded constructor
	
	// mutators or setters
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);


	// accessers or getters to print the date in 3 formats
	void showDate1();
	void showDate2();
	void showDate3();

};

// default constructor
Date::Date()
{
	setNames();	// we are calling the private member function
}

//overloaded constructors parameter m is month, d is day, y is year
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
	setNames();
}

// private member function setNames assigns the names of the monthe to the array
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

// member function setMonth - mutator
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
	else
	{
		cout << m << " is not a valid value for the month!\n";
		exit(EXIT_FAILURE);
	}
}

// member function setDay - mutator
void Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
		day = d;
	else
	{
		cout << d << " is not a valid value for the day!\n";
		exit(EXIT_FAILURE);
	}
}

// member function setYear - mutator
void Date::setYear(int y)
{
	year = y;
}

// showDate1 function displays MM/DD/YY - accesser
void Date::showDate1()
{
	cout << month << "/" << day << "/" << year << endl;
}

// showdate2 function displays December 25, 2014
void Date::showDate2()
{
	cout << names[month - 1] << " " << day << ", " << year << endl;	
}

// showDate3 function displays 25 DEcember, 2014
void Date::showDate3()
{
	cout << day << " " << names[month - 1] << ", " << year << endl;
}






int main()
{
	//	Your code goes here
	// create a date and initialize it using the overlopaded
	// constructor
	Date today(9, 25, 2019);

	// show the date in form #1
	today.showDate1();

	//// store a new month, day, and a year in the object
	today.setMonth(10);
	today.setDay(26);
	today.setYear(2020);

	// show the date in form # 2
	today.showDate2();

	// show the date in form #3
	today.showDate3();



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
