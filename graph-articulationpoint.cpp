#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<climits> 
using namespace std;
class Graph{
public:
    vector<int>display;
    vector<int>low;
    int curtime;
    vector<int>isvisited;
    unordered_map<int,list<int>> adj;
    Graph(int n){
        display.resize(n, 0);
        low.resize(n, INT_MAX);
        isvisited.resize(n, 0);
        curtime = 0;
    }
    void addadj(int f, int s){
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    void articulationpoint(int start,int parent,vector<int>& ans){
        isvisited[start] = 1;
        display[start] = low[start] = (++curtime);
        int children = 0;
        for(auto it : adj[start]){
            if(!isvisited[it]){
                children++;
                articulationpoint(it, start, ans);
                low[start] = min(low[start],low[it]);
                if(parent == -1 && children>1){
                    ans.push_back(start);
                }
                if(parent != -1 && low[it]>=display[start]){
                    ans.push_back(start);
                }
            }
            else if(it != parent){
                low[start] = min(low[start], display[it]);
            }
        }
    }
};
int main(){
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        g.addadj(f, s);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (g.isvisited[i] == 0){
            g.articulationpoint(i, -1, ans);
        }
    }
    if(ans.empty()){
        cout << -1;
    }
    else{
        for (auto it : ans){
            cout << it << " ";
        }
    }
}
