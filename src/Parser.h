#ifndef PARSER_H
#define PARSER_H

class Parser{
	private:
		string configfile;
		
	public:
		Parser();
		SearchSpace GetSearchSpace(string cf);
	
};

#endif
