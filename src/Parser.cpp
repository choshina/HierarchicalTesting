#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;


SearchSpace* Parser::getSearchSpace(string cf)
{
	SearchSpace* space;
	ifstream fin(cf);
	string line = "";

	stringstream ss;
	getline(fin, line);
	int n;
	ss<<line;
	ss>>n;
	ss.str("");	
	space = new SearchSpace();

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
			string lb_str = line.substr(line.find(':')+1, 1);
			ss<<lb_str;
			double lb;
			ss>>lb;
			ss.str("");

			string ub_str = line.substr(line.find(',')+1, 1);
			ss<<ub_str;
			double ub;
			ss>>ub;
			ss.str("");
			r->buildRange(lb,ub);

			getline(fin, line);
			list<Range*>* par;

			if(line.substr(line.find(':')+1)== "average"){
				getline(fin, line);

			
				int num_par;
				ss<<line.substr(line.find(':')+1);
				ss>>num_par;
				ss.str("");
				
				double l_pos = lb;
				double step_size = r->getLength()/num_par;
				for(int j = 0; j < num_par; j++){
					ContinuousRange* rg = new ContinuousRange();
					rg->buildRange(l_pos, step_size);
					l_pos = l_pos + step_size;
					par->push_back(rg);
				}
				
			}
			//ss<<par->size();
			//string y;
			//ss>>y;
			//cout<<y<<"aaa"<<endl;
			
			ContinuousInputVariable* iv_t = new ContinuousInputVariable(name, r, par);
			space->addVariable(iv_t);
		}else{

		}


		

	}

	fin.close();
	return space;


}
