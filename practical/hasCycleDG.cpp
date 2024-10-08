#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

bool dfs(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,int node){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            bool ans = dfs(adj,visited,dfsVisited,nbr);
            if(ans)     return true;
        }         
        else if(dfsVisited[nbr] == true)
            return true;
    }

    dfsVisited[node] = false;

    return false;
}
bool hasCycle(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,int n){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(dfs(adj,visited,dfsVisited,i))   return true;
        }
    }
    return false;
}
int main(){
    int n = 5;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({2,1});
    edges.push_back({1,4});
    edges.push_back({3,2});
    edges.push_back({4,3});

    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    if(hasCycle(adj,visited,dfsVisited,n))
        cout <<"Cycle Exists" << endl;
    else
        cout << "Not" << endl;
}