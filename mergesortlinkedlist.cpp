#include<iostream>
using namespace std;
class node{
public:
    node* next;
    int data;
    node(int data){
        this->data=data;
    }
    ~node(){
        cout<<"The deleted element is:"<<this->data<<endl;
    }
};
void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertathead(int data, node*& head){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}
node* findmidof(node* head){
    node* slow = head;
    node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* merge(node* left, node* right){
    node* temp = new node(INT_MIN);
    node* head = temp;
    if (left == NULL){
        return right;
    }
    if (right == NULL){
        return left;
    }
    while (left != NULL && right != NULL){
        if (left->data < right->data){
            temp->next = left;
            temp = temp->next;
            left = left->next;
        } 
        else{
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }
    while (right != NULL){
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }
    return head->next;
}
node* mergesort(node* head){
    if (head->next == NULL || head == NULL) {
        return head;
    }
    node* mid = findmidof(head);
    node* right = mid->next;
    mid->next = NULL; 
    node* left = head;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}
void deleteList(node*&head){
    while (head != NULL) {
        node* next =head->next;
        delete head;
        head = next;
    }
}
int main(){
    node* head = NULL;
    insertathead(10, head);
    insertathead(20, head);
    insertathead(70, head);
    insertathead(70, head);
    insertathead(60, head);
    insertathead(50, head);
    cout << "before sorting->";
    print(head);
    cout << endl;
    cout << "after sorting->";
    head = mergesort(head); 
    print(head);
    deleteList(head); 
}