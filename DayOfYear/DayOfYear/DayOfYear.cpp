// DayOfYear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOfYear.h"

using namespace std;


int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

string DayOfYear::monthName[] = { "January", "February", "March", "April", "May",
"June", "July", "August", "September", "October", "November", "December"};

DayOfYear::DayOfYear()
{

}

DayOfYear::DayOfYear(string month, int d)
{ 
	// if the day of the year is outside the last day of the month 
	// spit out an error
	if (daysAtEndOfMonth[day] < d)
	{
		throw new exception("Cannot go outside the number of days.");
	}

	// Setting the day of the month for the particular month
	// If its a certain day for the month of Jan - Dec

	if (d <= daysAtEndOfMonth[31])
	{
		month = "January";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[59])
	{
		month = "February";
		setDay(d);
	}
	
	if (d <= daysAtEndOfMonth[90])
	{
		month = "March";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[120])
	{
		month = "April";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[151])
	{
		month = "May";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[181])
	{
		month = "June";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[212])
	{
		month = "July";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[243])
	{
		month = "August";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[273])
	{
		month = "September";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[304])
	{
		month = "October";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[334])
	{
		month = "November";
		setDay(d);
	}

	if (d <= daysAtEndOfMonth[365])
	{
		month = "December";
		setDay(d);
	}
	
}

// dayOfYear Print convert and print day of the year
void ::DayOfYear::print()
{
	int month = 0;
	while (daysAtEndOfMonth[month] < day)

		month = (month + 1) % 12;
	if (month == 0)
	
		cout << "January " << day << endl << endl;
	else
	{
		cout << endl << monthName[month] << " "
			<< day - daysAtEndOfMonth[month - 1] 
			<< endl << endl;
	}
}
