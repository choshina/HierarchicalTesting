#ifndef CONTINUOUSINPUTVARIABLE_H
#define CONTINUOUSINPUTVARIABLE_H
#include <string>
#include <list>
#include "Range.h"
#include "InputVariable.h"
using namespace std;

class ContinuousInputVariable: public InputVariable{
	private:
		
	public:
		ContinuousInputVariable(string n,  Range* r, list<Range*>* p):InputVariable(n,r,p){}

};



#endif
