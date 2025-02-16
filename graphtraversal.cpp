#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;
int n, m;
class Graph{
public:
    unordered_map<int, list<int>> adj; 
    
    void addEdge(int f, int s, int direction){
        adj[f].push_back(s);  
        if (direction == 0){  
            adj[s].push_back(f); 
        }
    }
    
    void BFS(int start){
        unordered_map<int, bool> visited;  
        queue<int> q; 
        q.push(start);   
        visited[start] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " "; 
            for(int neighbor: adj[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
    void dfs(int start, unordered_map<int, bool>& visited){
        visited[start] = true;
        cout << start << " "; 
        for(auto it : adj[start]){
            if(!visited[it]){
                dfs(it, visited);
            }
        }
    }
};
int main(){
    cin >> n >> m; 
    Graph first;
    
    for(int i = 0; i < m; i++){
        int f, s, dir;
        cin >> f >> s >> dir;  
        first.addEdge(f, s, dir);  
    }
    int startNode;
    cin >> startNode;  
    cout << "BFS: ";
    first.BFS(startNode);
    cout << "DFS: ";
    unordered_map<int, bool> visited;
    first.dfs(startNode, visited);
    cout << endl;
}
