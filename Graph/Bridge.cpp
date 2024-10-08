#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

void dfs(unordered_map<int,list<int>> &adj,vector<int> &disc,vector<int> &low,
        int parent,int node,unordered_map<int,bool> &visited,
        int &timer,vector<pair<int,int>> &result){
    
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr : adj[node]){
        if(nbr == parent)
            continue;
        if(!visited[nbr]){
            dfs(adj,disc,low,node,nbr,visited,timer,result);
            low[node] = min(low[node],low[nbr]);
            if(low[nbr] > low[node]){
                result.push_back(make_pair(node,nbr));
            }
        }
        else{
            low[node] = min(low[node],disc[nbr]);
        }
    }

}

int main(){
    int n = 5;
    int e = 5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    //Creating adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    int parent = -1;
    unordered_map<int,bool> visited;
    int timer = 0;
    vector<pair<int,int>> result;

    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(adj,disc,low,parent,i,visited,timer,result);
    }
    for(auto i : result)
    {
        int u = i.first;
        int v = i.second;
        cout << u << " -> " << v << endl;
    }
}