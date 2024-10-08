#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int,int>> > adj;
        void addEdge(int u,int v,int weight){
            adj[u].push_back(make_pair(v,weight));
        }
        void print(){
            for(auto i : adj){
                cout << i.first << " -> ";
                for(auto j : i.second){
                    cout << '[' << j.first << "," << j.second << ']' << ",";
                }
                cout << endl;
            }
        }
        void dfs(unordered_map<int,bool> &visited,int node,stack<int> &topo){
            visited[node] = true;
            for(auto neighbour : adj[node]){
                if(!visited[neighbour.first])
                    dfs(visited,neighbour.first,topo);
            }
            topo.push(node);
        }
        void shortestPath(vector<int> &dist,stack<int> &topo,int src){
            dist[src] = 0;
            while(!topo.empty()){
                int front = topo.top();
                topo.pop();

                if(dist[front] != INT_MAX){
                    for(auto i : adj[front]){
                        if(dist[front] + i.second < dist[i.first])
                            dist[i.first] = dist[front] + i.second;
                    }
                }
            }
        }
};
int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);   
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.print();

    //topological sort
    int n = 6;  //vertices

    stack<int> topo;
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i])
            g.dfs(visited,i,topo);
    }

    vector<int> dist(n);  //to store distance
    int src = 1;
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }
    g.shortestPath(dist,topo,src);
    
    //printing answer
    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout << endl;
}