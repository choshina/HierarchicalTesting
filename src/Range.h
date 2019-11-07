#ifndef RANGE_H
#define RANGE_H

class Range{
	private:
		
	public:
	 	virtual int getType(){return 10;}
		virtual double getLb(){return 0;}
		virtual double getRb(){return 0;}
		virtual double getOne(){return 0;}
		virtual void buildRange(double, double){}
		virtual double getLength(){return 0;}
};
#endif
