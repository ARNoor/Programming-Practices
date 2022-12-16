/*Dijkstra's Single Source Shortest Path*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<pair<int, int>> adj[6];

void addEdge(int u, int v, int w){
    adj[u].push_back({v,w});
}

struct compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const{
        return a.second > b.second;
    }
};

void printPath(int *prev, int i, int s){
    if(prev[i] == s){
        cout<<s<<" ";
        return;
    }
    printPath(prev, prev[i], s);
    cout<<prev[i]<<" ";
}

void dijkstra(int s){
    int dist[6];
    int prev[6];
    for(int i=0; i<6; ++i){
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while(!pq.empty()){
        auto f = pq.top();
        pq.pop();
        for(auto i : adj[f.first]){
            if(dist[i.first] > dist[f.first] + i.second){
                dist[i.first] = dist[f.first] + i.second;
                prev[i.first] = f.first;
                pq.push({i.first, dist[i.first]});
            }
        }
    }

    for(int i=1; i<6; ++i){
        printPath(prev, i, s);
        cout<<i<<endl;
    }
}

int main()
{
    addEdge(0, 1, 1);
    addEdge(0, 2, 5);
    addEdge(1, 2, 2);
    addEdge(1, 3, 2);
    addEdge(1, 4, 1);
    addEdge(2, 4, 2);
    addEdge(3, 5, 1);
    addEdge(3, 4, 3);
    addEdge(4, 5, 2);
    int source = 0;
    dijkstra(source);
    return 0;
}
