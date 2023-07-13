#include "Surgery.h"

// here are all the functions
//Surgery::knee() 
//Surgery::back() 
//Surgery::heart() 
//Surgery::brain() 
//Surgery::eyeBall() 
//Surgery::none() 
using namespace std;

// implementations for all the surgeries

// constructor
Surgery::Surgery()
{

}

// knee surgery
double Surgery::knee()
{
	return kneeSurgery;
}
// Back surgery
double Surgery::back()
{
	return backSurgery;
}
// heart surgery
double Surgery::heart()
{
	return heartSurgery;
}
// brain surgery
double Surgery::brain()
{
	return brainSurgery;
}
// eyeBall surgery
double Surgery::eyeBall()
{
	return eyeballSurgery;
}
// no surgery selected
double Surgery::none()
{
	return no;
}

// return values for the case function in main
double Surgery::surgeryCharge(int choice)
{
	switch (choice)
	{
	case 1:
		return knee();
		break;
	case 2:
		return back();
		break;
	case 3:
		return heart();
		break;
	case 4:
		return brain();
		break;
	case 5:
		return eyeBall();
		break;
	case 6:
		return none();
		break;
	default:
		break;
	}
}