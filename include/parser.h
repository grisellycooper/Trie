#pragma once
#include <string>
#include <vector>
#include <set>


using namespace std;

class Word
{
	public:
		string word;
		int frecuency;
};

class Parser
{
	private:
		set<string> stopWordsList;		
		string inputFile;
		vector<Word*> wordsList;		
		
	public:
		Parser();
		~Parser();
			
		bool LoadStopWords(string fileName);
		void CleanWordList();
		void ParseFile(string _inputFile);
		bool IsStopWord(string word);
		void PreProcessWord(string &word);
		bool IsMark(char sign);		
		bool TakeOffMark(char &sign);
};