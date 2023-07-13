#pragma once
#ifndef DayOfYear_H
#define DayOfYear_H

#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class DayOfYear
{
private:
	int day;

public:
	// constructors
	DayOfYear();

	DayOfYear(string month, int);

	//setters getters and mutators
	static int daysAtEndOfMonth[];
	static string monthName[];
	void print();
	void setDay(int day) { this->day = day; }
	
};
#endif