#ifndef CONTINUOUSINPUTVARIABLE_H
#define CONTINUOUSINPUTVARIABLE_H
#include <string>

using namespace std;

class ContinuousInputVariable: public InputVariable{
	private:
		
	public:
		ContinuousInputVariable(string, int, Range, Range*);

};

ContinuousInputVariable::ContinuousInputVariable(string n, int t, Range r, Range* p):
InputVariable(n,t,r,p)
{}


#endif
