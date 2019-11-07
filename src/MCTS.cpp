#include "MCTS.h"
extern "C"{
#include "mycmaes.h"
}
#include <iostream>
using namespace std;
//MCTS::MCTS()
//{
//	root = new Node();
//}

MCTS::MCTS(double scl, int b_g, int b_l, SearchSpace* ss, double (*fit)(const double *, const double*))
{
	scalar = scl;
	budget_global = b_g;
	budget_local = b_l;
	space = ss;
	fitfun = fit;
	root = new Node(NULL, 0, NULL ,space);
	max_fitness = 0;
	falsified = 0;
	totalStage = space->getSize();
}

void MCTS::uctSearch()
{
	for(int i = 0;i < budget_global;i++){
		Node* front = treePolicy(root);
		cout<<front->getRange()->getType()<<endl;
		double rew = defaultPolicy(front);
		if(rew > max_fitness)
		{
			max_fitness = rew;
		}
		if(rew < 0)
		{
			backup(front, front->getReward());
			falsified = 1;
			break;
		}
		backup(front, front->getReward());

	}
}

Node* MCTS::treePolicy(Node* node)
{
	while(!(node->terminate(totalStage))){
		if(!node->fullyExpanded()){
//			return expand(node);
			return node->expand();
		}else{
//			node = bestChild(nod;
			node = node->bestChild(max_fitness, scalar);
		}
	}
	return node;
}

//Node* MCTS::expand(Node* node)
//{
//	cN = getChildNum(node->stage);
	
//	Range* r = 
//	Node* child = new Node(node, node->getStage() + 1);
//	node->addChild(child);
//	return child;
//}/

//Node* MCTS::bestChild(Node* node)
//{
//	double bestScore = -1;
//	return node->bestChild(max_fitness, scalar);	
//}


//int MCTS::getChildNum(int st)
//{
//	InputVariable* iv = space->getVariable(st+1);
//	return iv->getNumPartitions();
//}

double MCTS::defaultPolicy(Node* node)
{
	list<Range*> rgl;
	Node* tmp = node;
	while(tmp!=root){
		rgl.push_back(tmp->getRange());
		tmp = tmp->getParent();	
	}
	rgl.reverse();
	int s = node->getStage();
	while(s!=totalStage){
		rgl.push_back(space->getVariable(s)->getRange());
		s++;
	}
//	cout<<rgl.size()<<endl;
	return playout(rgl);
}

double MCTS::playout(list<Range*>& rgl)
{
//	cout<<space->getVariableRange(1)->getType()<<endl;

	int conNum = space->getConNum();
	int disNum = space->getDisNum();
//	cout<<conNum<<disNum<<endl;
	double* lb = new double[conNum];
	double* ub = new double[conNum];
	double* fix = new double[disNum];

	list<Range*>::iterator iter = rgl.begin();
	int con_i = 0;
	int dis_i = 0;
	for(;iter!=rgl.end();++iter){
		cout<<((*iter))->getType()<<endl;
		if((*iter)-> getType() == 0){//continuous
			lb[con_i] = (*iter)->getLb();
//			cout<<lb[con_i]<<endl;
			ub[con_i] = (*iter)->getRb();
			con_i ++;
		}else if((*iter)->getType() == 1){//discrete
			fix[dis_i] = (*iter)->getOne();
			dis_i ++;
		} 

	}
	
	mycmaes mc;
	mc.my_fitfun = fitfun;
	cout<<lb[0]<<"::"<<ub[0]<<"[["<<budget_local<<endl;
	double res = call_cmaes(&mc, lb, ub, fix, budget_local);
	return res;

}

void MCTS::backup(Node* node, double reward)
{
	while(true){
		node->visitPP();
		if(reward < node->getReward()){
			node->setReward(reward);
		}
		if(node->getStage() == 0){
			break;
		}else{
			node = node->getParent();
		}
	}	
}


