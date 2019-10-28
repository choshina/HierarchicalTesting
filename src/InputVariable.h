#ifndef INPUTVARIABLE_H
#define INPUTVARIABLE_H
#include <string>
using namespace std;

class InputVariable{

	private:
		string name;
		Range range;
		int partition_type; //0: average; 1: biased
		list<Range> partitions;
	public:
		InputVariable(string, int, Range, Range*);

};

InputVariable::InputVariable(string n, Range r,  Range* p)
{
	name = n;
	range = r;
//	partition_type = t;
	partitions = p;
}

#endif
