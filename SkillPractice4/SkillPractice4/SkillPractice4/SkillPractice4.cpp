/******************************
   Solomon Pattee
   10/1/2019
   SkillPractice4.cpp
   This program takes in three test scores 
   and outputs the average
   into the console 
   utilizing a class call and its 
   functions.
*******************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "testScores.h"

using namespace std;

// Global variables

// constants 
const int NUM_TESTS = 3;

// Function declarations

// test objects

int main()
{
	// variables
	int t1, t2, t3;

	// total scores
	int total;

	// test instantiation
	/*testScores test(NUM_TESTS);*/

	// Integers for tests to take in
	cout << "Enter the first test score: " << endl;
	cin >> t1;

	cout << "Enter the second test score: " << endl;
	cin >> t2;
	
	cout << "Enter the third test score: " << endl;
	cin >> t3;

	// test 
	testScores test(t1, t2, t3);

	// outputting the test scores
	total = test.averageOut();

	// formatting
	cout << endl;
	cout << "Here is the Average of the three test scores: " << total;

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
