/*Breadth First Search*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[6];

void addEdge(int x, int y){
    adj[x].push_back(y);
}

void BFS(int root){
    queue<int> q;       // create queue
    bool visited[6];    // visited array for nodes (all false)
    visited[root] = true;   //mark root as visited
    q.push(root);      //enqueue root
    while(!q.empty()){      //while queue is not empty
        int x = q.front();  //get the front element
        cout<<x<<" ";
        q.pop();            //dequeue front
        for(auto i : adj[x]){   //all immediate neighbors of front element
            if(!visited[i]){    //if not visited
                visited[i] = true;  //mark that neighbor visited
                q.push(i);      //enqueue it too
            }
        }
    }
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(3, 4);
    addEdge(4, 5);
    int root = 0;
    BFS(root);
    return 0;
}

