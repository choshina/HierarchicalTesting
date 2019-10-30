#ifndef SEARCHSPACE_H
#define SEARCHSPACE_H

#include <list>
#include "Range.h"
#include "ContinuousRange.h"
#include "InputVariable.h"
#include "ContinuousInputVariable.h"
using namespace std;

class SearchSpace{
	private:
//		int num;
		list<InputVariable*> variables;
		
	public:
		SearchSpace();
		void addVariable(InputVariable* iv);
		void printVariable();


};

#endif
