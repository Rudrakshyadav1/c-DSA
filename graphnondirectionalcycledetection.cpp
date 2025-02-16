#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
class graph {
public:
    unordered_map<int, list<int>> adj;
    void addadj(int f, int s){
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    void bfscycletraversal(int start, unordered_map<int, bool>& isvisited, bool& ans){
        queue<pair<int, int>> tracker; 
        tracker.push({start, -1});
        isvisited[start] = true;
        while (!tracker.empty()){
            int node = tracker.front().first;
            int parent = tracker.front().second;
            tracker.pop();

            for (auto it : adj[node]){
                if (isvisited[it] && it != parent){
                    ans = true;
                    return;
                }
                if (!isvisited[it]){
                    tracker.push({it, node});
                    isvisited[it] = true;
                }
            }
        }
    }
    void dfscycledetection(int start, unordered_map<int, bool>& visited, int parent, bool& ans) {
        visited[start] = true;
        for(auto it : adj[start]){
            if (visited[it] && it != parent){  
                ans = true;
                return;
            }
            if(!visited[it]) {
                dfscycledetection(it, visited, start, ans);
            }
        }
    }
};
int main(){
    graph a;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int f, s;
        cin >> f >> s;
        a.addadj(f, s);
    }
    unordered_map<int, bool>isvisited;
    bool ans_bfs = false;
    for (int i = 1; i <= n; i++){
        if (!isvisited[i]) {
            a.bfscycletraversal(i, isvisited, ans_bfs);
        }
        if (ans_bfs) {
            break;
        }
    }
    if (ans_bfs){
        cout << "Cycle detected by BFS!" << endl;
    }
    else{
        cout << "No cycle detected by BFS!" << endl;
    }
    unordered_map<int, bool> visited;
    bool ans_dfs = false;
    for (int i = 1; i <= n; i++){
        if (!visited[i]) {
            a.dfscycledetection(i, visited, -1, ans_dfs);
        }
        if (ans_dfs){
            cout << "Cycle detected by DFS!" << endl;
            break;
        }
    }
    if (!ans_dfs){
        cout << "No cycle detected by DFS!" << endl;
    }
}
