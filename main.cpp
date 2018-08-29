#include <iostream>
#include "include/parser.h"

using namespace std;

int main()
{
	Parser *parser = new Parser();
	parser->LoadStopWords("../stopWords.txt");
	parser->ParseFile("../1.txt");
	//cout<<"Hello!"<<endl;
	return 0;
}