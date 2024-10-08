#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool check(unordered_map<int,list<int>>& adj,vector<int>& color,int n,int node){
    queue<int> q;
    q.push(node);
    color[node] = false;

    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(auto nbr : adj[top]){
            if(color[nbr] == -1){
                color[nbr] = !color[top];
                q.push(nbr);
            }
            else{
                if(color[nbr] == color[top])
                    return false;
            }
        }
    }
    return true;
}

bool isBipartite(unordered_map<int,list<int>>& adj,vector<int>& color,int n){
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            bool flag = check(adj,color,n,i);
            if(!flag)   return false;
        }
    }
    return true;
}

int main(){
    int n = 4;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({3,1});
    edges.push_back({2,3});

    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n,-1);   
    if(isBipartite(adj,color,n))    cout << "Bipartite" << endl;
    else    cout << "Not" << endl;
}
