#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(unordered_map<int,list<int>>& adj,stack<int> &s,unordered_map<int,bool>& visited,int node){
    visited[node] = 1;

    for(auto nbr : adj[node]){
        if(!visited[nbr])
            dfs(adj,s,visited,nbr);
    }
    s.push(node);
}
void count(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& vis,int node){
    vis[node] = 1;

    for(auto nbr : adj[node]){
        if(!vis[nbr])
            count(adj,vis,nbr);
    }
}
int main(){
    int n = 5;
    vector<vector<int>> edges;
    edges.push_back({1,0});
    edges.push_back({0,2});
    edges.push_back({2,1});
    edges.push_back({2,3});
    edges.push_back({3,4});
    edges.push_back({4,3});
    
    //Creating adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //Reversing graphs
    unordered_map<int,list<int>> rev;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        rev[v].push_back(u);
    }

    //Topological ordering
    unordered_map<int,bool> visited;
    stack<int> s;
    dfs(adj,s,visited,0);

    //Counting strongly connected components
    int c = 0;
    unordered_map<int,bool> vis;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(!vis[node]){
            count(rev,vis,node);
            ++c;
        }
    }
    //Counting Connected Components
    int r = 0;
    unordered_map<int,bool> v;
    for(int i=0; i<n; i++){
        if(!v[i]){
            count(adj,v,i);
            ++r;
        }
    }

    cout << "Connected Components " << r << endl;
    cout << "Strongly Connect-components " << c << endl;
}