/*
Name: Solomon Pattee
Date: 11/20/2019
Filename: SkillPractice8.cpp
Description: This program does multiplication through recursion
*/

#include <iostream>

using namespace std;

template <class T>
T product(T x, T y)
{
	if (y > 1) {
		return(x + (product(y - 1, x)));
	}
	else if ((x == 0) || (y == 0))
	{
		return 0;
	}
	else if (y == 1)
	{
		return x;
	}
	else
	{
		return x;
	}	
}

int main()
{
	int m;
	int d;

	cout << "Input two numbers for multiplication..." << endl;
	cin >> m;
	cin >> d;
	int result = product(m, d);
	cout << result << endl;
	cout << endl;

	cout << endl;
	system("PAUSE");
}

