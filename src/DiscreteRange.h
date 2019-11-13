#ifndef DISCRETERANGE_H
#define DISCRETERANGE_H
#include <list>
using namespace std;


class DiscreteRange: public Range{

private:
	list<double> elements;

public:
	DiscreteRange(){}
	void addElement(double e){ elements.push_back(e);}

	void buildRange(double l, double u){}
	double getLb(){return 0;}
	double getRb(){return 0;}
	double getLength(){return elements.size();}

	int getType(){return 1;}
	double getOne(){
		int size = elements.size();
		list<double>::iterator iter = elements.begin();
		int j = 0;
		int r =  rand()%size;
		for(;iter!=elements.end();++iter){
			if(j == r){
				return (*iter);	
			}
			j++;
		}
		return 0;
	}
	double getByIndex(int i){
		list<double>::iterator iter = elements.begin();
		int j = 0;
		for(;iter!=elements.end();++iter){
			if(j == i){
				return (*iter);
			}
			j++;
		}
		return 0;
	}
};


#endif
