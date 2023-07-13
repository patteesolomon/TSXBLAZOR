#pragma once
// specs for the class
#ifndef Surgery_H
#define Surgery_H

class Surgery
{
	// Access specifier private
private:
	// Data members
	 double kneeSurgery = 100.00;
	 double backSurgery = 200.00;
	 double heartSurgery = 300.00;
	 double brainSurgery = 400.00;
	 double eyeballSurgery = 500.00;
	 double no = 0.00;
	 // Access specifier public
public: 
	// Member functions
	Surgery(); // Constructor
	// knee surgery function declaration
	double knee(); 
	// back surgery function declaration
	double back();
	// heart surgery function declaration
	double heart();
	// brain surgery function declaration
	double brain();
	// eyeBall surgery function declaration
	double eyeBall();
	// none surgery function declaration
	double none();
	// surgery charge function declaration
	double surgeryCharge(int);

};
#endif // !Surgery

