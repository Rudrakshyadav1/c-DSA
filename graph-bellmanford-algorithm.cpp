#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <climits> 
using namespace std;
class graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addadj(int f, int s, int weight){
        adj[f].push_back({s, weight});
    }
    vector<int> shortestdistance(int n, int start){
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        for (int i = 1; i <= n - 1; i++){
            for(auto node : adj){
                int u = node.first;
                for (auto edge : node.second){
                    int v = edge.first;
                    int weight = edge.second;
                    if(dist[u]!= INT_MAX && dist[u]+weight<dist[v]){
                        dist[v]= dist[u] + weight;
                    }
                }
            }
        }
        for (auto node : adj){
            int u = node.first;
            for (auto edge : node.second){
                int v = edge.first;
                int weight = edge.second;
                if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                    cout << "Graph contains negative weight cycle" << endl;
                    return {};
                }
            }
        }
        return dist;
    }
};
int main(){
    graph g;
    int n, e;
    cin >> n >> e;  
    for (int i = 0; i < e; i++){
        int f, s, w;
        cin >> f >> s >> w;  
        g.addadj(f, s, w);    
    }
    int start;
    cin >> start;  
    vector<int> dist = g.shortestdistance(n, start);
    if (!dist.empty()){
        for(int i = 0; i <n; i++){
            if(dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
    }
}
