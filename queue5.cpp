//reverse first k element in a queue
#include<iostream>
#include <queue>
#include<stack>
using namespace std;
void display(queue<int>Q){
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    };
    return;
}
void kthreversal(int k,queue<int>&Q){
    stack <int> temp;
    int size=Q.size();
    for(int i=0;i<k;i++){
        int t=Q.front();
        Q.pop();
        temp.push(t);
    }
    while(!temp.empty()){
        int p=temp.top();
        Q.push(p);
        temp.pop();
    }
    for(int i=0;i<size-k;i++){
        int z=Q.front();
        Q.push(z);
        Q.pop();
    }

}
int main(){
    queue<int>Q;
    int k;
    cout<<"enter first k elements to be reversed:";
    cin>>k;

    cout<<"\n";
    Q.push(1);
    Q.push(4);
    Q.push(69);
    Q.push(78);
    Q.push(34);
    Q.push(99);
    cout<<"initial Queue:";
    display(Q);
    cout<<"\n";
    kthreversal(k,Q);
    cout<<"kth reversed queue:";
    display(Q);

}