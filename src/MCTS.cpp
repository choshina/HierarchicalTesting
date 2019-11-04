#include "MCTS.h"
#include "mycmaes.h"


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
	root = new Node(NULL, 0);
	max_fitness = 0;
	falsified = 0;
	totalStage = space->getSize();
}

void MCTS::uctSearch()
{
	for(int i = 0;i < budget_global;i++){
		Node* front = treePolicy(root);
		double rew = defaultPolicy(front);
		if(rew > max_fitness)
		{
			max_fitness = rew;
		}
		if(rew < 0)
		{
			backup(front, front->reward);
			falsified = 1;
			break;
		}
		backup(front, front->reward);

	}
}

Node* MCTS::treePolicy(Node* node)
{
	while(!(node->terminate(totalStage))){
		if(!node->fullyExpanded()){
			return expand(node);
		}else{
			node = bestChild(node);
		}
	}
	return node;
}

Node* MCTS::expand(Node* node)
{
//	cN = getChildNum(node->stage);
	Node* child = new Node(node);
	node->addChild(child);
	return child;
}

Node* MCTS::bestChild(Node* node)
{
//	double bestScore = -1;
	return node->bestChild(max_fitness, scalar);	
}


//int MCTS::getChildNum(int st)
//{
//	InputVariable* iv = space->getVariable(st+1);
//	return iv->getNumPartitions();
//}

double MCTS::defaultPolicy(Node* node)
{
	list<Range*> rgl;
	Node* tmp = node;
	while(tmp->parent!=root){
		rgl.push_back(range);
		tmp = tmp->parent;	
	}
	rgl.reverse();
	while(!node->terminate(totalStage)){
		rgl.push_back(space->getVariableRange(node->stage+1));
		node = node->parent;
	}

	return playout(&rgl);
}

double MCTS::playout(list<Range*>* rgl)
{

	int conNum = space->getConNum();
	int disNum = space->getDisNum();
	double* lb = new double[conNum];
	double* ub = new double[conNum];
	double* fix = new double[disNum];

	list<Range*>::iterator iter = rgl->begin();
	int con_i = 0;
	int dis_i = 0;
	for(;iter!=rgl->end();++iter){
		if((*iter)-> getType() == 0){//continuous
			lb[con_i] = (*iter)->getLb();
			ub[con_i] = (*iter)->getRb();
			con_i ++;
		}else if((*iter)->getType() == 1){//discrete
			fix[dis_i] = (*iter)->getOne();
			dis_i ++;
		} 

	}
	
	mycmaes mc;
	mc.my_fitfun = fitfun;
	double res = call_cmaes(&mc, lb, ub, fix);
	return res;

}

void MCTS::backup(Node* node, double reward)
{
	while(true){
		node->visit = node->visit + 1;
		if(reward < node->reward){
			node->reward = reward;
		}
		if(node->stage == 0){
			break;
		}else{
			node = node->parent;
		}
	}	
}


