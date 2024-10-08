#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

void bfs(unordered_map<int,list<int>>& adj,int n,unordered_map<int,bool>& visited,int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        auto top = q.front();
        q.pop();
        cout << top << " ";

        for(auto nbr : adj[top]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
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
            bfs(adj,n,visited,i);
    }
}