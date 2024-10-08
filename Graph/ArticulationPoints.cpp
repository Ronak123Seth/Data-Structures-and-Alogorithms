#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void dfs(int &timer,unordered_map<int,list<int>> &adj,vector<int> &disc,
            vector<int> &low,int parent,unordered_map<int,bool> &visited,
            int node,vector<int> &ap){
    if(parent == -1 && adj[node].size() > 1)
        ap.push_back(node);
    visited[node] = true;
    disc[node] = low[node] = timer++;
    //Traversing neighbour of node
    for(auto nbr : adj[node]){
        if(nbr == parent)
            continue;
        if(!visited[nbr]){
            dfs(timer,adj,disc,low,node,visited,nbr,ap);
            low[node] = min(low[node],low[nbr]);
            if(low[nbr] > disc[node] && parent != -1){
                ap.push_back(node);
            }
        }
        else{
            low[node] = min(low[node],disc[nbr]);
        }
    }

}

int main(){
    int v = 5;
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
    int timer = 0;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent = -1;
    unordered_map<int,bool> visited;
    vector<int> ap;

    //For all connect components --> calling dfs
    for(int i=0; i<v; i++){
        if(!visited[i])
            dfs(timer,adj,disc,low,parent,visited,i,ap);
    }
    //Printing all Articulation Points
    for(auto ele : ap){
            cout << ele <<" , ";
    }
    cout << endl;
}