#ifndef NODE_H
#define NODE_H
#include <list>
#include <limits.h>
#include "Range.h"
#include "InputVariable.h"
#include "SearchSpace.h"
using namespace std;

class Node{
	private:
		int visit;
		double reward;
//		State* state;

		list<Node*> children;
		list<Range*> remainChildrenRange;
		Node* parent;

		int stage;

//		int totalChildrenNum;
		Range* range;

		SearchSpace* space;

	public:
		Node();

		Node(Node*,  int, Range*, SearchSpace*);
		Node* expand();

		void addChild(Node* child);

		void update(double r);

		bool fullyExpanded();
		Node* bestChild(double, double);
//		State* getState();

		bool terminate(int);
		int getStage();
		double getReward();		
		Node* getParent();
		void visitPP();
		void setReward(double);
		Range* getRange();
};

#endif
