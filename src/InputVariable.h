#ifndef INPUTVARIABLE_H
#define INPUTVARIABLE_H
#include <string>
#include <list>
#include "Range.h"
#include <iostream>
using namespace std;

class InputVariable{

	private:
		string name;
		Range* range;
		int partition_type; //0: average; 1: biased
		list<Range*> partitions;
	public:
		InputVariable(string n,  Range* r){
			name = n;
			range = r;
//			partitions = p;
		}
		string getName(){
			return name;
		}
		int getNumPartitions(){
			return partitions.size();
		}
		Range* getRange(){
//			cout<<partitions.size()<<endl;
//			list<Range*>::iterator it = partitions.begin();
//			cout<<(*it)->getType()<<endl;
			return range;
		}
		void push(Range* r){
			partitions.push_back(r);
		}

		void copyPartitions(list<Range*>& l){
			list<Range*>::iterator i1 = partitions.begin();
		//	list<Range*>::iterator i2 = l.begin();
			for(;i1!=partitions.end();++i1){
				l.push_back(*i1);
			}
		}

};


#endif
