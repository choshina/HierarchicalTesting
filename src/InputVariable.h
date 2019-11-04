#ifndef INPUTVARIABLE_H
#define INPUTVARIABLE_H
#include <string>
#include <list>
#include "Range.h"
using namespace std;

class InputVariable{

	private:
		string name;
		Range* range;
		int partition_type; //0: average; 1: biased
		list<Range*>* partitions;
	public:
		InputVariable(string n,  Range* r, list<Range*>* p){
			name = n;
			range = r;
			partitions = p;
		}
		string getName(){
			return name;
		}
		int getNumPartitions(){
			return partitions.size();
		}

};


#endif
