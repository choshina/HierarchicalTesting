#ifndef NODE_H
#define NODE_H
#include <list>
#include <limits.h>

class Node{
	private:
		int visit;
		double reward;
//		State* state;

		list<Node*> children;
		Node* parent;

		int stage;

//		int totalChildrenNum;
		Range* range;	

	public:
		Node();

		Node(Node* p);

		void addChild(Node* child);

		void update(double r);

		bool fullyExpanded();
		Node* bestChild(double, double);
//		State* getState();

		bool terminate();
		int getStage();
		
};

#endif
