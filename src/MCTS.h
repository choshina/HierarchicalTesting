#ifndef MCTS_H
#define MCTS_H

#include "Node.h"
#include "SearchSpace.h"
#include "Range.h"
#include <list>
using namespace std;

class MCTS{
	private:
		double scalar;
		int budget_global;
		int budget_local;

		SearchSpace* space;
		int totalStage;
		
		Node* root;


		int getChildNum(int);

		double max_fitness;

		int falsified;

		double playout(list<Range*>& rgl);

		double (*fitfun) (const double *, const double*);
	public:
//		MCTS();
		MCTS(double, int, int, SearchSpace*, double (*)(const double*, const double*));
		void uctSearch();
		Node* treePolicy(Node*);
		Node* expand(Node*);
		Node* bestChild(Node*);
		double defaultPolicy(Node*);
		void backup(Node*, double);

};

#endif
