#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void dfs(unordered_map<int, vector<pair<int, int>>>& adj, int src, vector<bool>& mst,
            vector<int>& parent, vector<int>& dist, queue<int> &q) {
        
    mst[src] = true;
    q.push(src);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto nbr : adj[node]) {
            int v = nbr.first;
            int w = nbr.second;

            if (!mst[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = node;
                mst[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 5;
    int e = 5;
    vector<vector<int>> edges;
    edges.push_back({0, 3, 4});
    edges.push_back({3, 4, 7});
    edges.push_back({0, 4, 3});
    edges.push_back({0, 1, 5});
    edges.push_back({1, 2, 2});

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
    
    // Creating necessary DS(vector)
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Simple queue
    queue<int> q;
    
    dfs(adj, src, mst, parent, dist, q);

    cout << "Minimum Spanning Tree (MST) Edges:" << endl;
    for (int i = 1; i < n; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << dist[i] << endl;
    }

    return 0;
}
