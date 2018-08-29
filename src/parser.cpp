#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <sstream> 
#include <string>

#include "../include/parser.h"

using namespace std;

Parser::Parser(){}

bool Parser::LoadStopWords(string fileName)
{
    set<string>::iterator it;
    ifstream ifs;
    ifs.open(fileName);	
    //cout<<"Loading..."<<endl;
    if (ifs.is_open()){
        string word;
        while (!ifs.eof()) {
            word = "";
            ifs >> word;
            if(word.compare("") != 0)
                stopWordsList.insert(word);               
        }
        ifs.close();            
	}
    else{
        cout<<"ERROR opening the file" <<endl;
        return false;
    }		
	//cout<<"Total items: " <<stopWordsList.size() <<endl;
    
    /*for (it=stopWordsList.begin(); it!=stopWordsList.end(); ++it)
        cout << ' ' << *it;*/
	return true;
}

void Parser::CleanWordList()
{
    wordsList = {};    
}

void Parser::ParseFile(string _inputFile)
{    
    ifstream ifs;
    ifs.open(_inputFile);	
    if (ifs.is_open()){
        int doc_block;
        string title, word, doc_id;		
		istringstream iss;

        getline(ifs, doc_id);
        getline(ifs, title);

        cout<<"doc_id: "<<doc_id <<endl;
        cout<<"title: "<<title <<endl;        

        while (!ifs.eof()) {            
            ifs >> word;
            PreProcessWord(word);git 
			if (!IsStopWord(word) && !word.empty()) {
			    cout<<" " <<l;
                //Ready for insert
			} 
        }
        cout<<endl;
        ifs.close();            
	}
    else{
        cout<<"ERROR opening the file" <<endl;        
    }	

	ifs.close();
}

bool Parser::IsStopWord(string word){
    return stopWordsList.find(word) != stopWordsList.end();
}

bool Parser::IsMark(char sign) {
	return (sign < 0);
}

bool Parser::TakeOffMark(char &sign) {
	switch (sign) {
	case -95:
		sign = 'a';
		break;
	case -87:
		sign = 'e';
		break;
	case -83:
		sign = 'i';
		break;
	case -77:
		sign = 'o';
		break;
	case -70:
		sign = 'u';
		break;
	case -79:
		sign = 'n';
		break;
	default:
		return false;
	}
	return true;	 
}

void Parser::PreProcessWord(string &word)
{
    //cout<<"word in: "<<word<<endl;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (int i = 0; i < word.length(); ++i) {
		if (IsMark(word[i])) {
			word.erase(i, 1);
			while (i < word.length() && !TakeOffMark(word[i])) {
				word.erase(i, 1);
			}
		} if (i < word.length() && !isalpha(word[i]) && !isdigit(word[i])) {
			word.erase(i, 1);
		}
	}
    //cout<<"word out: "<<word<<endl;	
}

Parser::~Parser()
{    
    //Clean WordList and stopWordList
}