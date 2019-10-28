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

	

		iv_t = new InputVariable();

	}

	fin.close();

}
