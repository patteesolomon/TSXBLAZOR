/******************************
   Jeremy Laney
   9/25/19
   File Name template.cpp
   pg 815 #18
********************************/

// Headers
//#include"stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Die.h"
using namespace std;

// Global variables



// Function declarations


int main()
{
	//	Your code goes here
	// constsnts
	const int NUM_SIDES = 6;		// nuumber of sides for the dice
	const int WINNING_TOTAL = 21;		// the winning totla

	// variablwees
	int computerTotal = 0;		// the copmputers total initialzed to 0
	int userTotal = 0;			//the users total
	string input;				// to hold the users decision to roll or not

	// create two die objects
	Die die1(NUM_SIDES);
	Die die2(NUM_SIDES);

	//display the introduction
	cout << "Let's play a game of 21!\n";

	// play as long a s a user want to roll the dice and the user
	// total does not exceed 21.
	do
	{
		// does the user want to roll the dice?
		cout << "Would you like to roll the dice?\n";
		cout << "Enter Y for yes or N for no: ";
		getline(cin, input);

		if (input == "Y" || input == "y")
		{
			// roll the dice for computer
			die1.roll();
			die2.roll();

			// increment computers total points
			computerTotal += die1.getValue() + die2.getValue();

			// roll the dice for the user
			die1.roll();
			die2.roll();

			// increment the users total points
			userTotal += die1.getValue() + die2.getValue();

			// display the user's total points
			cout << "\nYou have " << userTotal << " points\n\n";
		}
	} while ((userTotal < WINNING_TOTAL) && (input == "Y" || input == "y"));

	// determine if the user's total is greater than zero before display the total
	if (userTotal > 0)
	{
		// display the totalas
		cout << "\n------------------------------\n";
		cout << "The computer had " << computerTotal << " points.\n";
		cout << "You had " << userTotal << " points.\n";

		// detgermine the winner
		if (userTotal > computerTotal || computerTotal > WINNING_TOTAL)
		{
			// congratulate the winner
			cout << "\nCongrats!! You won!!\n\n";
		}
		else
		{
			// the uer did not win the game
			cout << "\nBetter luck next time!\n";
		}
	}
	// display the game over message
	cout << "---------------\n";
	cout << "\nGame over!\n\n";








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
