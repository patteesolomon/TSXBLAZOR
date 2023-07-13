// DayOfYear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOfYear.h"

using namespace std;

int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

string DayOfYear::monthName[] = { "January", "February", "March", "April", "May",
"June", "July", "August", "September", "October", "November", "December" };


DayOfYear::DayOfYear()
{
	day = getDay();
}

DayOfYear::DayOfYear(string month, int d)
{

	// min and 
	int min = 0;
	// max days allowed
	int max = 30;

	// Setting the day of the month for the particular month
	// If its a certain day for the month of Jan - Dec
	
		if (d == 0)
		{
			DayOfYear d = d++;
		}
		// day validations for the months
		else if (d <= daysAtEndOfMonth[0])
		{
			month = "January";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[1])
		{
			month = "February";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[2])
		{
			month = "March";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[3])
		{
			month = "April";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[4])
		{
			month = "May";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[5])
		{
			month = "June";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[6])
		{
			month = "July";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[7])
		{
			month = "August";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[8])
		{
			month = "September";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[9])
		{
			month = "October";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[10])
		{
			month = "November";
			setDay(d);
		}

		else if (d <= daysAtEndOfMonth[11])
		{
			month = "December";
			setDay(d);
		}

		else if (d == 365)
		{
			DayOfYear g = g++;
		}
	
}

// dayOfYear Print convert and print day of the year
void::DayOfYear::print()
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
//

DayOfYear DayOfYear::operator++(int m)
{
	DayOfYear brandNew;
	brandNew.day = getDay();
	brandNew.day += m++;
	return(brandNew);
}

