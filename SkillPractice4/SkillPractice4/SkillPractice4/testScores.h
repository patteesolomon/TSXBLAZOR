#pragma once
// specification file for the die class
#ifndef TESTSCORES_H
#define TESTSCORES_H
class testScores
{
private:
	int scores;		// number of scores

public:
	// these are alike prototypes
	testScores(int m);
	testScores(int t1, int t2, int t3);
	int averageOut();
	~testScores();

protected:

};
#endif