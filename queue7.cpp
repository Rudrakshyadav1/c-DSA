#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    queue<int>temp;
    queue<int>p;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    p=q;
    cout<<"Queue before interleaving with second half:";
    for(int i=0;i<q.size();i++){
        cout<<p.front()<<" ";
        p.pop();
    }
    cout<<"\n";
    int size= q.size();
    size/=2;
    for(int i=0;i<size;i++){
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<"Queue after interleaving with second half:";
    for(int i=0;i<2*size;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}