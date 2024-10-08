#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}
void makeSet(vector<int> &parent,vector<int> &rank,int n){
    for(int i=0 ;i<n; i++){
        parent[i] = i;
        rank[i] = -1;
    }
}
int findParent(vector<int> &parent,int node){
    if(parent[node] == node)
        return node;
    return parent[node] = findParent(parent,parent[node]);  //path compression
}
void findUnion(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(parent,u);
    v = findParent(parent,v);
    if(u != v){
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
}
int main(){
    vector<vector<int>> result;
    int n = 5;
    int e = 5;
    vector<vector<int>> edges;
    edges.push_back({0,3,4});
    edges.push_back({3,4,7});
    edges.push_back({0,4,3});
    edges.push_back({0,1,5});
    edges.push_back({1,2,2});
    //creating adjacency list
    // unordered_map<int,pair<int,int>> adj;
    // for(int i=0; i<e; i++){
    //     int u = edges[i][0];
    //     int v = edges[i][1];
    //     int w = edges[i][2];
    //     adj[u].push_back(make_pair(v,w));
    //     adj[v].push_back(make_pair(u,w));
    // }
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    //Minimum spanning Tree total weight
    int minWeight = 0;
    sort(edges.begin(),edges.end(),cmp);
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        u = findParent(parent,u);
        v = findParent(parent,v);
        if(u != v){
            vector<int> ans;
            ans.push_back(u);
            ans.push_back(v);
            ans.push_back(w);
            result.push_back(ans);
            findUnion(u,v,parent,rank);
            minWeight+=w;
        }
    }
    cout << "Minimum weight of the spanning tree " << minWeight << endl;
    for(auto edge : result){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        cout << u << " --> " << v << "[ " << w << "]" << endl;
    }
}