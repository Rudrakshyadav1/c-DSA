#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
class Graph{
public:
    unordered_map<int, list<pair<int, int>>> adj;  
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<bool> isVisited; 
    Graph(int n){
        isVisited.resize(n, false);  
    }
    void addEdge(int f, int s, int w){
        adj[f].push_back({s, w});
        adj[s].push_back({f, w});
    }
    int minWeight(int n){
        pq.push({0, 0});  
        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second;
            if(isVisited[node]) continue;
            isVisited[node] = true;
            ans+=weight;
            for(auto adjNode:adj[node]){
                int nextNode=adjNode.first;
                int edgeWeight = adjNode.second;
                if(!isVisited[nextNode]){
                    pq.push({edgeWeight, nextNode});
                }
            }
        }
        return ans;  
    }
};
int main(){
    int n, e;
    cin >> n >> e;  
    Graph g(n);  
    for (int i = 0; i < e; i++){
        int f, s, w;
        cin >> f >> s >> w;  
        g.addEdge(f, s, w);  
    }
    cout << g.minWeight(n) << endl;  
}
