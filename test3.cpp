#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

void loadFile(ifstream& inp, queue<string>& qList);
void SaveList(queue<string>& qList);

int main()
{
    queue<string> queueList; 
    ifstream infile;
    infile.open("Docs/spanishText_305000_310000_.txt");
    
    loadFile(infile, queueList);
    SaveList(queueList);
    while (!queueList.empty())
    {
        cout<<queueList.front()<<endl;
        queueList.pop();
    }

    cout<<endl<<endl;
        
    return 0;
}


void loadFile(ifstream& inp, queue<string>& qList)
{
    string str;
    while(inp)
    {
        getline(inp, str);
        qList.push(str);
    }
}

void SaveList(queue<string>& qList)
{
	ofstream myfile("Docs/out.txt");

	if (myfile.is_open())
	{
		if(myfile.good())
		{
            while (!qList.empty())
            {
                myfile << qList.front()<<endl;
                qList.pop();
            }
            cout<<endl<<endl;
		}
		myfile.close();
	}
	else
	{
		cout << "SaveList - Unable to open file";
	}
}