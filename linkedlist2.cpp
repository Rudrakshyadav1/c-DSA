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

void insertelement(int data,node*&head){
    node * temp= new node(data);
    temp->next = head;
    head = temp;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout << endl;
}

void insertrandomplace(int data,int place,node*& head){
    node * temp= new node(data);
    if(place == 1){
        temp->next = head;
        head = temp;
    } else {
        node *p = head;
        int cnt = 1;
        while(cnt < place-1 && p->next != NULL){
            p = p->next;
            cnt++;
        }
        if(p->next == NULL){
            p->next = temp;
        } else {
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void deleteList(node*& head){
    while(head != NULL){
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    node *head = NULL;
    insertelement(10,head);
    insertelement(20,head);
    insertelement(30,head);
    insertelement(40,head);
    insertelement(50,head);
    print(head);
    insertrandomplace(1000,3,head);
    print(head);
    return 0;
}