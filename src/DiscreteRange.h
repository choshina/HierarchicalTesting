#ifndef DISCRETERANGE_H
#define DISCRETERANGE_H
#include <list>
using namespace std;


class DiscreteRange: public Range{

private:
	list<double> elements;
public:
	DiscreteRange();
	void addElement(double);
	void buildRange(double* es);
};

DiscreteRange::DiscreteRange()
:Range()
{}

void DiscreteRange::addElement(double e)
{
	elements.push_back(e);
}

#endif
