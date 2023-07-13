#include <iostream>
#include <cstdio>
#include <string>
#include "Numbers.h"

// static member variables must be defined outside of the class
string Numbers::lessThan20[20] =
{ "zero", "one" , "two", "three", "four", "five", "six", "seven", "eight",
"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
"seventeen", "eighteen", "nineteen" };

string Numbers::tens[9] =

{ "ten", "twenty", "thirty", "fourty", "fifty", "sixty",
"seventy", "eighty", "ninety" };

string Numbers::hundred = "hundred";

string Numbers::thousand = "thousand";


// print functions prints the english words for the number

void Numbers :: print()
{
	int remainder = number;

	if (remainder < 0 || remainder > 9999)
	{
		cout << "invalid input. ";

	}
	else
	{
		cout << "The English description is: ";	
		if (number == 0)
		{
			cout << " zero";
		}

		// take care of thousands, if any
		int n_thousands = remainder / 1000;
		remainder %= 1000;
		if (n_thousands > 0)
		{
			cout << " " << lessThan20[n_thousands];
			cout << " " << thousand;

		}

		// take care of the hundreds if any

		int n_hundreds = remainder / 100;
		remainder %= 100;
		if (n_hundreds > 0)
		{
			cout << " " << lessThan20[n_hundreds];
			cout << " " << hundred;
		}

		// take care numbers less than a 100

		if (remainder >= 20)
		{
			int n_tens = remainder / 10;
			remainder %= 10;

			if (n_tens > 0)
			
				cout << " " << tens[n_tens - 1];
			
		}
		if (remainder > 0)
		{
			// take care of anything less than 20
			cout << " " << lessThan20[remainder];
		}
	}

	// skip a few lines
	cout << endl << endl;

}