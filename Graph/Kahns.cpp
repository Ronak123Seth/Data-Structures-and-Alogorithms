#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

int main(){
    //Create adjacency list
    int n;
    cout << "Enter number of edges "<<endl;
    cin >> n;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({0,3});
    edges.push_back({1,4});
    edges.push_back({2,6});
    edges.push_back({3,5});
    edges.push_back({5,6});
    edges.push_back({4,6});

    unordered_map<int,list<int>> adj;
    for(int i=0;i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //indegree
    int v;
    cout << "Enter number of vertices "<<endl;
    cin >> v;
    vector<int> indegree(v,0);
    for(int i=0; i<n; i++){
        int v = edges[i][1];
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for(auto nbr : adj[front]){
            indegree[nbr]--;
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    //display
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}