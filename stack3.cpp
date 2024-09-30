#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
    } else {
        int temp = s.top();
        s.pop();
        insertAtBottom(s, element);
        s.push(temp);
    }
}


void print(stack<int> s) {
    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        cout << temp << " ";
    }
    cout << endl;
}


void reversal(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();
    reversal(s);
    insertAtBottom(s, temp);
}

void sortinsert(stack<int>& s, int k) {
    if (s.empty() || (s.top() < k)) {
        s.push(k);
        return;
    }

    int temp = s.top();
    s.pop();
    sortinsert(s, k);
    s.push(temp);
}

 
void sortedstack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();
    sortedstack(s);
    sortinsert(s, temp);
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(69);
    s.push(30);
    s.push(40);
    s.push(0);
    s.push(100);
    s.push(99);

    cout << "Before reversal: ";
    print(s);
    cout << "After reversal" << endl;
    reversal(s);
    print(s);
    cout << "Sorted stack" << endl;
    sortedstack(s);
     print(s);
     
}