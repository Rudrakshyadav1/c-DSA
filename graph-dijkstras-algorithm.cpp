#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <unordered_map>
#include <climits>
using namespace std;
int n, m, source;
class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int f, int s, int weight){
        adj[f].push_back({s, weight});
        adj[s].push_back({f, weight});
    }
    void shortestDistance(vector<int>& path){
        path[source] = 0;
        set<pair<int, int>> temp;
        temp.insert({0, source});
        while (!temp.empty()){
            auto it = temp.begin();
            int distance = it->first;
            int node = it->second;
            temp.erase(it);
            for (auto i : adj[node]){
                if (distance + i.second < path[i.first]){
                    auto it = temp.find({path[i.first], i.first});
                    if (it != temp.end()){
                        temp.erase(it);
                    }
                    path[i.first] = distance + i.second;
                    temp.insert({path[i.first], i.first});
                }
            }
        }
    }
};
int main(){
    cin >> n >> m >> source;
    vector<int> path(n, INT_MAX);
    Graph g;
    for (int i = 0; i < m; i++){
        int f, s, weight;
        cin >> f >> s >> weight;
        g.addEdge(f, s, weight);
    }
    g.shortestDistance(path);
    for (int i = 0; i < n; i++){
        cout << i << " -> " << (path[i] == INT_MAX ? "INF" : to_string(path[i])) << endl;
    }
}

