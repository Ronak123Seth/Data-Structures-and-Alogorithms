#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>> adj;
        void addEdge(int u,int v,bool direction){
            //creating graph from u -> v
            //direction = 1 -->> directed
            //direction == 0 --> undirected
            adj[u].push_back(v);
            if(!direction)
                adj[v].push_back(u);
            return;
        }
        void bfs(){
            queue<int> q;
            vector<int> ans;
            unordered_map<int,bool> visited;
            q.push(0);
            while(!q.empty()){
                int front = q.front();
                q.pop();
                ans.push_back(front);
                visited[front] = 1;
                
                for(auto neighbour : adj[front]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = 1;
                    }
                }
            }
            for(auto i : ans){
                cout<< i <<",";
            }
            cout<<endl;
        }
        void dfs(){
            
        }
        void print(){
            for(auto i : adj){
                cout << i.first << " -> " ;
                for(auto j : i.second){
                    cout << j <<" ";
                }
                cout << endl;
            }
        }
};
int main(){
    Graph g;
    int n;
    cout << "Enter no. of vertices "<<endl;
    cin >> n;
    int m;
    cout << "Enter number of edges "<<endl;
    cin >> m;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,1);  //undirected graph
    }
    g.print();
    g.bfs();
    return 0;
}