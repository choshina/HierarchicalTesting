#include "Node.h"
#include <cmath>
#include <stdlib.h>

Node::Node()
{
	visit = 0;
	reward = INT_MAX;
}

Node::Node(Node* p, int st)
{
	visit = 0;
	reward = INT_MAX;
//	state = s;
	parent = p;
	stage = p->stage + 1;
//	totalChildrenNum = tcn;
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
	if(children.size() == totalChildrenNum){
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
		double exploitation = 1.0-(*iter->reward/maxV);
		double exploration = sqrt((2.0*log(visit))/(*iter)->visit);
		score = exploitation + scalar*exploration;
		
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
		iter = children.begin();
		return *(iter+r);

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
