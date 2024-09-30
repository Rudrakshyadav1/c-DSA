#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;

    }
    ~node() {
        cout << "Deleted element has value: " << this->data << endl;
    }
};

void insertathead(int data, node*& head) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* solve(node* first, node* second) {
    node dummy(0);
    node* tail = &dummy;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            tail->next = first;
            first = first->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }

    if (first != NULL) {
        tail->next = first;
    } else {
        tail->next = second;
    }

    return dummy.next;
}

node* mergelinkedlist(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data <= head2->data) {
        return solve(head1, head2);
    } else {
        return solve(head2, head1);
    }
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;

    insertathead(60, head1);
    insertathead(50, head1);
    insertathead(40, head1);
    insertathead(30, head1);
    insertathead(20, head1);
    insertathead(10, head1);

    insertathead(54, head2);
    insertathead(34, head2);
    insertathead(20, head2);
    insertathead(15, head2);
    insertathead(15, head2);
    insertathead(5, head2);

    cout << "Linked-list-1:" << endl;
    print(head1);

    cout << "Linked-list-2:" << endl;
    print(head2);

    node* head3 = mergelinkedlist(head1, head2);

    cout << "Merged linked-list sorted:" << endl;
    print(head3);

   
}
