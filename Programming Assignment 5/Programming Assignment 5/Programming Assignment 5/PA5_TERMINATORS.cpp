/******************************
   Name TERMINATORS
   Members Christina, Sao, Solomon, Jeremy, Christion
   Date 11/23/19
   File Name template.cpp
   Description Programming 5
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// global variable
const int SIZE = 6;		// constant to hold numbre of sentences to test

//function prototype
string flipSent(string);					// Function to test parameters to compare
bool palindromeTest(string&, int, int);		// Function to test for Palindrome

int main()
{
	// Function to hold array of strings to test
	string testStrings[SIZE] =
	{ "ABLE WAS I ERE I SAW ELBA",
	  "FOUR SCORE AND SEVEN YEARS AGO",
	  "NOW IS THE TIME FOR ALL GOOD MEN",
	  "DESSERTS I STRESSED",
	  "AKS NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
	  "KAYAK"
	};

	// variables definition
	string testSent;	//the initial sentence as a variable
	string newSent;		//the sentence reversed

	// variables initialization
	int firstLetter = 0;	//beginning of the string
	int lastLetter = string::npos;	//npos --constant usually set to -1 and reads the maximum length of the string

	// output to name what is happening in program to user
	cout << "	   THIS PROGRAM WILL DETECT PALINDROME\n"
		<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	
	// for loop to iterate through the element of the array to test each element
	for (int i = 0; i < SIZE; i++)	//loops through the arrays of the string
	{
		//loops through the number of characters in the sentence
		newSent = flipSent(testStrings[i]);
		cout << "Sentence Number " << i+1 << ": "
			<< testStrings[i] 
			<< (palindromeTest(newSent, firstLetter, lastLetter) ? " is a palindrome." : " is not a palindrome.") 
			<< endl << endl;
	}

	return 0;
}

// flip the sentence
//function that reverses the sentence
string flipSent(string testSent)
{
	string newSent;		//variable for the sentence reverses

	// flip the sentence 
	for (unsigned int c = 0; c < testSent.length(); c++)	//.length=length of the sentence
	{
		if (isalnum(testSent[c]))		//isalnum checks if testSentence[c] are characters
		{
			newSent += testSent[c];
		}

	}
	return newSent;
}

// test palindrome
bool palindromeTest(string& newSent, int firstLetter = 0, int lastLetter = string::npos)
{
	// check for one letter
	//compares the characters using a search on the characters to determine if a palindrome
	if (lastLetter == string::npos)
	{
		lastLetter = (newSent.length() - 1);
	}

	// check whole senetencce
	if (newSent[firstLetter] == newSent[lastLetter])
	{
		if ((firstLetter - lastLetter) == 0)	//subtracts the first and last character to see if they are equal
		{
			return true;
		}
		else if (firstLetter == (lastLetter - 1))
		{
			return true;
		}
		else
		{
			return palindromeTest(newSent, firstLetter + 1, lastLetter - 1);		//the recursion happens here
		}
	}
	// end of sentence
	else
	{
		return false;
	}
}