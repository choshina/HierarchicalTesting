#include "Node.h"
#include <cmath>
#include <stdlib.h>

Node::Node()
{
	visit = 0;
	reward = INT_MAX;
}

Node::Node(Node* p, int s, Range* r, SearchSpace* ss)
{
	visit = 0;
	reward = INT_MAX;
	stage = s;
	parent = p;
//	stage = ->stage + 1;
//	totalChildrenNum = tcn;
	range = r;
	space = ss;
	if(s < ss->getSize()){
		InputVariable* iv = ss->getVariable(stage+1);
		iv->copyPartitions(remainChildrenRange);
	}
}

Node* Node::expand()
{
	int sz = remainChildrenRange.size();
	int chosen = (rand() % (sz));
	list<Range*>::iterator it = remainChildrenRange.begin();
	int j = 0;
	Range* rg;
	for(;it!=remainChildrenRange.end();++it){
		if(j == chosen){
			rg = (*it);
			remainChildrenRange.erase(it);
			break;
		}
		j++;
	}


	Node* child = new Node(this, stage+1, rg , space);
	addChild(child);
	return child;
}

void Node::addChild(Node* child)
{
	children.push_back(child);

}

void Node::update(double r)
{
	reward = reward + r;
	visit ++;
}

bool Node::fullyExpanded()
{
	bool full = false;
	if(remainChildrenRange.size()==0){
		full = true;
	}
	return full;
}


Node* Node::bestChild(double maxV, double scalar)
{
	list<Node*>::iterator iter = children.begin();
	double bestScore = -1;
	list<Node*> bestChildren;
	for(;iter!=children.end();++iter){
		double exploitation = 1.0-(((*iter)->reward)/maxV);
		double exploration = sqrt((2.0*log(visit))/(*iter)->visit);
		double score = exploitation + scalar*exploration;
		
		if(score == bestScore){
			bestChildren.push_back(*iter);
		}
		if(score > bestScore){
			bestChildren.clear();
			bestChildren.push_back(*iter);
			bestScore = score;
		}


	}
	int n = bestChildren.size();
	if(n>1){
		int r = (rand()%(n));
		list<Node*>::iterator iter_t = children.begin();
		for(int t = 0;t<r;t++)
			iter_t++;
		return *(iter_t);

	}else{
		return children.front();
	}
	
}



/*State* Node::getState(){
	return state;
}*/

bool Node::terminate(int ts)
{
	if(stage == ts){
		return true;
	}else{
		return false;
	}
}


int Node::getStage()
{
	return stage;
}

double Node::getReward()
{
	return reward;
}

Node* Node::getParent()
{
	return parent;
}

void Node::visitPP()
{
	visit = visit + 1;
}

void Node::setReward(double r)
{
	reward = r;
}

Range* Node::getRange()
{

	return range;
}


