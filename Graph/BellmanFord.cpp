//use to detect negative cycle and to find shortest path if there are negative weights.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int v = 5;
    vector<vector<int>> edges;
    edges.push_back({1,0,5});
    edges.push_back({1,2,2});
    edges.push_back({1,4,6});
    edges.push_back({2,3,3});
    edges.push_back({3,1,4});

    vector<int> dist(v,INT_MAX);
    int src = 1;
    dist[src] = 0;

    for(int i=0; i<v-1; i++){
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != INT_MAX && (dist[v] > dist[u] + w)){
                dist[v] = dist[u] + w;
            }
        }
    }
    bool flag = 0;
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[v] > dist[u] + w){
                flag = 1;
            }
        }
    if(flag == 1)
        cout << "Negative Cycle is there" << endl;
    else{
        for(auto i : dist)
            cout << i << " ";
    }
}

