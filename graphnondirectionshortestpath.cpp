#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <stack>
#include <vector>
using namespace std;
int n, e;
class Graph{
public:
    unordered_map<int,list<int>> adj;
    void addAdj(int f, int s){
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    void shortestPathBFS(int start, vector<int>& parent){
        vector<bool> visited(n, false);
        queue<int> temp;
        visited[start] = true;
        temp.push(start);
        parent[start] = -1;
        while (!temp.empty()){
            int node = temp.front();
            temp.pop();
            for (auto it : adj[node]){
                if (!visited[it]){
                    parent[it] = node;
                    temp.push(it);
                    visited[it] = true;
                }
            }
        }
    }
};
int main(){
    Graph g;
    cin >> n >> e;
    int start, end;
    cin >> start >> end;
    vector<int> parent(n, -1);
    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        g.addAdj(f, s);
    }
    g.shortestPathBFS(start, parent);
    if (parent[end] == -1){
        cout << "No path found from " << start << " to " << end << endl;
        return 0;
    }
    stack<int> ans;
    ans.push(end);
    int i = parent[end];
    while (i != -1){
        ans.push(i);
        i = parent[i];
    }
    while (!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
}
