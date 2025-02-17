#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int n, e;
class graph{
public:
    unordered_map<int, vector<int>> adj;
    void addadj(int f, int s){
        adj[f].push_back(s);
    }
    void topologicaldfs(int start, vector<bool>& visited, stack<int>& tracker){
        visited[start] = true;
        for (auto it : adj[start]){
            if (!visited[it]){
                topologicaldfs(it, visited, tracker);
            }
        }
        tracker.push(start);
    }
    void storagecalculator(vector<int>& storage){
        for (auto it : adj) {
            for (auto i : it.second){
                storage[i]++;
            }
        }
    }
    void topologicalbfs(vector<int>& storage, vector<bool>& visited, vector<int>& ans){
        queue<int> temp;
        for (int i = 0; i < n; i++) {
            if (storage[i] == 0 && !visited[i]){
                temp.push(i);
                visited[i] = true;
            }
        }
        while (!temp.empty()){
            int var = temp.front();
            ans.push_back(var);
            temp.pop();
            for (auto it : adj[var]){
                storage[it]--;
                if (storage[it] == 0 && !visited[it]){
                    temp.push(it);
                    visited[it] = true;
                }
            }
        }
    }
};
int main(){
    graph a;
    cin >> n >> e;
    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        a.addadj(f, s);
    }
    vector<int> storage(n, 0);
    a.storagecalculator(storage);
    vector<bool> visited(n, false);
    stack<int> tracker;
    for (int i = 0; i < n; i++){
        if (!visited[i]) {
            a.topologicaldfs(i, visited, tracker);
        }
    }
    cout << "\nDFS-based Topological Sort: ";
    while (!tracker.empty()){
        cout << tracker.top() << " ";
        tracker.pop();
    }
    visited.assign(n, false);  
    vector<int> ans;
    a.topologicalbfs(storage, visited, ans);
    cout << "\nBFS-based Topological Sort: ";
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

}
