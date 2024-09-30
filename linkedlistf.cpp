#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void inserthead(int data,node *&head){
    node*temp=new node(data);
    temp->next=head;
    head=temp; 
}
node*reversal(node*&head){
    node*current=head;
    node*next=NULL;
    node*prev=NULL;
    while(current !=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void print(node*head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
node*add(node*head1,node*head2){
    node*temp1=reversal(head1);
    node*temp2=reversal(head2);
    node*head3=NULL;
    int carry=0;
    while(temp1 !=NULL || temp2 !=NULL ||carry !=0){
        int sum=0;
        int val1=0;
        if(temp1 !=NULL){
            val1=temp1->data;
        }
        int val2=0;
        if(temp2 !=NULL){
            val2=temp2->data;
        }
        sum=val1+val2+carry;
        int digit=sum%10;
        inserthead(digit,head3);
        carry=sum/10;
        if(temp1 !=NULL){
        temp1=temp1->next;}
        if(temp2!=NULL){
        temp2=temp2->next;}
    }
    return head3;
}
int main(){
    node*head=NULL;
    inserthead(1,head);
    inserthead(9,head);
    inserthead(9,head);
    inserthead(9,head);
    inserthead(8,head);
    inserthead(7,head);
    node*head2=NULL;
    inserthead(5,head2);
    inserthead(7,head2);
    inserthead(6,head2);
    cout<<"First list->";
    print(head);
    cout<<endl;
    cout<<"Second list->";
    print(head2);
    cout<<endl;
    cout<<"Added list->";
    node*result=add(head,head2);
    print(result);
    cout<<endl;
}