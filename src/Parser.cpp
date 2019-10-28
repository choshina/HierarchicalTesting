#include "Parser.h"
#include <iostream>
#include <fstream>

Parser::Parser()
{
		
}

SearchSpace Parser::GetSearchSpace(string cf)
{
	SearchSpace ss;
	ifstream fin("input.config")
	line = "";

	getline(fin, line);
	int n = atoi(line.c_str());
	ss = new SearchSpace(n);

	for(i = 0;i < n;i ++)
	{
		InputVariable iv_t;
		getline(fin, line);
		line = line.substr();
			
		if(line == "continuous"){
			
			getline(fin, line);
			name = line.substr();

			getline(fin, line);
			Range r = new ContinuousRange();
			r.buildRange();

			getline(fin, line);
			list<Range> par;
			if(line.substr()== "average"){
				Range rg = ;
				par.push_back();
			}
			
			iv_t = new ContinuousInputVariable();
		}else{

			iv_t = new DiscreteInputVariable();
		}


		

	}

	return ss;

	fin.close();

}
