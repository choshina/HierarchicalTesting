#include "SearchSpace.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

SearchSpace::SearchSpace()
{}

void SearchSpace::addVariable(InputVariable* iv)
{
	variables.push_back(iv);
}

void SearchSpace::printVariable()
{
	cout<<"begin"<<endl;
	stringstream ss;
	ss<<variables.size();
	string s;
	ss>>s;
	cout<<s<<endl;

	list<InputVariable*>::iterator i;
	for(i = variables.begin();i!=variables.end();++i){
		cout<<(*i)->getName()<<endl;
	}
}

int SearchSpace::getSize()
{
	return variables.size();
}

int SearchSpace::getConNum()
{
	return conNum;
}

int SearchSpace::getDisNum()
{
	return disNum;
}

Range* SearchSpace::getVariableRange(int s)
{
	list<InputVariable*>::iterator i;
	int j = 0
	for(i = variables.begin();i!=variables.end();++i){
		if(j == s){
			return (*i);
		}
		j++;
	}
}
