//dequeue
#include <iostream>
using namespace std;

class node {
public:
    node* next;
    node* prev;
    int data;

    node(int data) {
        next = nullptr;
        prev = nullptr;
        this->data = data;
    }
};

class Dequeue {
private:
    node* front;
    node* rear;
    int size;
    int currentSize;

public:
    Dequeue(int size) {
        this->size = size;
        front = rear = nullptr;
        currentSize = 0;
    }

    // Check if the queue is full
    bool isfull() {
        return currentSize == size;
    }

    // Check if the queue is empty
    bool isempty() {
        return currentSize == 0;
    }

    // Add element at the front
    void pushforward(int element) {
        if (isfull()) {
            cout << "Cannot insert element. Size limit reached." << endl;
            return;
        }
        node* newNode = new node(element);

        if (isempty()) {
            front = rear = newNode; 
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        currentSize++;
    }
    void pushbackward(int element) {
        if (isfull()) {
            cout << "Cannot insert element. Size limit reached." << endl;
            return;
        }
        node* newNode = new node(element);

        if (isempty()) {
            front = rear = newNode; 
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
    }
    void popforward() {
        if (isempty()) {
            cout << "Queue is empty. Cannot remove element." << endl;
            return;
        }
        cout << front->data << " is deleted." << endl;
        node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        delete temp;
        currentSize--;
    }
    void popbackward() {
        if (isempty()) {
            cout << "Queue is empty. Cannot remove element." << endl;
            return;
        }
        cout << rear->data << " is deleted." << endl;
        node* temp = rear;
        rear = rear->prev;
        if (rear) {
            rear->next = nullptr;
        } else {
            front = nullptr; 
        }
        delete temp;
        currentSize--;
    }

    ~Dequeue() {
        while (!isempty()) {
            popforward(); 
        }
        cout << "Complete dequeue deleted!" << endl;
    }
};

int main() {
    Dequeue dq(5);

    // Test pushforward and pushbackward
    dq.pushforward(10);
    dq.pushbackward(20);
    dq.pushforward(5);
    dq.pushbackward(30);

    // Test popforward and popbackward
    dq.popforward();
    dq.popbackward();

    // Test when the queue is full
    dq.pushforward(1);
    dq.pushforward(2);
    dq.pushforward(3); 

    dq.popforward();
    dq.popbackward();

    return 0;
}
