#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    };  
};
void insertelement(int n, node *& head){
    node *temp= new node(n);
    temp->next=head;
    head=temp;
}
void print(node *& head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node * head = NULL;
    insertelement(10, head);
    insertelement(20, head);
    insertelement(30, head);
    print(head);
    return 0;
}