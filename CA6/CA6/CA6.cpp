//***********************************
//	Name: Solomon Pattee
//	Date: 10/9/2019
//	FileName: CA6
//	Description: more on classes
//***********************************

#include <iostream>
#include <cstdlib>
#include <string>
#include "Numbers.h"

using namespace std;

int main()
{
	// your code goes here
	int number;

	// display the program description
	cout << "This program translates whole dollar amounts in the range\n"
		<< "0 through 9999 into an English desctription of the number. \n\n";

	// get the input from the user

	cout << "Enter a whole dollar amount: ";
	cin >> number;

	// create a Numbers object
	Numbers n(number);

	//print english description of our number
	n.print();

	cout << endl;

	system("PAUSE");

	return 0;
}