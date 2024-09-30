#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~node(){
        cout << "deleted element is: " << this->data;
    }
};
void headinsertion(int data,node*&head){
    node*temp=new node(data);
    temp->next=head;
    head=temp;
}
node* middle(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* reversal(node*& midd){
    node* prev = NULL; 
    node* current = midd;
    node* next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool ispallindrome(node* head){
    node* midd = middle(head);
    node* rmid = reversal(midd);
    node* temp = head;

    while (rmid != NULL){
        if (temp->data != rmid->data){
            return false;
        }
        temp = temp->next;
        rmid = rmid->next;
    }
    return true;
}
void print(node*head){
    while(head !=NULL ){
        cout<<head->data<<" ";
        head=head->next;
    }
}


int main(){
    node*head3=NULL;
    node* head = NULL;
    headinsertion(10, head);
    headinsertion(20, head);
    headinsertion(30, head);
    headinsertion(40, head);
    headinsertion(30, head);
    headinsertion(20, head);
    headinsertion(0, head);
    print(head);
    if (ispallindrome(head)){
        cout << "It is a pallindrome"<<endl;
    } else{
        cout << "Not a pallindrome"<<endl;
    }
    node* head1 = NULL;
    headinsertion(1, head1);
    headinsertion(2, head1);
    headinsertion(3, head1);
    headinsertion(4, head1);
    node* head2 = NULL;
    headinsertion(9, head2);
    headinsertion(7, head2);
    headinsertion(5, head2);
    cout<<endl;

}