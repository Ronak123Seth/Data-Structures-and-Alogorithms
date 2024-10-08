#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

bool bfs(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,vector<int>& parent,int par,int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        parent[node] = par;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto nbr : adj[top]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = top;
                }
                else if(visited[nbr] == true && nbr != parent[top])
                    return true;
            }
        }
        return false;
    }
int main(){
    int n = 5;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({1,2});
    edges.push_back({2,4});
    edges.push_back({3,2});

    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    vector<int> parent(n,-1);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = bfs(adj,visited,parent,-1,i);
            if(ans) {
                cout <<"Cycle Exists" << endl;
                return 0;
            }    
        }
    }
        cout << "Not" << endl;
        return 1;
}
