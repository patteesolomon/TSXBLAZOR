
// implementation file for the die class
#include <cstdlib>			// for the rand and srand
#include <ctime>			// for the time function
#include "Die.h"
using namespace std;

// constructor accepts an argument for the number of sides of the die
// performed the roll
Die::Die(int numSides)
{
	// get the syastem time
	unsigned seed = time(0);
	// seeds the random number generator
	srand(seed);
	// set tje number of sides
	sides = numSides;
	// perform and initial roll
	roll();
}

// roll function simualtes the rolling ofg the die
void Die::roll()
{
	// constant for the minimum die value
	const int MIN_VALUE = 1;		// min Die Value
	// get random value for the die
	value = (rand() % (sides - MIN_VALUE +1)) + MIN_VALUE;
}

// getSides member function returns the number for this die
int Die::getSides()
{
	return sides;
}

// getValue member function return  the die's value
int Die::getValue()
{
	return value;
}
