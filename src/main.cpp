#include "Range.h"
#include "ContinuousRange.h"
#include "InputVariable.h"
//#include "ContinuousInputVariable.h"
#include "SearchSpace.h"
#include "Parser.h"
#include "MCTS.h"
#include <iostream>
#include <string>

using namespace std;

double fitfun(const double *x,const double* m)
{
	double sum = (x[0]-2)*(x[0]-2) + x[1] + m[0];
	return sum;
}

int main()
{
	Parser p;

	SearchSpace* ss = p.getSearchSpace("input.config");
//	ss->printVariable();
	MCTS m(0.2, 100, 30, ss, &fitfun);
	m.uctSearch();


}
