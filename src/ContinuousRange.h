#ifndef CONTINUOUSRANGE_H
#define CONTINUOUSRANGE_H

#include "Range.h"

class ContinuousRange:public Range{
	private:
		double lbound;
		double ubound;
	public:
		ContinuousRange():Range(){}
		void buildRange(double l, double u){lbound = l;ubound = u;}
		double getLength(){return (ubound-lbound);}
		int  getType(){return 0;}		
		double getLb(){return lbound;}
		double getRb(){return ubound;}
};


#endif
