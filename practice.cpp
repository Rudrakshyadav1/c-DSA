#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertelement(node *& head,int element){
    node * temp =new node(element);
    temp->next=head;
    head=temp;
}
void print(node * head){
    node * temp =head;
    while(temp->next !=NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<"DONE!!!";

}
int main(){
    node * nod1=new node(10);
    node * head=nod1;
    insertelement(head,10);
    insertelement(head,100);
    insertelement(head,90);
    print(head);

}