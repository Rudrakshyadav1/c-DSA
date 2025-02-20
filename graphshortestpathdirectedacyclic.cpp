#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <list>
#include <climits>
using namespace std;
int n, e;
class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addAdj(int f, int s, int weight){
        adj[f].push_back({s, weight});
    }
    void dfs(int start, vector<bool>& visited, stack<int>& topological){
        visited[start] = true;
        for (auto& neighbor : adj[start]){
            int dest = neighbor.first;
            if (!visited[dest]){
                dfs(dest, visited, topological);
            }
        }
        topological.push(start);
    }
    void shortestPath(int source, stack<int>& topological){
        vector<int> dist(n, INT_MAX);  
        dist[source] = 0;  
        while (!topological.empty()){
            int node = topological.top();
            topological.pop();
            if(dist[node] != INT_MAX){ 
                for (auto& neighbor : adj[node]){
                    int dest = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[node] + weight < dist[dest]){
                        dist[dest] = dist[node] + weight;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if (dist[i] == INT_MAX){
                cout << "INF ";
            }
            else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }
};
int main(){
    Graph g;
    cin >> n >> e;  
    int source;
    cin >> source; 
    for (int i = 0; i < e; i++){
        int f, s, weight;
        cin >> f >> s >> weight;
        g.addAdj(f, s, weight);  
    }
    stack<int> topological;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            g.dfs(i, visited, topological);
        }
    }
    g.shortestPath(source, topological);
}
