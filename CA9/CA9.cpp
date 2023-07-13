
/******************************
   Name Solomon Pattee
   Date 11/06/2019
   File Name CA9.cpp
   TEMPLATES
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

// template fot the minimum function
template <class T>
T minimum(T number1, T number2)
{
	return (number1 < number2) ? number1 : number2;
}

// template for the maximum function 
template <class T>
T maximum(T number1, T number2)
{
	return (number1 > number2) ? number1 : number2;
}

int main()
{
	// test int arguments
	int num1 = 5;
	int num2 = 3;
	cout << "The minimum of 5,3 is: ";
	cout << minimum(num1, num2) << endl;
	cout << "the maximum of 5,3 is: ";
	cout << maximum(num1, num2) << endl;

	// tests
	double num3 = 5.5;
	double num4 = 3.5;
	cout << "The minimum of 5.5, 3.5 is: ";
	cout << minimum(num3, num4) << endl;
	cout << "The maximum of 5.5, 3.5 is: ";
	cout << maximum(num3, num4) << endl;

	// test with string arguments
	string hello = "hello";
	string hi = "hi";

	cout << "The minimum of \"hello\" and \ \"hi\" is :"; \
		cout << minimum(hello, hi) << endl;
	cout << "The maximum of \"hello\" and \ \"hi\" is :";
	cout << maximum(hello, hi) << endl;

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