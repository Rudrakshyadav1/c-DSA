#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <climits>
using namespace std;
class Graph{
public:
    map<int, list<int>> adj;
    vector<bool> isvisited;
    vector<int> low, steps;
    vector<pair<int, int>> ans;
    int time;
    Graph(int n){
        isvisited.resize(n, false);
        low.resize(n, INT_MAX);
        steps.resize(n, 0);
        time = 0;
    }
    void addadj(int f, int s){
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    void bridgefinder(int u, int parent){
        isvisited[u] = true;
        steps[u] = low[u] = ++time;
        for (auto v : adj[u]){
            if (!isvisited[v]){  
                bridgefinder(v, u);
                low[u] = min(low[u], low[v]); 
                if(low[v] > steps[u]){
                    ans.push_back({u, v});
                }
            }
            else if (v != parent){  
                low[u] = min(low[u], steps[v]);  
            }
        }
    }
};
int main() {
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        g.addadj(f, s);
    }
    for (int i = 0; i < n; i++) {
        if (!g.isvisited[i]) {
            g.bridgefinder(i, -1);
        }
    }
    if(g.ans.empty()){
        cout << "No bridges found." << endl;
    }
    else{
        for (auto it : g.ans){
            cout << "[" << it.first << ", " << it.second << "]" << endl;
        }
    }
}
