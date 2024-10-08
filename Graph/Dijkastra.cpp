#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<climits>
using namespace std;

int main(){
    int v = 10;
    int e = 24;
    vector<vector<int>> edges = {
        {0, 2, 6}, {0, 3, 7}, {0, 4, 9}, {0, 6, 8}, {0, 7, 6},
        {1, 2, 6}, {1, 3, 7}, {1, 5, 10}, {1, 6, 1}, {1, 7, 4},
        {2, 3, 3}, {2, 6, 10}, {2, 8, 8}, {2, 9, 10},
        {3, 5, 3}, {3, 6, 10}, {3, 7, 5},
        {5, 6, 9}, {5, 7, 7},
        {6, 7, 7}, {6, 8, 8}, {6, 9, 8},
        {7, 9, 1},
        {8, 9, 6}
    };
    //creating adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back({u,w});
    }
    set<pair<int,int>> pq;
    int src = 0;
    vector<int> dist(v,INT_MAX);
    dist[src] = 0;
    pq.insert({0,src});
    while(!pq.empty()){
        auto top = *(pq.begin());
        pq.erase(pq.begin());
        int nodeDist = top.first;
        int node = top.second;
        
        for(auto nbr : adj[node]){
            if(nodeDist + nbr.second < dist[nbr.first]){
                auto record = pq.find(make_pair(dist[nbr.first],nbr.first));
                if (record != pq.end()) {
                    pq.erase(record);
                }

                dist[nbr.first] = nodeDist + nbr.second;
                pq.insert(make_pair(dist[nbr.first],nbr.first));
            }
        }
    }
    //Display
    for(int i=0; i<v; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}


//417,-994,947,,1599