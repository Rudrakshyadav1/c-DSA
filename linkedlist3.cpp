#include <iostream>
using namespace std;
class node {
public:
    node* next;
    int data;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertElementAtHead(int data, node*& head) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int length(node* head) {
    int l = 0;
    while (head != NULL) {
        l++;
        head = head->next;
    }
    return l;
}
node* reverse(node* head, int k) {
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    int count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL) {
        head->next = reverse(next, k);
    }
    return prev;
}
void kthReversal(int k, node*& head) {
    head = reverse(head, k);
}
int main() {
    node* head = NULL;
    insertElementAtHead(20, head);
    insertElementAtHead(30, head);
    insertElementAtHead(40, head);
    insertElementAtHead(80, head);
    insertElementAtHead(90, head);
    insertElementAtHead(1000, head);
    insertElementAtHead(69, head);
    insertElementAtHead(99, head);
    int k;
    cout << "Enter the number in whose group elements to be reversed: ";
    cin >> k;
    cout << "Before kth reversal:->" << endl;
    print(head);
    cout << endl;
    kthReversal(k, head);
    cout << "After kth reversal:->" << endl;
    print(head);
}