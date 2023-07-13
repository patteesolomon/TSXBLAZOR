/******************************
   Name
   Date
   File Name template.cpp
   Description
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables
int z = 0;

// Function declarations
void sign(unsigned long long int);

template <class T> 
T recMulti(T x, T y) // this is broken
{
	if (y != 0) // if need be return
	{
		z += y;
		
		recMulti(x, --y);
	}
	else
	{
		return z;
	}
	//else if(y == 0) // if 0
	//{
	//	return 0;
	//}
	//else if(y < 0) // negative
	//{
	//	z = x + y;
	//	return recMulti(x, --y);
	//
	//}
	//else // irrational
	//{
	//	return x;
	//}
	//if (y < 0)
	//{
	//	return -z;
	//}
}

int main()
{
	//	Your code goes here
	int number; 
	int numberTwo;

	cout << "enter two numbers";
	cin >> number;
	cin >> numberTwo;

	cout << recMulti(number, numberTwo);

	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent.  It will only work on Windows
	// system("PAUSE");

	/*
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
}

void sign(unsigned long long int num) // this was a while loop and now its a recursive function
{
	if (num > 0)
	{
		cout << num << endl;
		cout << "No parking." << endl;
		sign(--num);
	}
	else
	{
		return;
	}
}


