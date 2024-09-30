#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void nextsmallerelement(int a[],vector<int>&ans){
    stack<int>s;
    s.push(-1);
    for(int i=5;i>=0;i--){
        while(a[i]<s.top()){
            s.pop();
        }
        ans[i]=s.top();
        s.push(a[i]);
    }
}
void display(vector<int>ans){
    for(int i=0;i<6;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>ans(6);
    int a[]={100,6,90,91,4,9};
    nextsmallerelement(a,ans);
    display(ans);

}
