#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

int main(){
    int n = 9;
    int e = 13;
    vector<vector<int>> edges;
    edges.push_back({1,0,1});
    edges.push_back({1,2,6});
    edges.push_back({0,2,6});
    edges.push_back({0,3,5});
    edges.push_back({3,4,2});
    edges.push_back({4,2,3});
    edges.push_back({2,5,7});
    edges.push_back({5,6,12});
    edges.push_back({6,4,8});
    edges.push_back({3,7,10});
    edges.push_back({7,6,7});
    edges.push_back({7,8,3});
    edges.push_back({6,8,8});

    // Creating Adjacency List
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,src});
    unordered_map<int,bool> visited;

    int totalWeight = 0;
     while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int node = top.second;
        int weight = top.first;

        if (visited[node]) continue; // Skip if already visited
        visited[node] = true;
        totalWeight += weight; // Accumulate edge weight

        // Explore neighbors
        for (auto nbr : adj[node]) {
            int v = nbr.first;
            int w = nbr.second;
            if (!visited[v]) {
                pq.push({w, v}); // Add to priority queue
            }
        }
     }
    cout << "Total Minimum Weight " << totalWeight << endl;
}