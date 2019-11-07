#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <list>
using namespace std;


SearchSpace* Parser::getSearchSpace(string cf)
{
	SearchSpace* space;
	ifstream fin(cf);
	string line = "";

//	stringstream ss;
	getline(fin, line);
	int n = atoi(line.c_str());
//	ss<<line;
//	ss>>n;
//	ss.str("");	
	space = new SearchSpace();
	int disNum = 0;
	int conNum = 0;

	for(int i = 0;i < n;i ++)
	{
		getline(fin, line);
		line = line.substr(line.find(':')+1);
			

		if(line == "continuous"){
			
			getline(fin, line);
			string name = line.substr(line.find(':')+1);
			cout<<name<<endl;

			getline(fin, line);
			ContinuousRange* r = new ContinuousRange();
			string lb_str = line.substr(line.find(':')+1, line.find(',')-line.find(':')-1);
		//	ss<<lb_str;
			double lb = atof(lb_str.c_str());
		//	ss>>lb;
		//	ss.str("");

			string ub_str = line.substr(line.find(',')+1);
		//	ss<<ub_str;
			double ub = atof(ub_str.c_str());
		//	ss>>ub;
		//	ss.str("");
			r->buildRange(lb,ub);

			InputVariable* iv_t = new InputVariable(name, r);

			getline(fin, line);
			//list<Range*> par;
			//Range* rrr = new Range();
			//par.push_back(rrr);

			if(line.substr(line.find(':')+1)== "average"){
				getline(fin, line);

			
				int num_par = atoi(line.substr(line.find(':')+1).c_str());
				
				double l_pos = lb;
				double step_size = r->getLength()/num_par;
				for(int j = 0; j < num_par; j++){
					ContinuousRange* rg = new ContinuousRange();
					rg->buildRange(l_pos, l_pos + step_size);
					iv_t->push(rg);
					
					
					l_pos = l_pos + step_size;
				//	cout<<par.size() <<rg->getLength()<<endl;
					//par.push_back(rg);
			//		cout<<"aa"<<par.size()<<endl;
				}
				
			}
			//ss<<par->size();
			//string y;
			//ss>>y;
			
//			InputVariable* iv_t = new InputVariable(name, r, &par);
			//cout<<iv_t->getRange()->getType()<<endl;
			space->addVariable(iv_t);
			conNum++;
		}else{

		}



		

	}
	space->setDisNum(disNum);
	space->setConNum(conNum);

	fin.close();
	return space;


}
