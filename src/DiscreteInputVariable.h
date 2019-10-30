#ifndef DISCRETEINPUTVARIABLE_H
#define DISCRETEINPUTVARIABLE_H

#include <list>

class DiscreteInputVariable: public InputVariable{
	private:
		
	public:
		DiscreteInputVariable(string, Range*, list<Range*>);

};

DiscreteInputVariable::DiscreteInputVariable()
:InputVariable()
{}



#endif
