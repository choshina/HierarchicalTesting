#ifndef SEARCHSPACE_H
#define SEARCHSPACE_H

#include <list>
#include "Range.h"
#include "ContinuousRange.h"
#include "InputVariable.h"
//#include "ContinuousInputVariable.h"
using namespace std;

class SearchSpace{
	private:
//		int num;
		list<InputVariable*> variables;
		int disNum;
		int conNum;
		
	public:
		SearchSpace();
		void addVariable(InputVariable* iv);
		int getSize();
		void printVariable();
		int getConNum();
		int getDisNum();
		InputVariable* getVariable(int s);
		int getVariablePartitionSize(int s);
		void setDisNum(int);
		void setConNum(int);
};

#endif
