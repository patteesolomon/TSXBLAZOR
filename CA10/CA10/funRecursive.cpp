// CA10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printFun(int);

//int main()
//{
//	int test = 3;
//	printFun(test);
//	cout << endl;
//
//	system("PAUSE");
//	return 0;
//}

void printFun(int t)
{
	if (t < 1)
		return;
	else
	{
		cout << t << " ";
		printFun(t - 1);
		cout << endl << "This is after recursive call\n";
		return;
	}
}