#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,e;
class graph {
public:
    vector<vector<int>> adj;
    void addadj(int f, int s, int w){
        adj.push_back({f, s, w});
    }
    int findparent(int a, vector<int>& p){
        if (p[a] == a) {
            return a;
        }
        return p[a] = findparent(p[a], p);  
    }
    void maker(vector<int>& parent){
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    void funion(int f, int s, vector<int>& p, vector<int>& d){
        int rootF = findparent(f, p);
        int rootS = findparent(s, p);
        if (rootF != rootS){
            if (d[rootF] > d[rootS]){
                p[rootS] = rootF;  
            }
            else if(d[rootF] < d[rootS]){
                p[rootF] = rootS;
            }
            else{
                p[rootS] = rootF; 
                d[rootF]++;  
            }
        }
    }
    int minimumspanningtree(){
        vector<int> parent(n);
        vector<int> depth(n, 0);
        maker(parent);  
        int ans = 0;
        sort(adj.begin(), adj.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];  
        });
        for (auto it : adj) {
            int first = findparent(it[0], parent);
            int second = findparent(it[1], parent);
            if (first != second) {
                ans += it[2];  
                funion(it[0], it[1], parent, depth);  
            }
        }
        return ans;
    }
};
int main(){
    graph g;
    cin >> n >> e; 
    for (int i = 0; i < e; i++) {
        int f, s, w;
        cin >> f >> s >> w;
        g.addadj(f, s, w);
    }
    cout << g.minimumspanningtree() << endl;

}
