#ifndef DISCRETERANGE_H
#define DISCRETERANGE_H
#include <list>
using namespace std;


class DiscreteRange: public Range{

private:
	list<double> elements;

public:
	DiscreteRange();
	void addElement(double){ elements.push_back(e);};
	void buildRange(double* es);
	int getType(){return 1;}
	double getOne(){
		size = elements.size();
		list<double>::iterator iter = elements.begin();
		iter+ = (rand() % (size));
		return (*iter);
	}
};


#endif
