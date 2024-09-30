#include <iostream>
#include <map>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        cout<<"this element is deleted:"<<this->data;
    }
};
void insertathead(int data,node*&head){
    node * temp= new node(data);
    temp->next=head;
    head=temp;
}
void print(node * head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void last(node*&tail,node* head){
    while(head !=NULL){
        tail=head;
        head=head->next;
    };
}
int elementloopdetection(node* head) {
    map<node*, bool> visited;
    while (head != NULL){
        if (visited[head]==true){
            return head->data;
        }
        visited[head] = true;
        head = head->next;
    }
    return INT_MIN;
}
void loopdeletion(node* head){
    map<node*, bool> visited;
    while (head != NULL){
        if (visited[head]==true){
            head->next=NULL;
            return;
        }
        visited[head] = true;
        head = head->next;
    }
    return;
}
bool floydsdetection(node *head) {
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;               
        fast = fast->next->next;          
        if (slow == fast) {              
            return true;    
        }
    }
    return false;             
}

int main(){
    node* head=NULL;
    insertathead(10,head);
    insertathead(20,head);
    insertathead(30,head);
    insertathead(40,head);
    insertathead(50,head);
    insertathead(60,head);
    insertathead(70,head);
    print(head);
    cout<<endl;
    node * tail=NULL;
    last(tail,head);
    tail->next= head->next->next;
    // if(loopdetection(head)){
    //     cout<<"yes the linked-list has a loop";
    // }
    // else{
    //     cout<<"It does not have a loop in linked-list";
    // }
    int t;
    if(floydsdetection(head)){
        cout<<"yes the linked-list has a loop  with starting element"<<elementloopdetection(head);;
    }
    else{
        cout<<"It does not have a loop in linked-list ";
    }
    cout<<endl;
    loopdeletion(head);
    if(floydsdetection(head)){
        cout<<"yes the linked-list has a loop ";
    }
    else{
        cout<<"It does not have a loop in linked-list ";
    }
}