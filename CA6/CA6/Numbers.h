#pragma once
#include <iostream>
#include <string>
using namespace std;

class Numbers
{

private:
	int number; // to hold a number

public:
	// static arrays to hold words
	static string lessThan20[20];
	static string tens[9];
	static string hundred;
	static string thousand;

	//constructor 
	Numbers(int x) { number = x; }

	// function to print the words for the number
	void print();
};
