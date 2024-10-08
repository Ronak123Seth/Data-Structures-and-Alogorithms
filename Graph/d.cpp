#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void dfs(unordered_map<int,pair<int,int>>& adj,unordered_map<int,bool>& visited
        ,priority_queue<pair<int,int>>& pq,vector<int>& dist){

    while(!pq.empty()){
        auto pair = pq.top();
        pq.pop();
        int node = pair.first;
        int distN = pair.second;
        for(auto nbr : adj[node]){
            int v = nbr.first;
            int w = nbr.second;
            if(distN + w < dist[v]){
                pair<int,int> p = make_pair(v,w);
                for(auto i : pq){
                    if(i == p)
                }
            }
        }

    }

}

int main(){
    int v = 5;
    vector<vector<int>> edges;
    edges.push_back({1,0,5});
    edges.push_back({1,2,7});
    edges.push_back({1,4,6});
    edges.push_back({2,3,3});
    edges.push_back({3,1,4});

    //Creating adjacency list
    unordered_map<int,list<pair<int,int>> adj;
    for(int i=0; i,edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v,w));
    }

    priority_queue<pair<int,int> pq;
    unordered_map<int,bool> visited;
    vector<int> dist(v,INT_MAX);
    int src = 0;
    dist[src] = 0;

    pq.push(make_pair(src,0));
    dfs(adj,visited,pq,dist);
}