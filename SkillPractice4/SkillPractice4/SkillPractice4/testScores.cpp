// testscores here
#include "testScores.h"

using namespace std;
//
//testScores::testScores(int m)
//{
//	;
//}

testScores::testScores(int t1, int t2, int t3)
{
	scores = (t1 + t2 + t3) / 2;
}

int testScores::averageOut()
{
	return scores;
}

testScores::~testScores()
{
	scores = 0;
}