#include "Range.h"
#include "ContinuousRange.h"
#include "InputVariable.h"
#include "ContinuousInputVariable.h"
#include "SearchSpace.h"
#include "Parser.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Parser p;

	SearchSpace* ss = p.getSearchSpace("input.config");
	ss->printVariable();
	return 0;
}
