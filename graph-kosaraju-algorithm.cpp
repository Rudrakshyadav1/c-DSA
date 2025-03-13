#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Graph{
public:
    vector<bool> isvisited;    
    vector<bool> isvisited2;   
    stack<int> temp;           
    unordered_map<int, list<int>> adj;           
    unordered_map<int, list<int>> adjtranspose;
    Graph(int n){
        isvisited.resize(n, false);
        isvisited2.resize(n, false);
    }
    void addadj(int f, int s){
        adj[f].push_back(s);
    }
    void topological(int start){
        isvisited[start] = true;
        for (auto it : adj[start]){
            if (!isvisited[it]){
                topological(it);
            }
        }
        temp.push(start); 
    }
    void transpose(){
        for (auto it : adj){
            int u = it.first;
            for (auto v : it.second){
                adjtranspose[v].push_back(u); 
            }
        }
    }
    void dfs_scc(int node){
        isvisited2[node] = true;
        cout << node << " "; 
        for (auto it : adjtranspose[node]){
            if (!isvisited2[it]) {
                dfs_scc(it); 
            }
        }
    }
    void scc(){
        for (int i = 0; i < isvisited.size(); i++){
            if (!isvisited[i]){
                topological(i);
            }
        }
        transpose();
        while (!temp.empty()){
            int node = temp.top();
            temp.pop();
            if (!isvisited2[node]){
                cout << "SCC: "; 
                dfs_scc(node); 
                cout << endl;    
            }
        }
    }
};
int main(){
    int n,e;
    cin >> n >> e; 
    Graph g(n);
    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;  
        g.addadj(f, s);  
    }
    g.scc();
}
