/*Graph representation using adjacency lists*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[5];

void addEdge(int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int main()
{
    int numEdges = 7;
    int numNodes = 5;
    int x,y;

    for(int i=0; i<numEdges; ++i){
        cin>>x;
        cin>>y;
        addEdge(x,y);
    }

    for(int i=0; i<numNodes; ++i){
        cout<<i<<"'s adjacent are: ";
        for(int j=0; j<adj[i].size(); ++j){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
