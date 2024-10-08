#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
using namespace std;

bool bfs(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,queue<pair<int,int>>& q,vector<int>& color){
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first;
        int c = front.second;
        color[node] = c;

        for(auto nbr : adj[node]){
            if(visited[nbr] && color[nbr] == c)
                return false;
            if(!visited[nbr]){
                visited[nbr] = 1;
                color[nbr] = !color[node];
                q.push({nbr,color[nbr]});
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({2,1});
    edges.push_back({2,3});

    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(4,-1);
    color[0] = 0;
    unordered_map<int,bool> visited;
    queue<pair<int,int>> q;
    q.push({0,0});
    bool flag = bfs(adj,visited,q,color);
    if(flag)
        cout << "It is a bipartite graph." << endl;
    else
        cout << "It is not a bipartite graph." << endl;
}