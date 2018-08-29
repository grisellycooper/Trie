#include <iostream>
#include "include/parser.h"

using namespace std;

void InsertWords(WordList *wl)
{
	cout<<"Doc Id: "<<wl->docId<<endl;
	cout<<"Words: ";
	for(int i = 0; i<wl->wordList.size(); ++i){
		cout << " " <<wl->wordList[i];
	}
	cout<<endl;
}

int main()
{
	Parser *parser = new Parser();
	WordList *wordlist = new WordList();
	parser->LoadStopWords("../stopWords.txt");	
	for(int i = 1; i<5; ++i)
	{		
		wordlist->docId = i;	
		wordlist->wordList = parser->ParseFile("../Docs/"+to_string(i)+".txt");
		InsertWords(wordlist);
		wordlist->docId = 0;
		wordlist->wordList = {};
	}
	

	return 0;
}