#ifndef CONTINUOUSRANGE_H
#define CONTINUOUSRANGE_H

class ContinuousRange:public Range{
	private:
		double lbound;
		double ubound;
	public:
		ContinuousRange();
		void buildRange();

		
};

ContinuousRange::ContinuousRange():
Range()
{}

void ContinuousRange::buildRange(double l, double u)
{
	lbound = l;
	ubound = u;
}

#endif
