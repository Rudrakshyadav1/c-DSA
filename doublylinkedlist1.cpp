#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *prev;
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node(){
        int val=this->data;
        cout<<"element with data:"<<val<<" is deleted sucessfully"<<endl;
    }
};
void print(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
void insertelementhead(int data, node *&head){
    node *temp = new node(data);
    if (head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertelementtail(int data,node*&tail){
    node * temp=new node(data);
    if(tail==NULL){
        tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insertrandomposition(int data,int position,node*&head,node*&tail,int len_){
    position--;
    node * temp=new node(data);
    node * random= head;
    int p=1;
    if(position==0){
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else if(position ==len_){
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    else{
        while(p!=position){
            random=random->next;
            p++;
        }
        temp->next=random->next;
        random->next=temp;
        temp->prev=random;
    }
}
int len(node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void deleteentirelist(node*& head){
    node* temp=head;
    while(temp != NULL){
        node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
}
void deleteparticularnode(node*head,int position){
    node * temp=head;
    int cnt=0;
    while(cnt!=position-1){
        temp=temp->next;
        head=temp->prev;
        cnt++;
    }
    head->next=temp->next;
    temp->prev= NULL;
    temp->next=NULL;
    delete temp;
}
void reversal(node *&head, node *&tail) {
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}
int main(){
    node *node1 = new node(10);
    node *head = node1;
    node * tail=node1;
    int len_=len(head);
    insertelementhead(100, head);
    insertelementhead(55, head);
    insertelementtail(69,tail);
    insertelementhead(120,head);
    insertelementtail(199,tail);
    print(head);
    cout<<endl;
    insertrandomposition(777,4,head,tail,len_);
    insertrandomposition(117,8,head,tail,len_);
    insertrandomposition(111,1,head,tail,len_);
    insertrandomposition(1000,5,head,tail,len_);
    print(head);
    cout<<endl;
    deleteparticularnode(head,3);
    cout<<endl;
    reversal(head,tail);
    print(head);
    cout<<endl;
    deleteentirelist(head);
}
