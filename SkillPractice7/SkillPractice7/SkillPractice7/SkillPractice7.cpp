/*
//	Name: Solomon Pattee
//	Date: 11/11/2019
//	Filename: SkillPractice7.cpp
//	Description: Absolute value calculator
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

// templates
template <class T>
T absolute(T ab0, T ab1, T ab2, T ab3, T abf)
{
	// absolute calculation
	if (ab0 != 0) // long
	{
		return static_cast<long>(abs(ab0));
	}
	else if (ab1 != 0) // double
	{
		return static_cast<double>(abs(ab1));
	}
	else if (ab2 != 0) // int
	{
		return static_cast<int>(abs(ab2));
	}
	else if (ab3 != 0) // float
	{
		return static_cast<float>(abs(ab3));
	}
	else if (abf != 0)
	{
		return static_cast<int>(abs(abf));
	}
	else
	{
		return abs(ab1);
	}
}

// function templates
int stupidFunct(int);

int main()
{
	// integer for input
	long l = 0;
	double d = 0.0;
	int t = 0;
	float f = 0.0;
	// argument test
	int a = 0;

	char choice;

	// greet the viewer and format the output
	cout << fixed << "\t\t\t" << "=====:: Here is the absolute value calculator for any number ::=====" << endl;
	
	// input the number to convert into an absolute value
	cout << "Input a number: " << endl;

	cout << "Select your data type!" << endl;
	cout << "\t\t" << "l (long), d (double), i (integer), f (float), a (test argument)" << endl;
	cin >> choice;

	

	// select your number type!
	switch (choice)
	{
	case 'l':
		cout << "What is the value of said type?" << endl;
		// long
		cin >> l;
		break;
	case 'd':
		cout << "What is the value of said type?" << endl;
		// double
		cin >> d;
		break;
	case 'i':
		cout << "What is the value of said type?" << endl;
		// integer
		cin >> t;
		break;
	case 'f':
		cout << "What is the value of said type?" << endl;
		// floating point
		cin >> f;
		break;
	case 'a':
		// this is the test argument
		a = -234 + 34;
		break;
	default:
		break;
	}

	// here is the absolute value
	cout << endl;
	cout << "Absolute value of inputted number: " << absolute(static_cast<double>(l), static_cast<double>(d), static_cast<double>(t), static_cast<double>(f), static_cast<double>(stupidFunct(a))) << endl;
}

int stupidFunct(int f)
{
	return f;
}
