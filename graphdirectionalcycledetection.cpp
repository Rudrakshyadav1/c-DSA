#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
class graph{
public:
    unordered_map<int, list<int>> adj;
    void addadj(int f, int s){
        adj[f].push_back(s);
    }
    void cycledetectiondfs(int start, unordered_map<int, bool>& isvisited,
        unordered_map<int, bool>& dfsvisited, bool& ans){
        isvisited[start] = 1;
        dfsvisited[start] = 1;
        for(auto it : adj[start]){
            if(dfsvisited[it] == 1 && isvisited[it]==1){
                ans = true;
                return;
            }
            if(isvisited[it]==0){
                cycledetectiondfs(it, isvisited, dfsvisited, ans);
            }
            if(ans) return;  
        }
        dfsvisited[start] = 0;
    }
    void cycledetectionbfs(int start, int parent, bool &ans, unordered_map<int, bool>& visited){
        queue<pair<int, int>> tracker;
        visited[start] = 1;
        tracker.push({start, parent});
        while (!tracker.empty()){
            int currentnode = tracker.front().first;
            int currentparent = tracker.front().second;
            tracker.pop();
            for(auto it : adj[currentnode]){  
                if (visited[it] == 1 && it != currentparent){
                    ans = true;
                    return;
                }
                if (visited[it] == 0){
                    visited[it] = 1;
                    tracker.push({it, currentnode});  
                }
            }
        }
    }
};
int main(){
    int n, m;
    cin >> n >> m; 
    graph a;
    for (int i = 0; i < m; i++){
        int f, s;
        cin >> f >> s;
        a.addadj(f, s);
    }
    unordered_map<int, bool> isvisited;
    unordered_map<int, bool> dfsvisited;
    bool ans = false;
    for (int i = 0; i < n; i++){
        if (isvisited[i] != 1){
            a.cycledetectiondfs(i, isvisited, dfsvisited, ans);
        }
        if (ans == true){
            cout << "Cycle detected!!" << endl;
            break;
        }
    }
    if(!ans){
        cout << "Cycle not detected" << endl;
    }
    bool ansbfs=false;
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            a.cycledetectionbfs(i,-1,ansbfs,visited);
        }
        if(ansbfs==true){
            cout<<"Cycle detected!!";
            break;
        }
    }
    if(!ansbfs){
        cout<<"Cycle not-detected!!";
    }
}
