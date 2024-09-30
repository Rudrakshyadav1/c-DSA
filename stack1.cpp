#include <iostream> 
using namespace std;
class stack1{
public:
    int top1;
    int top2;
    int size;
    int *arr;
    stack1(int size){
        this->size=size;
        this->top1=-1;
        this->top2=(this->size)+1;
        arr=new int[size];
    }
    ~stack1(){
        delete []arr;
    }
    void push1(int data){
        if(top2-top1-2>0){
            arr[++top1]=data;

        }
        else{
            cout<<"Stack overflow";
        }
    }
    void pop1(){
        if(top1>-1){
            int p=arr[top1];
            top1--;
            cout<<"element deleted:";
            cout<<p;
        }
        else{
            cout<<"stack-empty";
        }
    }
    void push2(int data){
        if(top2-top1-2>0){
            arr[--top2]=data;

        }
        else{
            cout<<"Stack overflow";
        }
    }
    void pop2(){
        if(top2<6){
            int p=arr[top2];
            top2++;
            cout<<"element deleted:";
            cout<<p;
        }
        else{
            cout<<"stack-empty";
        }
    }
    void display(){
        int count=0;
        while(count<size){
            cout<<arr[count]<<" ";
            count++;
        }

    }
};
    
int main(){
    stack1 s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);
    s.push1(60);
    s.push2(100);
    s.push2(120);
    s.push2(130);
    s.push2(90);
    s.display();
    cout<<endl;
    s.pop1();
    cout<<endl;
    s.pop2();
    cout<<endl;
    s.display();

}