//merge sorted linke-list in sorted order
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        cout<<"Element with value "<<this->data<<" is deleted";
    }
     
};
node* solve(node* head, node* head2) {
    node* result = NULL;
    node* current = NULL;
    if (head == NULL) return head2;
    if (head2 == NULL) return head;
    if (head->data <= head2->data) {
        result = head;
        head = head->next;
    } else {
        result = head2;
        head2 = head2->next;
    }

    current = result;

    while (head != NULL && head2 != NULL) {
        if (head->data <= head2->data) {
            current->next = head;
            head = head->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next; 
    }
    if (head != NULL) {
        current->next = head;
        while (current->next != NULL) {
            current = current->next; 
        }
    } else {
        current->next = head2;
        while (current->next != NULL) {
            current = current->next; 
        }
    }

    return result;
}
node* merge(node* head, node* head2) {
    if (head == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head;
    } 
    else if(head->data <head2->data){
        return solve(head, head2);
    }
    else{
        return solve(head2,head);
    }

}
void print(node*head3){
    while(head3 !=  NULL){
        cout<<head3->data<<" ";
    }
}
void insertelementathead(int data,node*&head){
    node*temp=new node(data);
    temp->next=head;
    head=temp;
}
int main(){
    node *head=NULL;
    insertelementathead(10,head);
    insertelementathead(20,head);
    insertelementathead(30,head);
    insertelementathead(30,head);
    node*head2=NULL;
    insertelementathead(0,head2);
    insertelementathead(3,head2);
    insertelementathead(69,head2);
    node* head3 =merge(head,head2);
    print(head3);
}