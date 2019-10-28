#ifndef INPUTVARIABLE_H
#define INPUTVARIABLE_H

class InputVariable{

	private:
		string name;
		bool partition_type; //0: average; 1: biased
		Range range;
		Range* partitions;
	public:
		InputVariable(string, bool, Range, Range*);

};

#endif
