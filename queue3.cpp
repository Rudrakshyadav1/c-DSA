#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> ans){
    while (!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
}
void reversalqueue(queue<int>& ans){
    if (ans.empty()){
        return;
    }
    int temp = ans.front();
    ans.pop();
    reversalqueue(ans);
    ans.push(temp);
}
int main(){
    queue<int> ans;
    ans.push(6);
    ans.push(5);
    ans.push(4);
    ans.push(3);
    cout << "Initial queue: ";
    display(ans);
    reversalqueue(ans);
    cout << "Final reversed queue: ";
    display(ans);
}
