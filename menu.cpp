#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

void LoadIndex()
{
    usleep(10000000);
    cout<<"… Loading index done!"<<endl;
    cout<<"---------------------------------------------"<<endl;
}

void MakeSearch(vector<int>& list)
{
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    usleep(1000000);
    
}

int main()
{
    string query;
    vector<int> listIds;
    int block = 0;
    LoadIndex();
    cout <<"Search: ";
    cin >>query;
    MakeSearch(listIds);
    for(int i = 1; i <=5 ; ++i)
    {
        
    }
    
}