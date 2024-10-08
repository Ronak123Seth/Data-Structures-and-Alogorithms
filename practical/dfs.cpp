#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(unordered_map<int,list<int>>& adj,int n,unordered_map<int,bool>& visited,int node){
    visited[node] = true;
    cout << node << " ";

    for(auto nbr : adj[node]){
        if(!visited[nbr])
            dfs(adj,n,visited,nbr);
    }
}
int main(){
    int n,e;
    cout <<"Enter number of edges and vertices "<<endl;
    cin >> e >> n;

    int u,v;
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    for(int i=1; i<=e; i++){
        cout <<"Enter edges " << endl;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(adj,n,visited,i);
    }
}