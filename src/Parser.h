#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Range.h"
#include "ContinuousRange.h"
#include "InputVariable.h"
//#include "ContinuousInputVariable.h"
#include "SearchSpace.h"
using namespace std;

class Parser{
	private:
		string configfile;
		
	public:
		SearchSpace* getSearchSpace(string cf);
	
};

#endif
